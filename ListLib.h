//file guard 
#ifndef _LIST_LIB_H
#define _LIST_LIB_H

Node* GetNewNode();

void SetData(Node* node,u32 Data);

u32 GetData(Node* node);

void SetNext(Node* node,Node* Next);

Node* GetNext(Node* node);

void SetNode(Node* node,u32 Data,Node* Next);

void CpyNode(Node* node,Node* NewVals);

Node* GetHeavyNode(u32 Data,Node* Next);

u8 GetListSize(Node* Head);

Node* GetTailAddress(Node* AnyNode);

Node* GetAddressAt(Node* node,u8 NodeIndex);

void AddNode(Node* Head,u32 data);

void AddNodeAt(Node* Head,u8 NodeIndex,u32 data);

void ElementAt(Node* Head,u8 NodeIndex);

void SearchForNode(Node* Head,u32 data);

void RemoveNode(Node* Head,u8 NodeIndex);

void DeleteList(Node* Head);

void UpdateNode(Node* Head,u8 NodeIndex,u32 NewData);

void ArrangeList(Node* Head,u8 Size);

#endif