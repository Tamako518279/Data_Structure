#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Queue.h"

int main()
{
    SqQueue Q1;
    InitQueue_Sq(&Q1);
    if(!Q1.base)  return ERROR;
    QElemType e1;
    for(e1 = 1;e1 <= 3;e1++)
    {
        EnQueue_Sq(&Q1,e1);
    }
    QElemType e2 = GetHead_Sq(Q1);
    QElemType e3;
    DeQueue_Sq(&Q1,&e3);
    printf("%d %d\n",e2,e3);
    printf("%d\n",GetHead_Sq(Q1));


    LinkQueue Q2;
    InitQueue_Link(&Q2);
    if(!Q2.front)  return ERROR;
    QElemType e4;
    for(e4 = 1;e4 <= 3;e4++)
    {
        EnQueue_Link(&Q2,e4);
    }
    QElemType e5 = GetHead_Link(Q2);
    QElemType e6;
    DeQueue_Link(&Q2,&e6);
    printf("%d %d\n",e5,e6);
    printf("%d\n",GetHead_Link(Q2));
}