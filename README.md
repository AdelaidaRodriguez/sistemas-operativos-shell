# Laboratorio de Sistemas Operativos - Práctica No. 2: Shell Wish

## 1. Integrantes
* **Nombre:** Adelaida Rodríguez
* **Correo:** adelaida.rodriguez@udea.edu.co
* **Cédula:** 1.033.377.815

## 2. Documentación de Funciones
* `main()`: Maneja el bucle principal y los modos interactivo/batch.
* `separaItems()`: Parsea la entrada y separa los comandos.
* `ejecutar_comando()`: Usa `fork()` y `execv()` para ejecutar procesos.
* `built-ins`: Implementación de `exit`, `cd` y `path`.

## 3. Problemas Presentados y Soluciones
* **Problema:** Manejo de la variable de entorno `path`.
* **Solución:** Se creó una estructura para almacenar múltiples rutas de búsqueda.
* **Problema:** Redirección con `>`.
* **Solución:** Uso de `dup2()` para redirigir la salida estándar a un archivo.

## 4. Pruebas Realizadas
* Comandos básicos (`ls`, `pwd`, `whoami`).
* Redirección a archivos de texto.
* Ejecución paralela con el operador `&`.

## 5. Enlace al Video (Sustentación 10 min)


## 6. Manifiesto de Transparencia (IA)
Se utilizó Gemini para la guía en la configuración de Git/GitHub y estructura del informe.


