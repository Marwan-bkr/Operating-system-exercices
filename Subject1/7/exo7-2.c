#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	off_t offset;
	int openedFile = open("example3.txt", O_CREAT | O_WRONLY, 0777);
	write(openedFile, "lorem upsum", 10);
	offset = lseek(openedFile, 0, SEEK_CUR);
	printf("example3.txt offset : %ld\n", (long)offset);
	int openedFile2= dup(openedFile);
	printf("Duplicated file of example3.txt offset : %ld\n", (long)lseek(openedFile2, 0, SEEK_CUR));
	printf("example3.txt offset after lseek modification : %ld\n", (long)lseek(openedFile, 10, SEEK_CUR));
	printf("Duplicate file offset without modifying it : %ld\n", (long)lseek(openedFile2, 0, SEEK_CUR));
    printf("Duplicate file offset after lseek modification : %ld\n", (long)lseek(openedFile2, 15, SEEK_CUR));
	printf("example3.txt offset without modifying it : %ld\n", (long)lseek(openedFile, 0, SEEK_CUR));
	close(openedFile);
	close(openedFile2);
}
