#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//usage: ./a.out pattern filename
void main(int argc, char *argv[]) {
    char *pattern = argv[1];
    char *filename = argv[2];

    FILE *fp = fopen(filename, "r");

    char line[1024];

    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, pattern)) {
            printf("%s\n", line);
        }
    }

    fclose(fp);
}
