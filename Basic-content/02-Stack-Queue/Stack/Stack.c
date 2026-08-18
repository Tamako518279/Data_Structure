#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Stack.h"



Status InitStack_Sq(SqStack *S)
{
    if(S == NULL)  return ERROR;
    S->base = malloc(MAXSIZE * sizeof(SElemType)); 
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return OK;
}

Status Push_Sq(SqStack *S,SElemType e)
{
    if(S->top - S->base == S->stacksize)  return ERROR;
    *(S->top++) = e;
    return OK;
}

Status Pop_Sq(SqStack *S,SElemType *e)
{
    if(S->top == S->base)  return ERROR;
    *e = *(--S->top);
    return OK;
}

SElemType GetTop_Sq(SqStack S)
{
    if(S.top != S.base)
    return *(S.top - 1);
}

Status InitStack_Link(LinkStack *S)
{
    *S = NULL;
    return OK;
}

Status Push_Link(LinkStack *S,SElemType e)
{
    StackNode *p = malloc(sizeof(StackNode));
    p->data = e;
    p->next = *S;
    *S = p;
    return OK;
}

Status Pop_Link(LinkStack *S,SElemType *e)
{
    if(*S == NULL) return ERROR;
    *e = (*S)->data;
    StackNode *p = *S;
    *S = (*S)->next;
    free(p);
    return OK;

}

SElemType GetTop_Link(LinkStack S)
{
    if(S == NULL)  return ERROR;
    else return S->data;
}



