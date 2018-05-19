#include <iostream>
#include <vector>
#include <string>
#include "string.h"
typedef union{
    char *val_str;
    int  val_int;
    bool val_flag;
    float val_float;
}varData;

typedef struct{
    std::vector<int> arr_int;
    std::vector<bool> arr_flag;
    std::vector<float> arr_float;
    std::vector<char *> arr_str;
}arrData;

enum Type_enum{VAL_NULL = 0,VAL_INT , VAL_BOOL, VAL_STR, VAL_FLOAT, VAL_REAL};
struct arrayNode{
    arrData array;
    int val_Type; 
    char *name;
};

struct variableNode{
    char* name;
    varData data;
    // int => 0 = T_INT bool => 1 = T_BOOL string => 3 = T_STR real => 3 = T_REAL
    int val_Type; 
    bool is_const;
    variableNode(int type,int value, char* vName,bool v_const){
        data.val_int = value;
        val_Type = type;
        name = vName;
        is_const = v_const;
    }
    variableNode(int type,float value,char* vName,bool v_const){
        data.val_float = value;
        val_Type = type;
        name = vName;
        is_const = v_const;
    }
    variableNode(int type,bool value,char* vName,bool v_const){
        data.val_flag = value;
        val_Type = type;
        name = vName;
        is_const = v_const;
    }
    variableNode(int type,char* value,char* vName,bool v_const){
        data.val_str = value;
        val_Type = type;
        name = vName;
        is_const = v_const;
    }
    variableNode(int type,char* vName,bool v_const){
        val_Type = type;
        name = vName;
        is_const = v_const;
    }

};

typedef struct {
    std::vector <variableNode> varNode;
    std::vector<arrayNode> arrNode;
}tableNode;

class symTable
{
public:
    symTable();
  //  ~symTable();
    variableNode *lookupVar(char *name);
    variableNode *lookupVar_for_declare(char *name);
    variableNode *lookupFunc(char *name);
    int var_declare(variableNode v);
    int func_declare(variableNode v);
    int array_declare(int type,int num,char* vName);
    int assignVal(variableNode v);
    int dumpTable();
    void pushTable();
	void popTable();
private:
    std::vector <tableNode> myTable;
    std::vector <variableNode> myFunc;

};

int symTable::assignVal(variableNode v)
{
    variableNode* assignNode;
    if(assignNode = lookupVar(v.name))
    {
        if(v.val_Type == assignNode->val_Type)
        {
            if(v.val_Type == VAL_INT)
            {
                assignNode->data.val_int = v.data.val_int;
            }
            else if(v.val_Type == VAL_BOOL)
            {
                assignNode->data.val_flag = v.data.val_flag;
            }
            else if(v.val_Type == VAL_FLOAT)
            {
                assignNode->data.val_float = v.data.val_float;
            }
            else if(v.val_Type == VAL_STR)
            {
                assignNode->data.val_str = v.data.val_str ;
            }
        }
        else if(v.val_Type == VAL_BOOL && assignNode->val_Type== VAL_INT)
        {
            assignNode->data.val_int = (v.data.val_flag?1:0);
        }
        else {
            printf("can't change type\n");
        }
        dumpTable();    
    }
}

symTable::symTable()
{
    myTable.push_back(tableNode());
}

int symTable::var_declare(variableNode v)
{
    variableNode* sameArr = lookupVar_for_declare(v.name);
    if(sameArr == NULL)
    {
        myTable.back().varNode.push_back(v);
        dumpTable();   
        return 1;
    }
    else{
        std::cout<<"this name is allready define"<<std::endl;
        if(v.val_Type == VAL_INT)
        {
            sameArr->data.val_int = v.data.val_int;
        }
        else if(v.val_Type == VAL_FLOAT)
        {
            sameArr->data.val_float = v.data.val_float;
        }
        else if(v.val_Type == VAL_BOOL)
        {
            sameArr->data.val_flag = v.data.val_flag;
        }
        else if(v.val_Type == VAL_STR)
        {
            sameArr->data.val_str = v.data.val_str;
        }
        sameArr->val_Type = v.val_Type;
        dumpTable();   
        return 1;
    }
}
int symTable::func_declare(variableNode v)
{
    variableNode* sameArr = lookupFunc(v.name);
    if(sameArr == NULL)
    {
        myFunc.push_back(v);
        dumpTable();   
        return 1;
    }
    else{
        std::cout<<"this name is allready define"<<std::endl;
        if(v.val_Type == VAL_INT)
        {
            sameArr->data.val_int = v.data.val_int;
        }
        else if(v.val_Type == VAL_FLOAT)
        {
            sameArr->data.val_float = v.data.val_float;
        }
        else if(v.val_Type == VAL_BOOL)
        {
            sameArr->data.val_flag = v.data.val_flag;
        }
        else if(v.val_Type == VAL_STR)
        {
            sameArr->data.val_str = v.data.val_str;
        }
        sameArr->val_Type = v.val_Type;
        dumpTable();   
        return 1;
    }
}
int symTable::array_declare(int type,int num,char* vName)
{
    arrayNode a;
    a.val_Type = type;
    a.name =vName;
    if(a.val_Type = VAL_INT)
    {
        for(int i =0;i<num;i++)
            a.array.arr_int.push_back(0);
    }
    else if(a.val_Type = VAL_FLOAT)
    {
        for(int i =0;i<num;i++)
            a.array.arr_float.push_back(0);
    }
    else if(a.val_Type = VAL_STR)
    {
        for(int i =0;i<num;i++)
            a.array.arr_str.push_back(NULL);
    }   
    else if(a.val_Type = VAL_BOOL)
    {
        for(int i =0;i<num;i++)
            a.array.arr_float.push_back(true);
    }
    myTable.back().arrNode.push_back(a);
    dumpTable();
    return 1;
}

int symTable::dumpTable(){
    int index =0;
    std::vector<tableNode>::iterator tableBegin;
    std::vector<variableNode>::iterator variableBegin;
    std::vector<variableNode>::iterator funcBegin;
    std::vector<arrayNode>::iterator arrBegin;
    
    std::cout<<"--------------------------------------------"<<std::endl;
    for(funcBegin = myFunc.begin();funcBegin!= myFunc.end();funcBegin++)
    {
        std::cout << "Function => name = ";
            std::cout << funcBegin->name;
            std::cout << "   type = ";
            switch(funcBegin->val_Type){
                case 0:
                    std::cout<< "NULL";
                    break;
                case 1:
                    std::cout<< "INT";
                    break;
                case 2:
                    std::cout<< "BOOL";
                    break;
                case 3:
                    std::cout<< "STR";
                    break;
                case 4:
                    std::cout<< "FLOAT";
                    break;
            }
            std::cout<<std::endl;
    }
    std::cout<<"------------------------------------------"<<std::endl;
    for(tableBegin = myTable.begin();tableBegin!=myTable.end();tableBegin++)
    {
        std::cout<<"table"<<index<<std::endl;
        index+=1;
        for(variableBegin = tableBegin->varNode.begin();variableBegin != tableBegin->varNode.end();variableBegin++)
        {
            std::cout << "variable => name = "<< variableBegin->name<<"   type = ";
            switch(variableBegin->val_Type){
                case 0:
                    std::cout<< "NULL";
                    break;
                case 1:
                    std::cout<< "INT";
                    break;
                case 2:
                    std::cout<< "BOOL";
                    break;
                case 3:
                    std::cout<< "STR";
                    break;
                case 4:
                    std::cout<< "FLOAT";
                    break;
            }
            if(variableBegin->val_Type == VAL_INT)
            {
                std::cout<< "   value = " << variableBegin->data.val_int<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_FLOAT)
            {
                std::cout<< "   value = " << variableBegin->data.val_float<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_STR)
            {
                std::cout<< "   value = " << variableBegin->data.val_str<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_BOOL)
            {
                std::cout<< "   value = " << variableBegin->data.val_flag<<std::endl;
            }
        }

        for(arrBegin = tableBegin->arrNode.begin();arrBegin != tableBegin->arrNode.end();arrBegin++)
        {
            std::cout << "array => name = ";
            std::cout << arrBegin->name;
            std::cout << "   type = ";
            switch(arrBegin->val_Type){
                case 0:
                    std::cout<< "NULL";
                    break;
                case 1:
                    std::cout<< "INT";
                    break;
                case 2:
                    std::cout<< "BOOL";
                    break;
                case 3:
                    std::cout<< "STR";
                    break;
                case 4:
                    std::cout<< "FLOAT";
                    break;
            }
            std::cout<<std::endl;
        }
    }
    
    std::cout<<"--------------------------------------------"<<std::endl;
    
}

variableNode *symTable::lookupVar(char *name)
{
    std::vector<tableNode>::reverse_iterator tableBegin;
    std::vector<variableNode>::iterator variableBegin;
    for(tableBegin = myTable.rbegin();tableBegin!=myTable.rend();tableBegin++)
    {
        for(variableBegin = tableBegin->varNode.begin();variableBegin!= tableBegin->varNode.end();variableBegin++)
        {
            if(!strcmp(variableBegin->name, name))
            {
                return (&*variableBegin);
            }
        }
    }
    return NULL;

}

variableNode *symTable::lookupVar_for_declare(char *name)
{
    std::vector<tableNode>::iterator tableBegin = myTable.end()-1;

    std::vector<variableNode>::iterator variableBegin;
    if(tableBegin->varNode.size() !=0){
        for(variableBegin = tableBegin->varNode.begin();variableBegin!=tableBegin->varNode.end();variableBegin++)
        {
            if(!strcmp(variableBegin->name, name))
            {
                return  (&*variableBegin);
            }
        }
    }
        
    return NULL;

}

variableNode *symTable::lookupFunc(char *name)
{

    std::vector<variableNode>::iterator funcBegin;
    funcBegin = myFunc.begin();
    if(myFunc.size() !=0){
        for(;funcBegin!=myFunc.end();funcBegin++)
        {
            if(funcBegin->name == name)
            {
                return  (&*funcBegin);
            }
        }
    }
        
    return NULL;

}

void symTable::pushTable()
{
    myTable.push_back(tableNode());
}
void symTable::popTable()
{
    myTable.pop_back();
}
