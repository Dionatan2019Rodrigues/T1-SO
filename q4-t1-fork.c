#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    printf("[%d] Starting tree...\n", getpid());

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    // FILHO
    if (pid1 == 0) {
        printf("[%d] My father is %d\n", getpid(), getppid());

        pid2 = fork();
        if (pid2 < 0) {
            perror("fork failed");
            exit(1);
        }

        // NETO
        if (pid2 == 0) {
            printf("[%d] My father is %d\n", getpid(), getppid());
            printf("[%d] I'm exiting\n", getpid());
            exit(0);
        }
        wait(NULL); // FILHO espera NETO
        printf("[%d] I'm exiting\n", getpid());
        exit(0);
    }
    
    wait(NULL); // espera FILHO
    printf("[%d] Complete tree. I'm exiting\n", getpid());
    return 0;
}