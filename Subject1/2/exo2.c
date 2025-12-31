#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int compareNode(int argc, char **argv) {
	if (argc != 3) {
		return -1;
        }
        unsigned long node[argc];
        for (int i = 1; i < argc; i++)
        {
  	      struct stat info;
              if (stat(argv[i], &info) != 0) {
		      return 2;
              }
     	      node[i] = (unsigned long) info.st_ino;
        }
        if (node[1] == node[2]) {
 	       return 1;
        } else {
	        return 0;
	}
}


int main( int argc, char **argv)
{
	printf("Returns : %d\n", compareNode(argc, argv));
	return 0;
}

