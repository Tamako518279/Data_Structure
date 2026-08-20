#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Status InitQueue_Sq(SqQueue *Q)
{
    Q->base = malloc(MAXQSIZE * sizeof(QElemType));
    if(!(Q->base))    exit(ERROR);
    Q->front = Q->rear = 0;
    return OK;
}


int QueueLength_Sq(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE)% MAXQSIZE;
}

Status EnQueue_Sq(SqQueue *Q,QElemType e)
{
    if((Q->rear + 1) % MAXQSIZE == Q->front)
    return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue_Sq(SqQueue *Q,QElemType *e)
{
  if(Q->front == Q->rear)  return ERROR;
  *e = Q->base[Q->front];
  Q->front = (Q->front + 1) % MAXQSIZE;
  return OK;
}

QElemType GetHead_Sq(SqQueue Q)
{
   if(Q.front != Q.rear)
   return Q.base[Q.front];
}

Status InitQueue_Link(LinkQueue *Q)
{
    (*Q).front = (*Q).rear = malloc(sizeof(QNode));
    (*Q).front->next = NULL;
    return OK;
}

Status EnQueue_Link(LinkQueue *Q,QElemType e)
{
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;(*Q).rear->next = p;
    (*Q).rear = p;
}

Status DeQueue_Link(LinkQueue *Q,QElemType *e)
{
    if((*Q).front == (*Q).rear)   return ERROR;
    QNode *p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;
    if((*Q).rear == p)
    (*Q).rear = (*Q).front;
    free(p);
    return OK;
}

QElemType GetHead_Link(LinkQueue Q)
{
    if(Q.front != Q.rear)
    return Q.front->next->data;
}





