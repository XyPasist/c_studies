#include <stdio.h>
#include <stdlib.h>
#include "List_xy.h"
#include <malloc.h>

// Initial the single list
PNode Single_InitList(PNode PHead)
{
    PHead=(PNode)malloc(sizeof(Node));
    if (PHead==NULL){
        printf ("malloc PHead Failed!");
        exit(-1);
    }
    PHead->next=NULL;
    PHead->val=0; 
    return PHead;
}

// insert the val to the head of single list 
PNode Single_InsertListHead(PNode PHead,int InsertVal)
{
    if(PHead==NULL){
        printf ("Please init the list first!");
        return NULL;
    }
    PNode PNew;
    PNew=(PNode)malloc(sizeof(Node));
    if (PNew==NULL){
        printf ("malloc phew failed!");
        exit(-1);
    }
    PNew->val=InsertVal;
    PNew->next=PHead->next;
    PHead->next=PNew;
    PHead->val++;
    return PHead;
}

// insert the val to the end of single list 
PNode Single_InsertListEnd(PNode PHead,int InsertVal)
{
    if(PHead==NULL){
        printf ("Please init the list first!");
        return NULL;
    }
    PNode PNew,PTail=PHead;
    while (PTail->next!=NULL){
        PTail=PTail->next;
    }
    PNew=(PNode)malloc(sizeof(Node));
    if (PNew==NULL){
        printf ("malloc PNew failed!");
        exit(-1);
    }
    PNew->val=InsertVal;
    PNew->next=NULL;
    PTail->next=PNew;
    PHead->val++;
    return PHead;
}

// insert the val to the assign location of single list 
void Single_InsertAsgnList(PNode PHead,int InsertLoc,int InsertVal)
{ int i; PNode PNew; PHead->val++; for(i=0;i<InsertLoc;i++)
        PHead=PHead->next;
    PNew=(PNode)malloc(sizeof(Node));
    PNew->val=InsertVal;
    PNew->next=PHead->next;
    PHead->next=PNew;
}

// delete the assign node 
void Single_DeleteNode(PNode PHead,int Deleteloc)
{
    int i;
    PNode PTmp;
    PHead->val--;
    for(i=1;i<Deleteloc;i++)
        PHead=PHead->next;
    PTmp=PHead->next;
    PHead->next=PTmp->next;
    free(PTmp);
}

// Print the single list
void Single_PrintList(PNode PHead)
{
    printf ("The length of the list is %d\n",PHead->val);
    if (PHead->next==NULL)
        return;
    PHead=PHead->next;
    while (PHead->next!=NULL){
        printf ("%d ",PHead->val);
    PHead=PHead->next;
    }
    printf ("%d\n",PHead->val);
}

// Read the list from the file List.data
void Single_ReadList(PNode PHead)
{
    char filename[20]="List.data";
    FILE *WFile =fopen(filename,"r");
    int tmp;
    PNode PNew;
    if(fscanf(WFile,"%d",&tmp)!=EOF)
    {
        PHead->val=tmp;
    }
    while(fscanf(WFile,"%d",&tmp)!=EOF)
    {
        PNew=(PNode)malloc(sizeof(Node));
        PNew->val=tmp;
        PNew->next=NULL;
        PHead->next=PNew;
        PHead=PNew;
    }
    fclose(WFile);
}

// Write the list to the file List.data
void Single_WriteList(PNode PHead)
{
    char filename[20]="List.data";
    PNode PTmp=PHead;
    FILE *WFile =fopen(filename,"w");
    while (PTmp->next!=NULL)
    {
        fprintf(WFile,"%d ",PTmp->val);
        PTmp=PTmp->next;
    }
    fprintf(WFile,"%d\n",PTmp->val);
    fclose (WFile);
}

// Free the list
int Single_FreeList(PNode PHead)
{
    PNode FreeP;
    while (PHead->next!=NULL)
    {
        FreeP=PHead;
        PHead=PHead->next;
        free(FreeP);
    }
    free(PHead);
}
