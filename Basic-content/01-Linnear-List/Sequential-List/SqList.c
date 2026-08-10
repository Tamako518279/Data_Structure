#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"


Status InitList(SqList *L)
{
    L->Elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    return OK;
}

Status GetElem(SqList L,int i,ElemType *e)
{
    if(i < 1 || i > L.length)
    return ERROR;
    else
    {
        *e = L.Elem[i-1];
         return OK;
    }
}

int LocateElem(SqList L,ElemType e)
{
    int i = 0;
    while(i < L.length && L.Elem[i] != e)
    {
        i++;
    }
     if(i >= L.length)
    {
        return ERROR;
    }
    else
    {
        return i + 1;
    }

}

Status ListInsert(SqList *L,int i,ElemType e)
{
  if(i < 1 || i > L->length + 1) return ERROR;
  if (L->length == MAXSIZE) return ERROR;
    int j;
       for(j = L->length - 1;j >= i - 1;j--)
      {
         (*L).Elem[j+1] = (*L).Elem[j];
      }
      (*L).Elem[i - 1] = e;
      L->length ++;
      return OK;
}

Status ListDelete(SqList *L,int i)
{
    if(i < 1 || i > L->length) return ERROR;
    int j;
    for(j = i;j <= L->length - 1;j++)
    {
        L->Elem[j - 1] = L->Elem[j];
    }
    L->length--;
    return OK;
}

void MergeList_Sq(SqList LA,SqList LB,SqList *LC)
{
    LC->length = LA.length + LB.length;
    LC->Elem = (ElemType *) malloc (LC->length * sizeof(ElemType));
    ElemType *pa,*pb,*pc,*pa_last,*pb_last;
    pc = LC->Elem; pa = LA.Elem; pb = LB.Elem;
    pa_last = pa + LA.length - 1; pb_last = pb + LB.length - 1;
    while(pa<=pa_last&&pb<=pb_last)
    {
       if(*pa <= *pb)
       {
          *pc++ = *pa++;
       }
       else
       {
          *pc++ = *pb++;
       }
    }
    while(pa <= pa_last)  *pc++ = *pa++;
    while(pb <= pb_last)  *pc++ = *pb++;
}



