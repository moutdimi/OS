#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    pid_t pid;
    int file_fd;
    char buffer[100];

    file_fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file_fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        close(file_fd);
        return 1;
    }

    if (pid == 0) {
        snprintf(buffer, sizeof(buffer), "Child PID: %d\n", getpid());
        write(file_fd, buffer, strlen(buffer));
        printf("Child: PID written to file.\n");
    } else {
        snprintf(buffer, sizeof(buffer), "Parent PID: %d\n", getpid());
        write(file_fd, buffer, strlen(buffer));
        printf("Parent: PID written to file.\n");
    }

    close(file_fd);
    return 0;
}

//The file is created and appended as intended.

