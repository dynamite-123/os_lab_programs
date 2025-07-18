#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// ls command simulation
// Execution: ./a.out filename
void main(int arg, char *argv[]) {
    char *filename = argv[1];

    if(unlink(filename) == 0) {
        printf("File removed successfully\n");
    } else {
        printf("File removal was unsuccessful\n");
    }
}


