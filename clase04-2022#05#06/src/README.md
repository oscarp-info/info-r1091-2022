# Clase #4

## Caracteres

- Variables tipo 'char'
- Presentación del codigo ASCII
- Como se guardan en memoria los caracteres. Rol de printf y scanf
- Comparacion de caractares. Como verificar si dos variables son iguales
- Overflow de una variable de tipo caracter. Primer concepto del tamaño de una variable
- Operador sizeof
- Necesidad de 'for' => next, para imprimir todo el codigo ASCII

## Estructuras de repetición

- Estructura for / while / do while
- Casos de usos para utilizar alguna de las 3 (for, while, do while)

## Operadores Logicos

- Los operadores logicos y su combinacion con los operadores relacionales
para generar expresiones ( condiciones )

Pregunta:

	if ( 0 ) es VERDADERO?
	if ( 100 ) es VERDADERO?
	if ( -100 ) es VERDADERO?


 # switch

Estructura de seleccion y se realizo la comparacion con if else

Pregunta:

	float x = 10;
	switch (c) {
		// ...
	}

	es valido?

## scanf

AYUDA:

	printf("Continuar S/N: ");

	scanf(" %c", &sn);

*** para poder limpiar el buffer de stdin

void vaciar_buffer_teclado(void){
    while(getchar()!='\n');
}

