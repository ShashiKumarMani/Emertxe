
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char ch;
    int i = 0, ret;

    FILE *ptr = fopen(argv[1], "rb");

    while(ret = read(fd, &ch, 1))
    {
	if(ret == -1)
	    printf("ERROR\n");
	else if(ret == 0)
	    break;

	printf("%d %d %c\n", i, ch, ch);

	i++;
    }
    
    printf("-->%c %d\n", ch, ch);
    return 0;
}
