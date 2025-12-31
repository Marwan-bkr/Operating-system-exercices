#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
        if (argc != 2) {
                printf("No file argument\n");
                return 1;
        }

        
        int openedFile = open(argv[1], O_RDONLY);
	if (openedFile > -1){
		close(openedFile);
		printf("File already exist\n");
		return -1;
	} else {
		int create = creat(argv[1], 0755);
	}
        return 0;
}

