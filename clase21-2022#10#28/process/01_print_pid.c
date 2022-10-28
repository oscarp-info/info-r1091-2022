#include <stdio.h>

// archivo de cabecera para las funciones que permiten trabajar con procesos
#include <unistd.h>

// archivo de cabecera para pid_t (typedef)
#include <sys/types.h>

// test:
//  ejecutarlo varios veces
//    cambia el pid? porque?
//    cambia el ppid? porque? cual es el proceso padre?

int main()
{

  pid_t pid;
  pid_t ppid;

  pid = getpid();
  ppid = getppid();

  printf("The process id is %d\n", pid);
  printf("The parent process id is %d\n", ppid);

  while (1)
    // la funcion sleep como funciona?
    sleep(2);

  return 0;
}
