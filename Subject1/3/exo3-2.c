#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
        if (argc != 2) {
                printf("No file argument");
                return 1;
        }

        int openedFile = open(argv[1], O_RDONLY);
        struct stat info;
        fstat(openedFile, &info);

        if(!S_ISREG(info.st_mode)) {
                printf("Not a regular file");
                close(openedFile);
                return 1;
        }

        char out[1024];
	ssize_t n;
	while ((n= read(openedFile, &out, BUF_SIZE)) > 0) {
                write(STDOUT_FILENO, &out, n);
        }
        close(openedFile);
        return 0;
}

