#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    char* name;
    union{
        char *val_str;
        int  val_int;
        bool val_flag;
        float val_float;
    };


    struct VNode* next;
}VNode;

typedef struct {
    VNode *varNode;
    struct TNode* next;
}TNode;

VNode* CreateVNode(){
    VNode* node;
    node = (VNode)malloc(sizeof(VNode));
    node->next =NULL;
    return node;
}
VNode* CreateTNode(){
    VNode* node;
    node = (Tnode* )malloc(sizeof(Tnode));
    node->next =NULL;
    return node;
}

Tnode* CreateTable(){
    Tnode* myFirstTable;
    myFirstTable = CreateTNode();
    myFirstTable->varNode = CreateVNode();
    return myFirstTable;
}

int LookupTable(TNode* myFirstTable,char* s){
    TNode *nowTable = myFirstTable ;
    for(;nowTable->next !=NULL;)
        nowTable=nowTable->next;
    
    Vnode* lnode = nowTable->varNode->next;//first node don' have data
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
    int flag = LookupTable(myFirstNode,s);
    int i;
    if(flag<0){
        SymDataNode* lnode = myFirstNode;
        for(i = -1;lnode->next!=NULL;i++){
            lnode = lnode->next;
        }
        SymDataNode* temp = (SymDataNode*) malloc(sizeof(SymDataNode));
        temp->name = CopyString(s);
        temp->next = NULL;
        lnode->next = temp;
        return i+1; 
    }
    return flag;
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