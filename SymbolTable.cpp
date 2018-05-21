#include "SymbolTable.h"

int symTable::assignVal(variableNode v)
{
    variableNode* assignNode;
    if(assignNode = lookupVar(v.name))
    {
        if(assignNode->is_const)
        {
            printf("error: this is const value can't modify");
            return 0;
        }
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
        //dumpTable();    
    }
}

symTable::symTable()
{
    myTable.push_back(tableNode());
}

arrayNode *symTable::lookupArr(char *name)
{
    std::vector<tableNode>::reverse_iterator tableBegin;
    std::vector<arrayNode>::iterator arrayBegin;
    for(tableBegin = myTable.rbegin();tableBegin!=myTable.rend();tableBegin++)
    {
        for(arrayBegin = tableBegin->arrNode.begin();arrayBegin!= tableBegin->arrNode.end();arrayBegin++)
        {
            if(!strcmp(arrayBegin->name, name))
            {
                return (&*arrayBegin);
            }
        }
    }
    return NULL;    
}

int symTable::assignArr(int index,variableNode v)
{
    arrayNode *aNode = lookupArr(v.name);
    if(aNode != NULL)
    {
        if(v.val_Type == VAL_INT)
        {   
            if(index >= aNode->array.arr_int.size())
            {
                std::cout<<"assign array error"<<std::endl;
                return 0;
            }
            aNode->array.arr_int[index] = v.data.val_int;
            std::cout<<v.data.val_int<<std::endl;
        }
        else if(v.val_Type == VAL_FLOAT)
        {   
            if(index >= aNode->array.arr_float.size())
            {
                std::cout<<"assign array error"<<std::endl;
                return 0;
            }
            aNode->array.arr_float[index] = v.data.val_float;

        }
        else if(v.val_Type == VAL_BOOL)
        {
               
            if(index >= aNode->array.arr_flag.size())
            {
                std::cout<<"assign array error"<<std::endl;
                return 0;
            }
            aNode->array.arr_flag[index] = v.data.val_flag;
        }
        else if(v.val_Type == VAL_STR)
        {   
            if(index >= aNode->array.arr_str.size())
            {
                std::cout<<"assign array error"<<std::endl;
                return 0;
            }
            aNode->array.arr_str[index] = v.data.val_str;
            
        }
        std::cout<<"assign array success"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"declared error"<<std::endl;
        return 0;
    }
}
int symTable::var_declare(variableNode v)
{
    variableNode* sameArr = lookupVar_for_declare(v.name);
    if(sameArr == NULL)
    {
        myTable.back().varNode.push_back(v);
        std::cout << "--------------------------------------------\n"<<"PUSH variable => name = "<< v.name<<std::endl<<"--------------------------------------------"<<std::endl;  
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
        //dumpTable();   
        return 1;
    }
}
int symTable::func_declare(variableNode v)
{
    variableNode* sameArr = lookupFunc(v.name);
    if(sameArr == NULL)
    {
        myFunc.push_back(v);
        //dumpTable();   
        std::cout <<"--------------------------------------------\n"<< "PUSH function => name = "<< v.name<<std::endl<<"--------------------------------------------"<<std::endl;  
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
        //dumpTable();   
        return 1;
    }
}
int symTable::array_declare(int type,int num,char* vName)
{
    arrayNode a;
    a.val_Type = type;
    a.name =vName;
    std::cout << "--------------------------------------------\n"<<"PUSH array => name = "<< vName<<std::endl<< "--------------------------------------------"<<std::endl;  
    if(a.val_Type == VAL_INT)
    {
        for(int i =0;i<num;i++)
            a.array.arr_int.push_back(0);
    }
    else if(a.val_Type == VAL_FLOAT)
    {
        for(int i =0;i<num;i++)
            a.array.arr_float.push_back(0);
    }
    else if(a.val_Type == VAL_STR)
    {
        for(int i =0;i<num;i++)
            a.array.arr_str.push_back(NULL);
    }   
    else if(a.val_Type == VAL_BOOL)
    {
        for(int i =0;i<num;i++)
            a.array.arr_float.push_back(true);
    }
    
    myTable.back().arrNode.push_back(a);
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

            if(variableBegin->val_Type == VAL_INT)
            {
                std::cout<< "INT"<< "   value = " << variableBegin->data.val_int<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_FLOAT)
            {
                std::cout<< "FLOAT"<< "   value = " << variableBegin->data.val_float<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_STR)
            {
                std::cout<< "STR"<< "   value = " << variableBegin->data.val_str<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_BOOL)
            {
                std::cout<< "BOOL"<< "   value = " << variableBegin->data.val_flag<<std::endl;
            }
        }

        for(arrBegin = tableBegin->arrNode.begin();arrBegin != tableBegin->arrNode.end();arrBegin++)
        {
            std::cout << "array =>";
            switch(arrBegin->val_Type){
                case 0:
                     std::cout<<" name = " << arrBegin->name <<"  type = NULL";
                    break;
                case 1:
                    for(int i = 0;i<arrBegin->array.arr_int.size();i++)
                    {
                        std::cout<<std::endl<<" name = " << arrBegin->name <<"  type = INT  value = "<<arrBegin->array.arr_int[i];
                    }
                    break;
                case 2:
                    for(int i = 0;i<arrBegin->array.arr_flag.size();i++)
                    {
                        std::cout<<std::endl<<" name = " << arrBegin->name <<"  type = BOOL  value = "<<arrBegin->array.arr_flag[i];;
                    
                    }
                    break;
                case 3:
                    for(int i = 0;i<arrBegin->array.arr_str.size();i++)
                    {
                        std::cout<<std::endl<<" name = " << arrBegin->name <<"  type = STR  value = "<< arrBegin->array.arr_str[i];;
                    
                    }
                    break;
                case 4:
                    
                    for(int i = 0;i<arrBegin->array.arr_float.size();i++)
                    {
                        std::cout<<std::endl<<" name = " << arrBegin->name <<"  type = FLOAT  value = "<<arrBegin->array.arr_float[i];;
                        
                    }
                    
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
    std::vector<tableNode>::iterator tableBegin = myTable.end()-1;

    std::vector<variableNode>::iterator variableBegin;
    std::vector<arrayNode>::iterator arrBegin;
    std::cout<<"-----------------------------------------"<<std::endl;
    if(tableBegin->varNode.size() !=0){
        for(variableBegin = tableBegin->varNode.begin();variableBegin != tableBegin->varNode.end();variableBegin++)
        {
            std::cout << "POP variable => name = "<< variableBegin->name<<"   type = ";

            if(variableBegin->val_Type == VAL_INT)
            {
                std::cout<< "INT"<< "   value = " << variableBegin->data.val_int<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_FLOAT)
            {
                std::cout<< "FLOAT"<< "   value = " << variableBegin->data.val_float<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_STR)
            {
                std::cout<< "STR"<< "   value = " << variableBegin->data.val_str<<std::endl;
            }
            else if(variableBegin->val_Type == VAL_BOOL)
            {
                std::cout<< "BOOL"<< "   value = " << variableBegin->data.val_flag<<std::endl;
            }
        }

        for(arrBegin = tableBegin->arrNode.begin();arrBegin != tableBegin->arrNode.end();arrBegin++)
        {
            std::cout << "POP array => name = ";
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
    else
        std::cout << "Nothing pop"<<std::endl;
    std::cout<<"-----------------------------------------"<<std::endl;
    myTable.pop_back();
}
