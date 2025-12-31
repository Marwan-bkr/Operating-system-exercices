#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char **argv)
{
 	 for (int i = 1; i < argc; i++) 
    	{
		//state
		struct stat info;
		stat(argv[i], &info);   		
		printf("with stat() :\n");
        printf("inode: %lu\n",(unsigned long) info.st_ino);
   		printf("links: %lu\n", (unsigned long) info.st_nlink);
        printf("owner uid: %lu\n", (unsigned long) info.st_uid);
        printf("group gid: %lu\n", (unsigned long) info.st_gid);
		printf("size %lld bytes\n", (long long)info.st_size);
	}
	 return 0;
}
