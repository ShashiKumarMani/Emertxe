/*
    Function to open files
 */

#include "header.h"

data_t open_files(FileInfo *InputData)
{
    //Open source and Destination files
    if((InputData->src_ptr = fopen(InputData->src_fname, "rb")) == NULL)
    {
	return FAILURE;
    }

    if((InputData->dest_ptr = fopen(InputData->dest_fname, "wb")) == NULL)
    {
	return FAILURE;
    }

    return SUCCESS;
}
