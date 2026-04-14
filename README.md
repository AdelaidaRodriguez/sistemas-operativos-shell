# Laboratorio de Sistemas Operativos - Práctica No. 2: Shell Wish

## 1. Integrante
* **Nombre:** Adelaida Rodríguez
* **Correo:** adelaida.rodriguez@udea.edu.co
* **Documento:** 1.033.377.815

## 2. Documentación de Funciones
* `main()`: Ciclo principal que maneja los modos interactivo y batch.
* `separaItems()`: Encargada de parsear la entrada del usuario y separar comandos por espacios o operadores.
* `ejecutar_comando()`: Utiliza `fork()` y `execv()` para lanzar procesos externos.
* `built-in commands`: Implementación de `exit`, `cd` y `path`.

## 3. Problemas Presentados y Soluciones
* **Problema:** Manejo de múltiples rutas en el comando `path`.
* **Solución:** Se implementó un arreglo dinámico para almacenar las rutas válidas y buscarlas antes de cada ejecución.
* **Problema:** Redirección de salida con `>`.
* **Solución:** Se utilizó `open()` y `dup2()` para desviar el flujo de salida estándar hacia el archivo especificado.

## 4. Pruebas Realizadas
* Ejecución de comandos simples: `ls`, `cat`, `whoami`.
* Cambio de directorios con `cd` y verificación con `pwd`.
* Pruebas de error: Comandos inexistentes y falta de argumentos en comandos integrados.
* Modo Batch: Ejecución del shell pasando un archivo con comandos.

## 5. Enlace al Video (10 minutos)
[PEGA AQUÍ EL LINK DE TU VIDEO DE YOUTUBE O DRIVE]


## 6. Manifiesto de Transparencia (IA Generativa)
En este proyecto se utilizó IA generativa (Gemini) para:
* Explicación de errores de sintaxis en lenguaje C.
* Guía paso a paso para la configuración y carga del repositorio en GitHub.
  

---
