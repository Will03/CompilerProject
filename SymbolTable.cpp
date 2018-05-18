#include "SymbolTable.h"

int main()
{
    symTable a;
    variableNode v(1,1,"aaaa");
    a.declare(v);
    a.declare(v);
    variableNode q(1,1,"aahaa");
    a.declare(q);
    variableNode o(1,21,"aahaa");
    a.assignVal(o);
    a.dumpTable();
}