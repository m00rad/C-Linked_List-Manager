#include<stdio.h>
#include"STD_TYPES.h"
#include "NODE.h"
#include"SystemFunctions.h"

void PrintAppMenu()
{
	printf(" __________________________________\n");//
	printf(" To Add Node   --------> Enter : 1 \n");//Mandatory
	printf(" To Add Node At -------> Enter : 2 \n");//Extra
	printf(" To Remove Node  ------> Enter : 3 \n");//Extra
	printf(" To Update Node   -----> Enter : 4 \n");//Extra
	printf(" To Show the list  ----> Enter : 5 \n");//Mandatory
	printf(" To Get list Size   ---> Enter : 6 \n");//Extra
	printf(" To Delete the list  --> Enter : 7 \n");//Extra
	printf(" To Clear the Screen  -> Enter : 8 \n");//Extra
	printf(" To Search for Node  --> Enter : 9 \n");//Extra
	printf(" To Get Element At  ---> Enter : 10\n");//Extra
	printf(" To Arrange List   ----> Enter : 11\n");//Extra
	printf(" To Exit          -----> Enter : 0 \n");//Mandatory
	printf(" __________________________________\n\n");//

}

void PrintList(Node* Head)
{
	u8 size=0;
	Node* node= Head;
	while(node!=NULL)
	{
		size++;
		printf(" Node : %d data = %hu \n",size,node->data);
		node=node->next;	
	}
	if (size==0)
		printf(" No Elements in the list (-_-)\n");
}
