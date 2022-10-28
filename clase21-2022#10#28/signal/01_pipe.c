#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{

    int rVal;
    char fifoName[] = "my_fifo";
    int fd;

    //-- Creo el nodo fifo --
    rVal = mknod(fifoName, S_IFIFO | 0666, 0);
    if (rVal == -1)
    {
        if (errno != EEXIST)
        {
            printf("Error mknod: %d\n", errno);
            fprintf(stderr, "Error create pipe: %s\n", strerror(errno));
            return (-1);
        }
    }

    //-- Abro la fifo como escritura --
    fd = open(fifoName, O_WRONLY);
    if (fd < 0)
    {
        printf("Error fifo");
        return (-8);
    }

    // -- Escribo el fifo --
    rVal = write(fd, "Hola Mundo", 1);


    char buffer[100];
    
    //-- Abro la fifo como lectura --
    fd = open(fifoName, O_RDONLY);
    if (fd < 0)
    {
        printf("Error fifo");
        return (-8);
    }
    
    fscanf (fd, "%s", buffer);

    fclose (fd);


    return 0;
}