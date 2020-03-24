/*############################################################################################### 
 *
 *           Author         : Shashi Kumar M 
 *           Date           : March 2020
 *           File           : file.c©
 *           Descriptions   : All file operations
 *           Objective      : To read/write from/to file in both server and client side
 *
###############################################################################################*/

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "tftp.h"

int file_open_read(char *filename)
{
	return open(filename, O_RDONLY);
}

int file_open_write(char *filename)
{
	return open(filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
}

int file_close(int file_fd)
{
	close(file_fd);
}
