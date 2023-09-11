#include<stdio.h>
#include<stdlib.h>
#include "STD_TYPES.h"
#include "NODE.h"
#include"ListLib.h"

extern u8 ListIsEmpty;

Node* GetNewNode()
{
    Node* NewNode = (Node*) malloc(sizeof(Node));
    return NewNode;
}

void SetData(Node* node,u32 Data)
{
    node->data=Data;
}

u32 GetData(Node* node)
{
    return node->data;
}

void SetNext(Node* node,Node* Next)
{
    node->next=Next;
}

Node* GetNext(Node* node)
{
    return node->next;
}
void SetNode(Node* node,u32 Data,Node* Next)
{
    SetData(node,Data);
    SetNext(node,Next);
}
void CpyNode(Node* node,Node* NewVals)
{
    SetNode(node,GetData(NewVals),GetNext(NewVals));
}

Node* GetHeavyNode(u32 Data,Node* Next)
{
    Node* NewNode = GetNewNode();
    SetNode(NewNode,Data,Next);
    return NewNode;
}
u8 GetListSize(Node* Head)
{
    u8 size=0;
    if(!ListIsEmpty)
    {
        Node* node= Head;
        while(node!=NULL)
        {
            size++;
            node=GetNext(node);
        }
    }
    return size;
}

Node* GetTailAddress(Node* node)
{
    // node represents any node in the list
    if(node!=NULL)
    {
        while(node->next!=NULL)
            node=GetNext(node);
        return node;
    }
    return node;
}

Node* GetAddressAt(Node* Head,u8 NodeIndex)
{
    Node* node;
    if(NodeIndex==1)
        return Head;
    else
    {
        u8 size=2;
        node=GetNext(Head);
        while(size!=NodeIndex)
        {
            size++;
            node=GetNext(node);
        }
    }
    return node;

}

void AddNode(Node* Head,u32 data)
{
	if (ListIsEmpty)
	{
		SetNode(Head,data,NULL);
		ListIsEmpty=false;
	}
	else
	{
		Node* NewNode = GetHeavyNode(data,NULL);
		Node* Tail = GetTailAddress(Head);
		SetNext(Tail,NewNode);
	}
	printf(" Node Added Successfully ! (^_^)\n");
}

void AddNodeAt(Node* Head,u8 NodeIndex,u32 data)
{
	u8 size = GetListSize(Head);
	if (NodeIndex>=1&&NodeIndex<=size+1)
	{
		if ((NodeIndex==1&&size==0)||(NodeIndex==size+1))
			AddNode(Head,data);
		else if(NodeIndex==1)//Add a new Head
		{
			/*  Add a new head but avoiding Re-Assigning head 
				So i didn't use Head=NewNode() (if I use it Head never changed always=null)
				to solve it i swapped the values between the old head and the new one
			*/
			Node* New_Node = GetHeavyNode(GetData(Head),GetNext(Head));
			SetNode(Head,data,New_Node);
			printf(" Node has been Added As a Head of the List Successfully! (^_^)\n");
		}
		else
		{
			Node* NewNode = GetNewNode();
			Node* NewNext =GetAddressAt(Head,NodeIndex);
			Node* PreviousNode = GetAddressAt(Head,NodeIndex-1);
			SetNext(PreviousNode,NewNode);
			SetNode(NewNode,data,NewNext);
			if (NodeIndex==size+1)
				printf(" Node has been added As a Tail of the List Successfully ! (^_^)\n");
			else
				printf(" Node has been added Successfully ! (^_^)\n");
		}
	}
	else
		printf(" The Index you had entered is out of list. \n");
}

void RemoveNode(Node* Head,u8 NodeIndex)
{
	u8 size = GetListSize(Head);
	if (NodeIndex==1&&size==1)
	{
		ListIsEmpty=true;
		printf(" Removing the Head Node.\n");
	}
	else if(NodeIndex<1||NodeIndex>size)
		printf(" Invalid Index (-_-), Make sure you enter an Index between [1 :size].\n current size = %d\n",size);
	else
	{
		/*
		Get the Unwanted node  
		Get address of the next node
		get the previous node
		previous points to next node
		*/
		if (NodeIndex==1&&size!=1)//removing the Head Node 
		{
			Node* Temp = GetNext(Head);
			CpyNode(Head,Temp);
			free(Temp);
			printf(" Removing the Head Node.\n");
		}
		else if (NodeIndex==size)//removing tail
		{
			Node* PreviousNode =GetAddressAt(Head,NodeIndex-1);
			free(GetNext(PreviousNode));
			SetNext(PreviousNode,NULL);
			printf(" Removing the Tail Node.\n");
		}
		else// removing a middle node
		{
			Node* UnwantedNode =GetAddressAt(Head,NodeIndex);
			Node* PreviousNode =GetAddressAt(Head,NodeIndex-1);
			SetNext(PreviousNode,GetNext(UnwantedNode));
			free(UnwantedNode);
		}
		printf(" Node is Removed Successfully ! (^_^)\n");
	}
}
void DeleteList(Node* Head)
{
	if(ListIsEmpty)
		printf(" List is already Empty.(-*-)\n");
	else if (GetListSize(Head)==1)
		ListIsEmpty=true;
	else
	{
		Node* Temp = GetNext(Head);
		//Can't Remove the Head or make Head=null or Re-assignes it after equalling null
		Node* HoldAddress=Head;;
		while(Temp!=NULL)
			{
				HoldAddress=Temp;
				Temp = GetNext(Temp);
				free(HoldAddress);
			}
		SetNext(Head,NULL);
		ListIsEmpty=true;
	}
}

void ElementAt(Node* Head,u8 NodeIndex)
{
	u8 size= GetListSize(Head);
	if(NodeIndex>=1&&NodeIndex<=size)
	{
		Node* node=GetAddressAt(Head,NodeIndex);
		printf(" Node @ index (%d) =  %hu\n",NodeIndex,GetData(node));
	}
	else
	{
		printf(" The index you entered is invalid (-_-)\n A valid Index is between [1:size]\n");
		printf("Current List Size = %d .\n",size);
	}
}
void UpdateNode(Node* Head,u8 NodeIndex,u32 NewData)
{
	u8 size= GetListSize(Head);
	if(NodeIndex>=1&&NodeIndex<=size)
	{
		Node* node=GetAddressAt(Head,NodeIndex);
		SetData(node,NewData);
		printf(" Node is Updated Successfully ! (^_^)\n");
	}
	else
		printf(" Node index is invalid (-_-)\n A valid Index is between [1:size]\n Current List Size = %d .\n",size);

}
void SearchForNode(Node* Head,u32 data)
{
	u8 Index=0, flag = 0;
	if(!ListIsEmpty)
	{
		Node* node= Head;
		while(node!=NULL)
		{
			Index++;
			if(GetData(node)==data)
			{
				flag=1;
				printf(" Found! Node Index is : %d (1-Based Indexing)\n",Index);
				break;
			}
			else
				node=GetNext(node);
		}
	}
	if(flag==0)
		printf(" This node isn't in the list (-_-)\n");
}
 void ArrangeList(Node* Head,u8 Size)
 {
	u8 Tsize;
	Node* Current =Head;
	Node* Next=NULL;
	u32 TempData;
	while(Size!=1)
	{
		Current =Head;
		for(Tsize=0;Tsize<Size-1;Tsize++)
		{
			Next=GetNext(Current);
			if(GetData(Current) > GetData(Next))
			{
				TempData = GetData(Next);
				SetData(Next,GetData(Current));
				SetData(Current,TempData);
			}
			Current=Next;
			Next=GetNext(Next);
		}
		Size--;
	}
	printf(" Done, List is arranged Successfully ! (^_^)\n");
 }
