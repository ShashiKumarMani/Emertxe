 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <stdlib.h>
 #include <string.h>

    int main()
    {

    char *arr = malloc(sizeof(int));
    int num;
    int fd[2];
    char *piping = malloc(10*sizeof(char));
    char *word = malloc(10*sizeof(char));

    while(1)
    {
        printf("enter the number of child: ");
        fflush(stdout);
        fgets(arr, 10, stdin);

        printf("enter word: ");
        fflush(stdout);
        fgets(word, 10, stdin);

        num = atoi(arr);

        pipe(fd);
        for(int i = 0; i < num; i++)
        {
                if(!fork())
                {
                        read(0, piping, 10);
                        if(i != 0)
                        {
                            dup2(fd[0],0);
                        }
                        if(i != num-1)
                        {
                            dup2(fd[1],1);
                        }
                        write(1, piping, 10);
			exit(0);
   		}
                else
                    wait(0);
        }
    }
    return 0;
   }
