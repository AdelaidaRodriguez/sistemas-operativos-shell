#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void print_error() {
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
}

char **path_dirs;
int path_count = 0;

void clear_path() {
    for (int i = 0; i < path_count; i++) free(path_dirs[i]);
    free(path_dirs);
    path_count = 0;
}

void execute_cmd(char *cmd_raw) {
    char *args[128];
    int arg_count = 0;
    char *redirect_file = NULL;
    char *out_part = strstr(cmd_raw, ">");
    if (out_part) {
        *out_part = '\0';
        out_part++;
        char *token;
        int files = 0;
        while ((token = strsep(&out_part, " \t\n\r")) != NULL) {
            if (strlen(token) > 0) {
                if (files == 0) redirect_file = token;
                files++;
            }
        }
        if (files != 1) { print_error(); return; }
    }
    char *token;
    while ((token = strsep(&cmd_raw, " \t\n\r")) != NULL) {
        if (strlen(token) > 0) args[arg_count++] = token;
    }
    args[arg_count] = NULL;
    if (arg_count == 0) return;
    if (strcmp(args[0], "exit") == 0) {
        if (arg_count > 1) print_error();
        else exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (arg_count != 2 || chdir(args[1]) != 0) print_error();
    } else if (strcmp(args[0], "path") == 0) {
        clear_path();
        path_count = arg_count - 1;
        path_dirs = malloc(path_count * sizeof(char *));
        for (int i = 1; i < arg_count; i++) path_dirs[i-1] = strdup(args[i]);
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            if (redirect_file) {
                int fd = open(redirect_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd < 0) { print_error(); exit(1); }
                dup2(fd, STDOUT_FILENO);
                dup2(fd, STDERR_FILENO);
                close(fd);
            }
            char full_path[512];
            for (int i = 0; i < path_count; i++) {
                snprintf(full_path, sizeof(full_path), "%s/%s", path_dirs[i], args[0]);
                if (access(full_path, X_OK) == 0) {
                    execv(full_path, args);
                    exit(0);
                }
            }
            print_error();
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *in = stdin;
    path_dirs = malloc(sizeof(char *));
    path_dirs[0] = strdup("/bin");
    path_count = 1;
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (!in) { print_error(); exit(1); }
    } else if (argc > 2) {
        print_error(); exit(1);
    }
    char *line = NULL;
    size_t len = 0;
    while (1) {
        if (argc == 1) { printf("wish> "); fflush(stdout); }
        if (getline(&line, &len, in) == -1) exit(0);
        char *line_ptr = line;
        char *cmd;
        int commands_launched = 0;
        while ((cmd = strsep(&line_ptr, "&")) != NULL) {
            if (strlen(cmd) > 0) {
                execute_cmd(cmd);
                commands_launched++;
            }
        }
        for (int i = 0; i < commands_launched; i++) wait(NULL);
    }
    return 0;
}
