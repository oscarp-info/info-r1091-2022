#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset

#include "database.h"

int main()
{

    TASK mem_database[DATABASE_SIZE];
    TASK aux = {40, "task 40", 4};
    int idx;

    // printf("sizeof(TASK)=%d\n", sizeof(TASK));
    // printf("sizeof(mem_database)=%d\n", sizeof(mem_database));

    // init database
    memset(mem_database, 0, sizeof(mem_database));

    // create fake database
    fake_database(mem_database);

    // add element
    idx = task_create(mem_database, aux);
    printf("Add element at position...%d\n", idx);

    // list database
    task_list(mem_database);

    // get task
    aux = task_read_by_id(mem_database, 40);
    task_show(aux);

    return 0;
}
