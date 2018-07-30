#include <stdio.h>
#include <stdlib.h>
#include "List_xy.h"
#include <malloc.h>

int main(int argc,char **argv)
{
    PNode PHead;
    int GetcharTmp,InsertVal,InsertLoc,DeleteLoc;
    PHead=Single_InitList(PHead);

    //  loop begin
    while(1){
        system("clear");
        Single_PrintList(PHead);
        InsertLoc=-1;
        DeleteLoc=-1;
        printf("\n");
        printf("Please choose what to do:\n");
        printf("h Insert a value to the head of list.\n");
        printf("e Insert a value to the end of list.\n");
        printf("i Insert a value to the asign location.\n");
        printf("d Delete the asign location node.\n");
        printf("r Read from the file list.data\n");
        printf("w Write the list to the file list.data\n");
        printf("q end\n");
        GetcharTmp=getchar();
        switch(GetcharTmp)
        {
        case 'h':
            printf("Please input the val to insert to the head of th list:");
            scanf("%d",&InsertVal);
            PHead=Single_InsertListHead(PHead,InsertVal);
            break;
        case 'e':
            printf("Please input the val to insert to the end of th list:");
            scanf("%d",&InsertVal);
            PHead=Single_InsertListEnd(PHead,InsertVal);
            break;
        case 'i':
            while (InsertLoc<0||InsertLoc>PHead->val)
            {
                printf("Where do you want to insert?\nNext to the ?th(more the 0 and less then %d):",PHead->val+1);
                scanf("%d",&InsertLoc);
            }
            printf("Please input the val to insert:");
            scanf("%d",&InsertVal);
            Single_InsertAsgnList(PHead,InsertLoc,InsertVal);
            break;
        case 'd':
            if(!PHead->val)
            {
                printf("Please create or read a list first!");
                GetcharTmp=getchar();
                break;
            }
            while (DeleteLoc<=0||DeleteLoc>PHead->val)
            {
                printf("Which one do you want to delete?\nthe ?th(more the 1 and less then %d):",PHead->val+1);
                scanf("%d",&DeleteLoc);
            }
            Single_DeleteNode(PHead,DeleteLoc);
            break;
        case 'r':
            Single_ReadList(PHead);
            break;
        case 'w':
            Single_WriteList(PHead);
            break;
        case 'q':
            Single_FreeList(PHead);
            exit(0);
        }
    }
    return 0;
}
