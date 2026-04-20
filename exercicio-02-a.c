#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    printf("[%d] hello world\n", (int)getpid());
    int fd = open("q2.c", O_RDONLY);    // any .c file, which "always" starts with #incl...
    if(fd == -1) {
        printf("Unable to open the file\n exiting....\n");
        exit(1);
    }
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("      [%d] hello, I'm %d, my father is %d\n", getpid(), getpid(), getppid());
        char myChar;
        read(fd, &myChar, 1);
        printf("      [%d] I'm reading a character from the file and printing it => %c\n", getpid(), myChar);
    }
    else {
        wait(NULL);
        printf("[%d] hello, I'm %d, my father is %d, and my son is %d\n", getpid(), getpid(), getppid(), pid);
        char myChar;
        read(fd, &myChar, 1);
        printf("[%d] I'm reading a character from the file and printing it => %c\n", getpid(), myChar);
    }
    return 0;
}