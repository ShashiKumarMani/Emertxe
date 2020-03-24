
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int ret = open(argv[1], O_WRONLY | O_CREAT | O_EXCL);

    if(ret == -1)
    {
	if(errno == EEXIST)
	{
	    printf("ERROR : File exists\n");
	}
    }
}
