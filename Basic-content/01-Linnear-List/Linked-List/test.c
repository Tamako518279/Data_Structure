#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
    LinkList L;
    
    if(InitList(&L) == ERROR) printf("ERROR\n");
    int i;
    for(i = 1;i <=5;i++)
    {
        ListInsert(&L,i,i);
    }
    ElemType e;
    Status s = GetElem(L,2,&e);
    if(s == ERROR)  printf("ERROR\n");
    else
    {
        if(e == 2)
        printf("The result is correct\n");
        else
        printf("The result is wrong\n");
    }



}