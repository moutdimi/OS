#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("Child received SIGINT signal from parent\n");
    }
}

int main() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        signal(SIGINT, signal_handler);
        pause();
    } else {
        sleep(1);
        kill(pid, SIGINT);
        printf("Parent sent SIGINT signal to child\n");
    }

    return 0;
}

//I understood the signaling to mean something like SIGINT.
