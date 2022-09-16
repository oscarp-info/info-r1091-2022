// punteros a estructuras
// precedencia de operadores

#include <stdio.h>

struct st_data
{
    char x;
    char y;
    char z;
};

int main(void)
{

    struct st_data s = {'X', 'Y', 'Z'};
    struct st_data *p;

    p = &s;

    printf("(*p).y: %c\n", (*p).y);
    printf("p->y: %c\n", p->y);

    // error: request for member 'y' in something not a structure or union
    // es necesario el parentesis porque el operador . tiene mayor precedencia
    // que el operador *
    printf("*p.y: %c\n", *p.y);

    return 0;
}
