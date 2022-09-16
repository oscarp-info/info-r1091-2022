#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset

#define DATABASE_SIZE 100
#define STR_NAME_LEN 30

// modelo de datos (schema)
struct task
{
    int id;
    char task_name[STR_NAME_LEN];
    int task_priority;
};

typedef struct task TASK;

void fake_database(TASK *);
void task_list(TASK *);
int task_create(TASK *, TASK);
TASK task_read_by_id(TASK *p, int id);
void task_show(TASK t);
