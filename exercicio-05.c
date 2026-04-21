#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define N 4

void cria_procs(){
    pid_t new_proc;
    int i = 0;

    printf("I'm %d: PID = %d\tPPID = %d\n", i, getpid(), getppid());
    for (i=1; i<=N; i++) {
        new_proc = fork();
        if (new_proc == 0)
            printf("I'm %d: PID = %d\tPPID = %d\n", i, getpid(), getppid());
        else
            break;
    }
}

int main(){
    cria_procs();
    getchar();
    return 0;
}