#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    int status;
    pid_t pid;

    int ret = fork();

    if(ret == 0)
    {
	printf("Child\n");
	return 0;
    }
    else if(ret > 0)
    {
	pid = wait(&status);

	if(WIFEXITED(status))
	{
	    printf("Child %d terminated normally\n", pid);
	    printf("Status of child - %d\n", WEXITSTATUS(status));

	}
	else
	{
	    printf("Child %d terminated\n", pid);
	}
    }
}

