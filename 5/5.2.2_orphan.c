#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

 
    if (pid == 0) {
        // Child process
        printf("Child: PID=%d, Parent PID=%d\n", getpid(), getppid());
        printf("Child sleeping for 10 seconds...\n");
        sleep(10);
        printf("Child: After sleep, new Parent PID=%d (should be 1 or systemd)\n", getppid());
        exit(0);
    } else {
        // Parent process
        printf("Parent: PID=%d, Child PID=%d\n", getpid(), pid);
        printf("Parent exiting...\n");
        exit(0);
    }
}
