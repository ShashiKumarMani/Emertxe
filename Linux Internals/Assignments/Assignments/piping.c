
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd[2], status;
    pipe(fd);
    char *cmd1[2] = {NULL}, *cmd2[2] = {NULL};
    cmd1[0] = argv[1], cmd2[0] = argv[2];

    int stdout_dup = dup(1);

    if(fork() == 0)
    {
	close(1);
	dup(fd[1]);
	close(fd[0]);
//	execlp(argv[1], argv[1], NULL);
	execvp(cmd1[0], &cmd1[0]);
    }
    else
    {
	wait(&status);
	dup2(stdout_dup, 1);
	
	if(fork() == 0)
	{
	    close(0);
	    dup(fd[0]);
	    close(fd[1]);
//	    execlp(argv[2], argv[2], NULL);
	    execvp(cmd2[0], &cmd2[0]);
	}
	else
	{
//	    wait(&status);
    }
    }

    return 0;

}
