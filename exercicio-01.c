#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int myVariable = 100;

    printf("[%d] hello!\n", getpid());
    printf("[%d] myVariable before fork is %d\n", getpid(), myVariable);

    int pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("    [%d] hello, my father is %d\n", getpid(), getppid());
        printf("    [%d] myVariable is %d\n", getpid(), myVariable);
        printf("    [%d] changing the value of myVariable to 200\n", getpid());
        myVariable = 200;
        printf("    [%d] now myVariable is %d\n", getpid(), myVariable);
    }
    else {
        printf("[%d] hello, my father is %d, and my son is %d\n", getpid(), getppid(), pid);
        printf("[%d] myVariable from parent after fork is %d\n", getpid(), myVariable);
        printf("[%d] changing the value of myVariable to 300\n", getpid());
        myVariable = 300;
        printf("[%d] changed value of myVariable is %d\n", getpid(), myVariable);
    }

    printf("=> [%d] final value of myVariable is %d\n", getpid(), myVariable);

    return 0;
}