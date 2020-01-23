/*
 
       Function to insert a new node at the end of a linked list.
   
 */

#include "header.h"

int insert_last(Filenames **head, char *filename)
{
    //1. Create a new node.
    Filenames *new = malloc(sizeof(Filenames)), *temp = *head;

    //2. Check if node is create.
    if(new == NULL)
    {
	printf("Memory error\n");
	return FAILURE;
    }	
    
    //3. Update data and link.
    new->filename = malloc(sizeof(filename));
    strcpy(new->filename, filename);
    new->link = NULL;

//    printf("New node created\n");

    //4. Check if list empty.
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }

    //5. Traverse the list and add the node
    while(temp -> link)
    {
	temp = temp -> link;
    }
    
    temp -> link = new;
    
    return SUCCESS;
}
