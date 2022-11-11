# 1

Implementar un programa en C que calcule el factorial de los numeros que se le pasan como argumentos desde la linea de comandos. El programa creara tantos hilos como argumentos se introduzcan y cada uno de los hilos recibira uno de esos argumentos y calculara su factorial. 
No importa que se mezcle la salida que imprimen los hilos.

Un ejemplo de la ejecucion del programa podria ser la siguiente:

```console
$ factorial 3 6 4 1 0
Factorial de 1: 1
Factorial de 0: 1
Factorial de 4: 24
Factorial de 6: 720
Factorial de 3: 6
```

# 2

Modifica el programa anterior para que no se mezclen las impresiones de los diferentes hilos. 

# 3

Implementar un programa que calcule una secuencia de potencias de 2. El programa creara tantos hilos como se especifique en su unico argumento. Y cada hilo calculara la potencia de 2 de un numero que se le pasa como argumento. El primer hilo recibira 0 como argumento y calculara 2^0. El segundo hilo, 2^1
El tercero, 2^2 y asi sucesivamente. 
El hilo principal mostrara por pantalla el resultado calculado por cada hilo subordinado.

```console
$ pot2 5
2 ˆ 0: 1
2 ˆ 1: 2
2 ˆ 2: 4
2 ˆ 3: 8
2 ˆ 4: 16
```

# 4

Implementar un programa utilizando thread que liste un directorio, cuyo path se pasa por la linea de comandos, por cada archivo encontrado, que se supone que son todos archivos de texto, se tendra que:

    *  eliminar todos los espacios duplicados en cada archivo de texto
    *  luego moverlo a un directorio en path/output. Este directorio podra o no existir. En caso de no existir se debera crear
    *  al finalizar, mostrar por pantalla un resumen indicando:
       *  cantidad de archivos movidos
       *  cantidad de espacios duplicados eliminados por cada uno de los archivos

# 5

Modificar el programa anterior de manera que no finalice el thread main, salvo con ctrl-c. Cada vez que se agregue un archivo nuevo al directorio, debera procesarse segun el ejercicio anterior. Analice la necesidad o no de que los threas sean joinabled o detached.

















