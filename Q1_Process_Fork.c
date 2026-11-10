#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else {
        wait(NULL);
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), pid);
    }
    return 0;
}
