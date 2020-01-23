#include "Dlist.h"

data_t delete_list(Dlink **head, Dlink **tail)
{
    if(*head == NULL)
    {
	return 0;
    }

    Dlink *temp1 = NULL, *temp2 = *head;

    while(temp2)
    {
	temp1 = temp2;
	temp2 = temp2->next;
	free(temp1);
    }

    *head = *tail = NULL;
}
