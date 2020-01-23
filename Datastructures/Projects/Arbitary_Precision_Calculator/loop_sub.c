
#include "Dlist.h"

int loop_sub(Dlink **temp1_h, Dlink **temp1_t, Dlink **temp2_h, Dlink **temp2_t)
{
//    printf("	\nLoop-sub\n");

    int count = 0;
    Dlink *temp3_h = NULL, *temp3_t = NULL;

    while((*temp1_h)->data != NEGATIVE)
    {
	//Subtract number - divisor
	dl_sub(temp1_h, temp1_t, temp2_h, temp2_t, &temp3_h, &temp3_t);
	
	delete_list(temp1_h, temp1_t);
	*temp1_h = temp3_h, *temp1_t = temp3_t;

//	printf("    Remainder : ");
//	print_list(*temp1_h);

	temp3_h = temp3_t = NULL;
	
	count++;
     }

  //   printf("	    Out : ");
    // print_list(*temp1_h);

     //Remove negative sign
     delete_first(temp1_h, temp1_t);

//     printf("		temp1---");
  //   print_list(*temp1_h);

     //Add divisor to remainder to make it pos
     dl_sub(temp2_h, temp2_t, temp1_h, temp1_t, &temp3_h, &temp3_t);
     delete_list(temp1_h, temp1_t);
     *temp1_h = temp3_h, *temp1_t = temp3_t;

//     printf("		----END : ");
  //   print_list(*temp1_h);

     // -- - for the above addition
     return --count;
 }

