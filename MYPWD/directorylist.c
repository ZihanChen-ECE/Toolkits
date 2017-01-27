#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


int main(int argc, char ** argv)
{
    if (2 != argc) {
        fprintf(stderr, "Usage: %s directory...\n", argv[0]);
        exit(-1);
    }

    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    if (NULL == (dp = opendir(argv[1]))) {
        fprintf(stderr, "Can not open Input Directory [%s]\n", argv[1]);
        exit(-1);
    } else {
        printf("Directory [%s] Content List: \n", argv[1]);
        while (NULL != (dptr = readdir(dp))) {
            printf("inode-number: %-10ld \t filename: %s\n", dptr->d_ino, dptr->d_name);
        }

        closedir(dp);
    }

    return 0;
}