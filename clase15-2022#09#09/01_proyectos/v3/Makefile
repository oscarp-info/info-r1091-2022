# mi primer Makefile
#reglas
#objetivo: dependencias
#	comando

# compilacion separada
# gcc -c -I include src\util.c
# gcc -c -I include src\main.c
# gcc -o app main.o util.o



CC=gcc
CFLAGS=-Wall -I $(INC_DIR)
INC_DIR= include
SRC_DIR= src
BIN_DIR= bin

all: mi_programa

mi_programa:main.o util.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)\mi_programa main.o util.o

main.o: $(SRC_DIR)\main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)\main.c

util.o:src\util.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)\util.c

clean:
	rm -f *.o
	rm -f mi_programa

run:
	$(BIN_DIR)\mi_programa
