#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
  pid_t child_pid;

  child_pid = fork ();
  if (child_pid > 0) {
      sleep (60);						// parent
  }
  else {
      exit (0);							// child. Exit immediately.
  }
  return 0;
}
