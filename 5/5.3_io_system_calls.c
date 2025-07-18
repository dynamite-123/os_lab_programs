#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[20];

    if (argc != 2) {
        write(2, "Usage: ./a.out <filename>\n", 26);
        return 1;
    }

    // Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "Cannot open file\n", 17);
        return 1;
    }

    // i. Read first 10 characters
    read(fd, buf, 10);
    write(1, "First 10 chars: ", 16);
    write(1, buf, 10);
    write(1, "\n", 1);

    // ii. Skip 5 characters
    lseek(fd, 5, SEEK_CUR);
    read(fd, buf, 10);
    write(1, "After skipping 5 chars, next 10: ", 33);
    write(1, buf, 10);
    write(1, "\n", 1);

    // iii. Go to 5th last character in file
    lseek(fd, -5, SEEK_END);
    read(fd, buf, 1);
    write(1, "5th last char: ", 15);
    write(1, buf, 1);
    write(1, "\n", 1);

    // iv. Go to the 3rd character in the file
    lseek(fd, 2, SEEK_SET); // 0-based: position 2 is the 3rd character
    read(fd, buf, 1);
    write(1, "3rd char: ", 10);
    write(1, buf, 1);
    write(1, "\n", 1);

    close(fd);
    return 0;
}
