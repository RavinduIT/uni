#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    printf("PARENT (PID: %d)\n", getpid());

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        printf("CHILD 1 (PID: %d, PPID: %d)\n", getpid(), getppid());
        sleep(10); 
        exit(0);
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        printf("CHILD 2 (PID: %d, PPID: %d)\n", getpid(), getppid());
        sleep(10); 
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    printf("PARENT EXITING (PID: %d)\n", getpid());
    return 0;
}
