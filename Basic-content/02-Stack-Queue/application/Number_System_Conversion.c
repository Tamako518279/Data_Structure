#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Stack/Stack.h"
void Conversion(SElemType N, int div);
SElemType StackEmpty(SqStack S);


int main()
{
    Conversion(100,8);
    return 0;
    
}


void Conversion(SElemType N,int div)
{
    SqStack S;SElemType e;
    InitStack_Sq(&S);
    while(N)
    {
        Push_Sq(&S,N%div);
        N = N/div;
    }

    while(!StackEmpty(S))
    {
    Pop_Sq(&S,&e);
    printf("%d",e);
    }
}

    SElemType StackEmpty(SqStack S)
    {
        if(S.base == S.top)  return 1;
        else         return 0;
    }

