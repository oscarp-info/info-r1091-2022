#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t child_pid;

  printf("the main program process id is %d\n", (int)getpid());

  /*
   * fork - create a new process
   *  return 0 to the child process and shall return the process ID of the child process 
   *  to the parent process
   * 
   * */
  child_pid = fork();

  if (child_pid != 0)
  {
    printf("parent:: this is the parent process, me %d\n", (int)getpid());
    printf("parent:: this is the parent process, my parent %d\n", (int)getppid());
    printf("parent:: this is the parent process, my child %d\n", (int)child_pid);
  }
  else
  {
    printf("child:: this is the child process, me %d\n", (int)getpid());
    printf("child:: this is the child process, my parent %d\n", (int)getppid());
  }
  return 0;
}
