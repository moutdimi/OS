#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//Waiting Commands have been added so the processes print in an organized ordder.

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child process 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    } else if (pid1 > 0) {
        wait(NULL);
        printf("Parent process after first fork: PID = %d\n", getpid());
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Child process 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    } else if (pid2 > 0) {
        wait(NULL);
        printf("Parent process after second fork: PID = %d\n", getpid());
    }

    pid3 = fork();
    if (pid3 == 0) {
        printf("Child process 3: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    } else if (pid3 > 0) {
        wait(NULL);
        printf("Parent process after third fork: PID = %d\n", getpid());
    }

    return 0;
}
