#include"MySymbolTable.h"

#define token(t) printf("<%s>\n",t)
#define tokenInteger(t,i) printf("<%s:%d>\n","t",atoi(i));
#define tokenString(t,s) LIST; printf("<%s:%s>\n",t,s);
int main()
{
    // SymDataNode *a;
    // a = CreateTable();
    // InsertTable(a,"qwerwq");

    // InsertTable(a,"aaaqq");

    // InsertTable(a,"bbbbbbqwerwq");

    // int b= LookupTable(a,"qwerwq");

    // int c= LookupTable(a,"bbbbbbqwerwq");
    
    // int d= LookupTable(a,"bbbbbrwq");

    // printf("%d %d %d" , b,c,d);
    // DumpTable(a);


    token("'('");
}