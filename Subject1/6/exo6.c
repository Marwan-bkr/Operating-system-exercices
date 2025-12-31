#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main( int argc, char **argv)
{
         for (int i = 1; i < argc; i++)
        {
                //fstat
                int openedFile = open(argv[i], O_RDONLY);
                struct stat info;
                fstat(openedFile, &info);
		printf("File %s\n", argv[i]);
                printf("inode number : %lu\n", (unsigned long) info.st_ino);
		printf("size %lld bytes\n", (long long)info.st_size);
		printf("Permissions : %o\n", info.st_mode);
		printf("Size of a block : %ld bytes\n", (long) info.st_blksize);
		printf("Number of physical links : %lu\n", (unsigned long) info.st_nlink);
		printf("Number of blocks : %lld\n", (long long) info.st_blocks);
                printf("owner uid: %lu\n", (unsigned long) info.st_uid);
		printf("last acces : %s", ctime(&info.st_atime));
                printf("group gid: %lu\n\n", (unsigned long) info.st_gid);
                close(openedFile);
        }
         return 0;
}
