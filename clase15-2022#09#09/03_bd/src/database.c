#include "database.h"

void fake_database(TASK *p)
{
    int i = 0;

    TASK db_fake[3] = {
        {1, "task 1", 1},
        {2, "task 2", 1},
        {3, "task 3", 2}};

    for (i = 0; i < 3; i++)
    {
        p[i] = db_fake[i];
    }
}

void task_list(TASK *p)
{
    while (p->id != 0)
    {
        printf("{%d}\t {%s}\t {%d}\n", p->id, p->task_name, p->task_priority);
        p++;
    }
}

int task_create(TASK *p, TASK t)
{
    int index = 0;
    // position to last element
    // TODO: check max size of database
    while (p->id != 0)
    {
        p++;
        index++;
    }
    *p = t;
    return index;
}

TASK task_read_by_id(TASK *p, int id)
{
    TASK t;
    memset(&t, 0, sizeof(TASK));
    int index = 0;
    while (p->id != 0 && index < DATABASE_SIZE)
    {
        if (p->id == id)
        {
            t = *p;
            return t;
        }
        p++;
        index++;
    }
    return t;
}

void task_show(TASK t)
{
    printf("\n\n");
    printf("Task\n");
    printf("{%d}\t {%s}\t {%d}\n", t.id, t.task_name, t.task_priority);
}