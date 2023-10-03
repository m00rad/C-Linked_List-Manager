#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"STD_TYPES.h"
#include"NODE.h"
#include"ListLib.h"
#include"SystemFunctions.h"

// Global Variables
u8 ListIsEmpty = true; // Flag to avoid (Head = NULL) Bug
void main()
{
	printf("\n\t  Welcome (^_^)  \n");
	printf("\tLast C Assignment  \n");
	
	Node* Head = GetNewNode();
	/*
		Here I have to allocate a block in memory for the Head and not assigning it to null;
		if I just Assigne Head = null 
		AddNode won't work cuz it always sees Head as a null value 
		even if I changed the return type of Fun AddNode to Node* instead of void 
		and Re assigne Head (which's = null) to the returned pointer of the func
			Head = AddNode(Head,data); of course it will be writen in the while loop below 
	*/
	
	//Node* Head = NULL ;
	//		--> Head -no matter what you Re-Assigne it to or how- will be always NULL IDK why.
	
	/*
		Node* Head= GetNewNode();
		Run Correctlly but causes some scenario and status needs to be handled
		Thats why I used a Global Variable/Flag  
		Could be local but I will have to pass it by reference to the functions  
		Not Very efficient (from Memory perspective/Memory wise)
		When the list is Empty As it Allocate an Empty Block in mem
	*/
	u8 choice;
	while(1)
	{
		PrintAppMenu();
		printf(" Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :// Add Node
			{
				printf("  >>Add Node<< \n");;
				u32 data;
				printf(" Enter Node data :  ");
				scanf("%lu",&data);
				AddNode(Head,data);
				//Head =AddNode(Head,data);//Head always Null
				break;
			}
			case 2 :// Add Node @t
			{
				printf("  >>Add Node At<< \n");;
				u8 NodeIndex;
				u32 NodeData;
				printf(" Enter Data of the node : ");
				scanf("%lu",&NodeData);
				printf(" Enter an index(1-Based) to Add the node in : ");
				scanf("%d",&NodeIndex);
				AddNodeAt(Head,NodeIndex,NodeData);
				break;
			}
			case 3 :// Remove Node @t
			{
				printf("  >>Remove Node At<< \n");
				if(!ListIsEmpty)
				{
					u8 NodeIndex;
					printf(" Enter the node Order (1-Based indexing) : ");
					scanf("%d",&NodeIndex);
					RemoveNode(Head,NodeIndex);
				}
				else
					printf(" List is Empty (-_-)\n So You Can't remove any Nodes \n Please Add one or more nodes first\n");

				break;
			}
			case 4 :// Update Node
			{
				printf("  >>Update Node<< \n");
				if(ListIsEmpty)
					printf(" No nodes to be updated List is Empty\n");
				else
				{
					u8 NodeIndex;
					printf(" Enter the targeted Node Index : ");
					scanf("%d",&NodeIndex);
					u32 NewData;
					printf(" Enter New Data Value : ");
					scanf("%lu",&NewData);
					UpdateNode(Head,NodeIndex,NewData);
				}
				break;
			}
			case 5 :// Show List
			{
				printf("  >>Show List<< \n");
				if(!ListIsEmpty)
					PrintList(Head);
				else
					printf(" List is Empty (-_-)\n Add some nodes first\n");
				break;
			}
			case 6 :// Get List Size
			{
				printf("  >>Get List Size<< \n");
				u8 size =GetListSize(Head);
				printf(" List Size = %d \n",size);
				break;
			}
			case 7 :// Delete List
			{
				printf("   >>Delete List<< \n");
				if(ListIsEmpty)
					printf(" List Cann't be deleted (-_-)\n Because it's already Empty\n");
				else
					DeleteList(Head);
				printf(" list is Deleted Successfully ! (^_^)\n");

				break;
			}
			case 8 :// Clear scr
			{
				printf("  >>Clear Console Screen<< \n");
				printf("    Cleared after 3 Secs \n");
				sleep(3);
				system("cls");
				printf("\n\tWelcome again!(^_^)  \n");
				printf("\t Last C Assignment  \n");
				break;
			}
			case 9 :// SearchFor
			{
				printf("  >>Search For node<< \n");

				u32 NodeData;
				printf(" Enter Data of the node : ");
				scanf("%lu",&NodeData);
				if(ListIsEmpty)
					printf(" There are no nodes in the list to search for (-_-)\n");
				else
				{
					SearchForNode(Head,NodeData);
				}
				break;
			}
			case 10 :// ElementAt
			{
				printf("  >>Get Element At<< \n");
				u8 NodeIndex;
				printf(" Enter the Wanted Node Index : ");
				scanf("%d",&NodeIndex);
				ElementAt(Head,NodeIndex);
				break;
			}
			case 11 :// Arrange List
			{
				printf("  >>Arrange List<< \n");
				if(ListIsEmpty)
					printf("list is Empty (-_-)\n");
				else
					ArrangeList(Head,GetListSize(Head));
				break;
			}
			case 0 :// Exit
			{
				printf("  >>Exit<< \n");
				printf(" Thank You :) \n");
				printf(" Good Bye \n");
				if(!ListIsEmpty)
					DeleteList(Head);
				free(Head);
				return;
			}
			default:
				printf(" Invalid Choice Please Try Again (-_-)\n");
		}
	}
}