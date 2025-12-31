#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

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

	char out;
	while (read(openedFile, &out, 1) > 0) {
		write(STDOUT_FILENO, &out, 1);
	}
	close(openedFile);
	return 0;
}
