/*
    Title - my_cp
    Author - Shashikumar M
    Date - 21 January 2020
    Description - Program to implement the cp command
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define SIZE 10

/* Function to validate CLA*/
int validate_args(char *argv[], char **src_fname, char **dest_fname)
{
    //If p option was passed
    if(strcmp(argv[1], "-p") == 0)
    {
	*src_fname = argv[2];
	*dest_fname = argv[3];
	return 1;
    }
    else
    {
	*src_fname = argv[1];
	*dest_fname = argv[2];
	return 0;
    }
}

/* Function to implement cp command*/
int my_copy(int src_fd, int dest_fd, int flag)
{
    char buff[SIZE];
    int r_ret, w_ret;

//    printf("CP : sr:%d dt:%d\n", src_fd, dest_fd);

    do
    {
	if((r_ret = read(src_fd, buff, SIZE)) == -1)
	{
	    if(errno == EBADF)
	    {
		printf("ERROR : Read\n");
		return -1;
	    }
	}

	if((w_ret = write(dest_fd, buff, r_ret)) == -1)
	{
	    if(errno == EBADF)
	    {
		printf("ERROR : Write\n");
		return -1;
	    }
	}

    }while(r_ret != 0);

    //If -p flag is set, copy the file permissions
    if(flag)
    {
	struct stat var;
	fstat(src_fd, &var);

	fchmod(dest_fd, var.st_mode);
    }
}

/* Main	*/
int main(int argc, char *argv[])
{
    char *src_file = NULL, *dest_file = NULL, option;

    //Error check the CLA
    if(argc < 3)
    {
	printf("\nERROR : Enter the arguments in format <-p> <source file> <dest. file>\n");
	return 0;
    }

    int flag = validate_args(argv, &src_file, &dest_file), src_fd, dest_fd;

    printf("Validation Done, src_f : %s, dest_f : %s\n", src_file, dest_file);

    //Open source file
    if((src_fd = open(src_file, O_RDONLY)) == -1)
    {
	printf("ERROR : Open src\n");

	if(errno == EACCES)
	{
	    printf("ERROR : File doest not exist Or cannot be accessed\n");
	}
    }

    //Open destination file
    if((dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_EXCL, 0666)) == -1)
    {
	printf("ERROR : Open dest\n");
	if(errno == EEXIST)
	{
	    printf("File Exist\n");
	    
	    printf("Do you want to write to the file ? [Yy | Nn] : ");
	    scanf("\n%c", &option);
		
	    if(option == 'Y' || option == 'y')
	    {
		if((dest_fd = open(dest_file, O_WRONLY)) == -1)
		{
		    printf("ERROR : Open file open\n");
		}
	    }
	    else
	    {
		printf("\nExiting.....\n");
		sleep(1);
		return 0;
	    }

	}	    
    }	    

    //If cpoy returns error
    if(my_copy(src_fd, dest_fd, flag) == -1)
    {
	printf("ERROR : File Descriptors\n");
    }
}
