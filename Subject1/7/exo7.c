#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){

	int openedFile = open("example2.txt", O_CREAT | O_WRONLY, 0777);
	off_t offset = lseek(openedFile, 10000, SEEK_SET);
	write(openedFile,"o", 1);
	close(openedFile);
}
