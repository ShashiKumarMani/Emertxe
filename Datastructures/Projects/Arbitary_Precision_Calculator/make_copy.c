/*
    Copy temp2 to temp1
 */
#include "Dlist.h"

int make_copy(Dlink **temp1_h, Dlink **temp1_t, Dlink *temp2_h, Dlink *temp2_t)
{
    while(temp2_h)
    {
	insert_last(temp1_h, temp1_t, temp2_h->data);
	temp2_h = temp2_h->next;
    }
}
