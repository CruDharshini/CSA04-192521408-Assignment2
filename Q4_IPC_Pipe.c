#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    char buf[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t p = fork();

    if (p == -1) {
        perror("fork");
        return 1;
    }

    if (p == 0) {
        close(fd[1]);
        int n = read(fd[0], buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            printf("Child received: %s\n", buf);
        }
        close(fd[0]);
    } else {
        close(fd[0]);
        write(fd[1], "Hello from Parent", 17);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
