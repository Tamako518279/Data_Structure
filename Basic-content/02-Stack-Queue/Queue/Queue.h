#ifndef QUEUE_H
#define QUEUE_H
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef struct 
{
    QElemType *base;   //存储空间的基地址
    int front;        //头指针
    int rear;         //尾指针
}SqQueue;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
Status InitQueue_Sq(SqQueue *Q);
int QueueLength_Sq(SqQueue Q);
Status EnQueue_Sq(SqQueue *Q,QElemType e);
Status DeQueue_Sq(SqQueue *Q,QElemType *e);
QElemType GetHead_Sq(SqQueue Q);
Status InitQueue_Link(LinkQueue *Q);
Status EnQueue_Link(LinkQueue *Q,QElemType e);
Status DeQueue_Link(LinkQueue *Q,QElemType *e);
QElemType GetHead_Link(LinkQueue Q);
#endif