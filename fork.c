#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork();
    
    if (child1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child1 == 0) {
        printf("CHILD 1\n");
        exit(0);
    } else {
        child2 = fork();

        if (child2 < 0) {
            perror("Fork failed");
            exit(1);
        } else if (child2 == 0) {
            printf("CHILD 2\n");
            exit(0);
        } else {
            printf("PARENT\n");
        }
    }

    wait(NULL);
    wait(NULL);

    return 0;
}