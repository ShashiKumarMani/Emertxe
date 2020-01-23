/*
    Function to create a file node
*/

#include "header.h"

Filenode *create_file_node(char *file_name)
{
//    printf("Creating file node %s\n", file_name);
    Filenode *new = malloc(sizeof(Filenode));
    new->file_link = NULL;

    strcpy(new->file_name, file_name);
    new->word_count = 1;

    return new;
}
