#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void child_signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child: Received SIGUSR1 signal from parent\n");
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
        signal(SIGUSR1, child_signal_handler);
        printf("Child: Waiting for signal from parent...\n");
        pause();
    } else {
        sleep(1);
        kill(pid, SIGUSR1);
        printf("Parent: Sent SIGUSR1 signal to child\n");
    }

    return 0;
}
//Parent and child communicate via kill as intended.

