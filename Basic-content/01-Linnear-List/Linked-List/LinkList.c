#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"



Status InitList(LinkList *L)
{
    if(L == NULL) return ERROR;
    *L = malloc(sizeof(**L));
    if(*L == NULL) return ERROR;
    (*L)->next = NULL;
    return OK;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    LNode *p;
    p = L->next;
    int j = 1;
    while(p && j < i)
    {
        j++;
        p = p->next;
    }
    if(!p || j>i) return ERROR;
    *e = p->data;
    return OK;
}

LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p;
    p = L->next;
    while(p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

Status ListInsert(LinkList *L,int i,ElemType e)
{
    LNode *p = *L;
    int j = 0;
    while(p && j < i-1)
    {
        j++;
        p = p->next;
    }
    if(!p || j > i - 1)  return ERROR;
     LNode *s = malloc(sizeof **L);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;

}

Status ListDelete(LinkList *L,int i)
{
    LNode *p = *L;
    int j = 1;
    while((p->next) && (j < i))
    {
        p=p->next;
        j++;
    }
    if(!(p->next) || (j > i)) return ERROR;
    LNode *q = p->next;
    p->next = p->next->next;
    free(q);
    return OK;

}

void CreateList_H(LinkList *L,int n)
{
    *L = malloc(sizeof(LNode));
    (*L)->next = NULL;
    int i;LNode *p;
    for(i = 0;i < n;i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateList_R(LinkList *L,int n)
{
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    int i;LNode *p,*r;
    r = *L;
    for(i = 0;i < n;i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

DuLNode* GetElem_DuL(DuLinkList *L,int i)
{
    int j = 0;
    DuLNode *p = (*L)->next;
    while(p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    return p;
}

Status ListInsert_DuL(DuLinkList *L,int i,ElemType e)
{
   DuLNode *p;
   p = GetElem_DuL(L,i);
   if(!p)  return ERROR;
   DuLNode *s = (DuLNode*)malloc(sizeof(DuLNode));
   s->data = e;
   s->prior = p->prior;
   s->next = p;
   p->prior->next = s;
   p->prior = s;
   return OK;
}

Status ListDelete_DuL(DuLinkList *L,int i)
{
    DuLNode *p; 
    if(!(p = GetElem_DuL(L,i))) return ERROR;
    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
    return OK;
}

void MergeList_L(LinkList *LA,LinkList *LB,LinkList *LC)
{
    LNode *pa,*pb,*pc;
    pa = (*LA)->next;pb = (*LB)->next;
    LC = LA;
    pc = *LC;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc ->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if(pa) pc->next = pa;
    else pc->next = pb;
    //等价写法为pc->next = pa?pa:pb;
    free(LB);
}

void CreatePolyn(Polynomial *p,int n)
{
    *p = (Polynomial)malloc(sizeof(Polynomial));
    int i;PNode *s,*q,*pre;
    for(i = 0;i < n;i++)
    {
        s = (PNode*)malloc(sizeof(PNode*));
        scanf("%d %d",s->coef,s->expn);
        pre = *p;
        q = (*p)->next;
        while(q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre ->next = s;
    }
    
}

void AddPolyn(Polynomial *Pa,Polynomial *Pb)
{
    PNode *p1,*p2,*p3;
    p1 = *Pa;p2 = *Pb;
    p3 = p1;
    p1 = p1->next;p2 = p2->next;
    int sum;PNode *r;
    while(p1 && p2)
    {
      if(p1->expn == p2->expn)
      {
         sum = p1->coef +p2->coef;
         if(sum!=0)
         {
            p1->coef = sum;
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
            r = p2;
            p2 = p2->next;
            free(r);
         }
         else
         {
            r = p1;p1 = p1->next;free(r);
            r = p2;p2 = p2->next;free(r);
         }
      }
      else if(p1->expn < p2->expn)
      {
         p3->next = p1;
         p3 = p1;
         p1 = p1->next;
        
      }
      else
      {
        p3->next = p2;
        p3 = p2;
        p2 = p2->next;
      }
      
    }
    p3 = p1?p1:p2;
    free(Pb);
}













