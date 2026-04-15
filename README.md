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

## 5. Enlace al Video: 
https://drive.google.com/file/d/1CkPtcGPPwcR8WWXv14l8bz0RDCaw3bH6/view?usp=sharing
https://github.com/AdelaidaRodriguez/sistemas-operativos-shell
## 6. Evidencia de funcionamiento
![Pruebas de la Shell]

<img width="1094" height="618" alt="image" src="https://github.com/user-attachments/assets/535efde2-2e50-4e23-ba93-a2f6e2d17e6a" />


## 7. Manifiesto de Transparencia (IA)
Se utilizó Gemini para la guía en la configuración de Git/GitHub y estructura del informe.


