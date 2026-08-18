#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>

int main()
{
    SqStack S1;
    if(InitStack_Sq(&S1) == ERROR)  printf("ERROR\n");
    Push_Sq(&S1,1);Push_Sq(&S1,1);
    int e ; 
    Pop_Sq(&S1,&e);
    printf("%d %d\n",e,GetTop_Sq(S1));

    LinkStack S2;
    InitStack_Link(&S2);
    if(S2 != NULL)  printf("ERROR");
    Push_Link(&S2,2);Push_Link(&S2,2);
    int s;
    Pop_Link(&S2,&s);
    printf("%d %d\n",s,GetTop_Link(S2));


}