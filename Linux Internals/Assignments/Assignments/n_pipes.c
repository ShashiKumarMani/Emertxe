
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char ** argv) {
    int i;

    for( i=1; i<argc-1; i++)
    {
        int pd[2];
        pipe(pd);

        if (!fork()) 
	{
	    dup2(pd[1], 1);
            execlp(argv[i], argv[i], NULL);
	    return 0;
	}

        dup2(pd[0], 0);
        close(pd[1]);
    }

    execlp(argv[i], argv[i], NULL);
    return 0;
}
