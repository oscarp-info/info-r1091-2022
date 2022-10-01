# Tipos de archivos:
	- texto (texto plano *ASCII), se pueden ver/editar con cualquier editor de texto
	- binario (dump del contenido de las variables tal estan en la memoria)

# Tipos de streams conocidos:
    stdin(teclado), stdout(pantalla), stderror(pantalla)
    se pueden abrir/cerrar/cambiar

# Funciones (o APIS):
    - alto nivel (libc)                 => FILE *, fopen, fclose, fwrite, fread .....
    - bajo nivel o system calls(kernel) => open, close, read, write, .... (streams)

    == en linux "todo" es un "stream" ==
        drivers -> system calls , otras a las mas comunes: fcntl, ioctl

## Alto Nivel

## Funciones "texto"

fopen fclose
fprintf fscanf
fgetc fgets
fputc fputs
fread y fwrite (en general no se utilizan para texto)
    
## Funciones "binarios"
        
fopen fclose
fread y fwrite
fseek
ftell (devuelve la posicion actual)
    * ejemplo para conocer el  tamaño de archivo
```code
fseek( fichero, 0L, SEEK_END );
final = ftell( fichero );
```

