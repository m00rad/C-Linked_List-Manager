//file guard 
#ifndef _NODE
#define _NODE
#include "STD_TYPES.h"
typedef struct node
{
	u32 data;
	struct node* next;
}Node;


#endif