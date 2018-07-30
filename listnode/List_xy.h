#ifndef __LIST_XY_H__
#define __LIST_XY_H__

// define data type of the element 
#define ELementDate int

typedef struct SingleListNode{
    ELementDate val; 
    struct SingleListNode *next;
}Node,*PNode;

// Initial the single list
PNode Single_InitList(PNode PHead);

// insert the val to the head of single list 
PNode Single_InsertListHead(PNode PHead,int InsertVal);

// insert the val to the end of single list 
PNode Single_InsertListEnd(PNode PHead,int InsertVal);

// insert the val to the assign location of single list 
void Single_InsertAsgnList(PNode PHead,int InsertLoc,int InsertVal);

// delete the assign node 
void Single_DeleteNode(PNode PHead,int Deleteloc);

// Print the single list
void Single_PrintList(PNode PHead);

// Read the list from the file List.data
void Single_ReadList(PNode PHead);

// Write the list to the file List.data
void Single_WriteList(PNode PHead);

// Free the list
int Single_FreeList(PNode PHead);

#endif
