/*
    Function to find if file is duplicate.
    Returns FAILURE if duplicate
 */

#include "header.h"

int isduplicate(Filenames *filenames, char *filename)
{
    while(filenames)
    {
//	printf("----> NEWLIST Adding %s to newlist\n", filename);

	if(strcmp(filenames->filename, filename))
	    filenames = filenames->link;
	else
	    return FAILURE;
    }
    return SUCCESS;
}
