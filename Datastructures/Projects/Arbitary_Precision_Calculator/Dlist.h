#ifndef SLIST_H
#define SLIST_H

//Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>                              

//Macros
#define FAILURE -987
#define SUCCESS 909
#define DATA_NOT_FOUND -234
#define NEGATIVE -2435
#define DOT -435
#define LIST_EMPTY -456
#define PRECISION 20

//UDDF
typedef int data_t;
typedef struct node{
    
    struct node *prev;
    short data;
    struct node *next;

}Dlink;

/*
   Function declarations
 */
void sleep(void);
data_t insert_first(Dlink **, Dlink **,data_t);
data_t insert_last(Dlink **, Dlink **, data_t);
data_t delete_first(Dlink **, Dlink **);
data_t delete_last(Dlink **, Dlink **);
data_t delete_list(Dlink **, Dlink **);
data_t print_list(Dlink *);
data_t dl_cla(char *, Dlink **, Dlink **, Dlink **, Dlink **, char *);
data_t dl_add(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);
data_t dl_sub(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);
data_t dl_sub(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);
data_t dl_mul_one(Dlink **, Dlink **, int, Dlink **, Dlink **);
data_t dl_mul(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);
data_t add_one(Dlink **, Dlink **, Dlink *);
data_t dl_div(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);
data_t make_copy(Dlink **, Dlink **, Dlink *, Dlink *);
data_t loop_sub(Dlink **, Dlink **, Dlink **, Dlink **);
data_t loop_div(Dlink **, Dlink **, Dlink **, Dlink **, Dlink **, Dlink **);

#endif
