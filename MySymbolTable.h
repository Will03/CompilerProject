#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct DNode{
    char* name;
    struct DNode* next;
}SymDataNode;

SymDataNode* CreateTable(){
    SymDataNode* myFirstNode;
    myFirstNode = (SymDataNode* )malloc(sizeof(SymDataNode));
    return myFirstNode;
}

int LookupTable(SymDataNode* myFirstNode,char* s){
    SymDataNode* lnode = myFirstNode->next;//first node don' have data
    for(int i =0;lnode!=NULL;i++){
        if(!strcmp(lnode->name ,s))
        {
            return i;
        }
        lnode = lnode->next;
    }
    return -1;
}
char *CopyString(char *s)
{
    char *copyS = (char*)malloc(sizeof(strlen(s))+1);
    strcpy(copyS, s);
    return copyS; 
}
int InsertTable(SymDataNode* myFirstNode, char* s){
    // int flag = LookupTable(myFirstNode,s);
    // if(flag<0){}
        SymDataNode* lnode = myFirstNode;
        for(int i = 0;lnode->next!=NULL;i++){
            lnode = lnode->next;
        }
        SymDataNode* temp = (SymDataNode*) malloc(sizeof(SymDataNode));
        temp->name = CopyString(s);
        temp->next = NULL;
        lnode->next = temp;
    
}
int DumpTable(SymDataNode* myFirstNode){
    SymDataNode* lnode = myFirstNode->next;//first node don' have data
    printf("Symbol Table:\n");
    for(int i =0;lnode!=NULL;i++){
        printf("%s\n",lnode->name);
        lnode = lnode->next;
    }
    return 1;
}