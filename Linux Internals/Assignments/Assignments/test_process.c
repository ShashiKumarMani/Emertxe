
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    
    if(pid > 0)
    {
	while(1);
    }
    else if(!pid)
    {
	sleep(10);
    }
}
