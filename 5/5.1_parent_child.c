#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, wpid;

    int status;

    pid = fork();
    
    if(pid < 0) {printf("Fork failed"); exit(1);}

    if(pid == 0) {
        printf("CHILD: pid: %d ppid: %d\n", getpid(), getppid());
    }

    else {
        printf("PARENT: pid: %d ppid: %d child_pid: %d\n", getpid(), getppid(), pid);
        wpid = waitpid(pid, &status, 0);

        if(wpid < 0) {printf("Wait failed"); exit(1);}
        else {
            printf("Parent: Child with PID %d terminated.\n", pid);
        }
    }
    
}
