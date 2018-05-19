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

