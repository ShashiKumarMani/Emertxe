
#include "Dlist.h"

int insert_first(Dlink **head, Dlink **tail, data_t data)
{
    Dlink *temp = *head, *new = malloc(sizeof(Dlink));
    
    if(new == NULL)
    {
	printf("ERROR : Memory allocation.\n");
	return 0;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
	*head = new;
	*tail = new;
	return 1;
    }

    (*head)->prev = new;
    new->next = *head;
    *head = new;

    return 1;
}

