#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int numDone = 0;

static void reapChild(int sig) { /* the handler. sig is unused. */
  waitpid(-1, NULL, 0); /* wait for any one child and reap it */
  numDone++;
}

int main() {
    int kid;
	int kNumChildren = 5;

	signal(SIGCHLD, reapChild); /* register the handler */
    for (kid = 1; kid <= kNumChildren; kid++) {
        pid_t pid = fork(); /* create a child process */

        if (pid == 0) { /* for the child process */
          printf("Child create\n");
		  sleep(5 * (kid+1)); /* sleep for some seconds proportinal to kid */
          printf("Kid %d completes.\n", kid);
          exit(0); /* do not forget to exit! */
        }
	}
	
	/* for the parent process */
	while (numDone < kNumChildren) {
		printf("Parent wakes up: %d\n", numDone);
		sleep(1);
	}

	printf("All finished. Go home.\n");
	return 0;

}
