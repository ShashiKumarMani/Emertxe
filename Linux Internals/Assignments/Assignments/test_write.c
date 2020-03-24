
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("red.txt", O_WRONLY | O_CREAT, 0666);

    if(fd == -1)
    {
	printf("ERROR\n");
	return 0;
    }

    char num = 5;
    write(fd, &num, 1);

    return 0;
}
