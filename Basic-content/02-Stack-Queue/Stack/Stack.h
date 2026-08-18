#ifndef STACK_H
#define STACK_H
typedef int SElemType;
typedef int Status;
typedef int ElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
#define ERROR 0
#define OK 1
#define MAXSIZE 100
Status InitStack_Sq(SqStack *S);
Status Push_Sq(SqStack *S,SElemType e);
Status Pop_Sq(SqStack *S,SElemType *e);
SElemType GetTop_Sq(SqStack S);
Status InitStack_Link(LinkStack *S);
Status Push_Link(LinkStack *S,SElemType e);
Status Pop_Link(LinkStack *S,SElemType *e);
SElemType GetTop_Link(LinkStack S);

#endif