#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

#define SUCCESS -234
#define FAILURE -356

typedef int data_t;

typedef struct html{

    FILE *src_ptr, *dest_ptr;
    char *src_fname, *dest_fname;
    data_t line_flag;

}FileInfo;    

/* Function declarations */

data_t validate_args(char **, FileInfo *);
data_t open_files(FileInfo *);
data_t add_tags(FileInfo *);
#endif 
