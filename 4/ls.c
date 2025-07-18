#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

// Execution: ./a.out .
void main(int arg, char *argv[]) {
    DIR *dp;
    struct dirent *entry; 

    dp = opendir(argv[1]);
    entry = readdir(dp);
    while(entry != NULL) {

        printf("%s\n", entry->d_name);
        entry = readdir(dp);
    }
    closedir(dp);
}

/* 
Parameters for the main function:

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}

./myprog hello world

Number of arguments: 3
Argument 0: ./myprog
Argument 1: hello
Argument 2: world

*/

