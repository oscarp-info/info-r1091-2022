#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static void handleSIGSEGV(int sig) {
    printf("Oops, super sorry, a segfault occurs.\n");
    exit(0); /* Exit the process, otherwise it keeps running into
                the segfault error each time the process resumes */
}

int main() {
    signal(SIGSEGV, handleSIGSEGV); /* register a custom handler */
    *(int *)NULL = 1; /* cause a segmentation fault */

    /* the process can never reach here */
    return 0;
}
