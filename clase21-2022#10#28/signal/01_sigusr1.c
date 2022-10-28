// kill -SIGUSR1  <pid>
// kill -l
// kill -10 <pid>

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * syntax
 *  typedef void (*sighandler_t)(int);
 *  sighandler_t signal(int signum, sighandler_t handler);
 * 
 * */
void handler(int signal_number)
{
  printf("SIGUSR1 recived!\n");
}

int main()
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = &handler;
  sigaction(SIGUSR1, &sa, NULL);

  pid_t pid;

  pid = getpid();
  printf("pid=%d\n", pid);

  while (1)
    sleep(2);

  return 0;
}
