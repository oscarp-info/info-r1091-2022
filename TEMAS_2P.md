### SISTEMAS DE NUMERACIÓN Y REPRESENTACIÓN NUMÉRICA

Aritmética Binaria Introducción. 
Los sistemas de numeración y su evolución histórica. 
Sistemas de numeración decimal, binario, octal y hexadecimal. 
Pasajes entre sistemas de números enteros y positivos. 
Representación de Números signados: Convenio de signo y magnitud. 
Convenio de complemento a uno. 
Convenio de complemento a dos. 
Operaciones de adición y de sustracción utilizando el convenio de complemento a dos. 
Representación de números fraccionarios. Punto flotante. 
Precisión y truncado. Formato IEEE 754. 
Representación de caracteres: Binario Codificado Decimal (BCD), ASCII.

### ESTRUCTURAS Y UNIONES

Definición de estructura. 
Acceso a los miembros de una estructura. 
Punteros a estructuras. 
Funciones con Estructuras. 
Estructuras autoreferenciadas. 
Definición de Unión. Acceso a los miembros de una unión. Funciones con Uniones.

### PUNTEROS EN C

Concepto de dirección. 
Aritmética de punteros. 
Inicialización de punteros. 
Punteros a punteros. 
Vector de punteros. 
Relación entre punteros y arreglos. 
Ordenamiento de estructuras utilizando vector de punteros. 
Punteros a función. 
Declaraciones complejas

### MEMORIA DINAMICA

Inicialización de punteros y reserva de memoria: malloc y free. 

### OPERADORES A NIVEL DE BIT Y CAMPOS DE BIT
Operadores lógicos, Operadores de desplazamiento. 
Campos de bit. Definición. Acceso a los miembros de un campo de bits 
Campos de bit vs. Operadores a nivel de bits. 
Uniones y campos de bit.

### STREAMS

Funciones del kernel - Archivos. 
Concepto de Flujo de datos (streams). 
Tipos de stream conocidos: stdin, stdout, stderr. 
Clase de nodo más común: el archivo. 
Funciones del kernel: File I/O Creación, apertura y cierre de archivos: funciones creat, open, close. 
Concepto y significado de File Descriptor. 
Funciones para lectura y escritura de bajo nivel: read , y write. 
Accesos secuencial función lseek. 
Funciones fcntl e ioctl. 
Concepto “everything is a file”. 
Uso de las funciones de archivos para acceder a dispositivos de E/S (acceso a E/S de alto nivel). 
Espera del dispositivo de E/S. 
Ejemplos de acceso al dispositivo de audio de una PC.
Funciones de la librería estándar de C para el manejo de archivos, concepto de archivos de “texto” y “binario”

### MULTIPROCESAMIENTO: HILOS

Introducción al multiprocesamiento.
Creación de threads, necesidad de la herramienta.
Aplicaciones típicas (espera sincrónica de respuesta, paralelismo para performance, etc.).
Funciones asociadas.
Espera a la finalización de threads y threads detached .
Implicancias de espera a la finalización de threads.
Uso y riesgo de threads detacheados.
Retorno de resultados de threads: Retorno mediante argumentos al thread.
Retorno mediante variables globales.
Retorno mediante finalización del thread.
Creación y destrucción de mutex. Atributos de los mutex.
Su utilización como sincronización entre threads y sus implicancias.
Bloqueo indefinido (deadlock). Concepto de deadlock. Cómo evitarlos.

### IPC: SEÑALES y SOKETS
Concepto de redes.
Intercomunicaciones de procesos residentes en computadores diferentes a través de una red de datos: sockets.
Acceso de lectura y escritura mediante read () write ().
Ejemplos Cliente – Servidor.
Señales

