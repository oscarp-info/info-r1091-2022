gcc -c -I include src\util.c
gcc -c -I include src\main.c
gcc -o app main.o util.o