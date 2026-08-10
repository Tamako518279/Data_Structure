#ifndef SQLIST_H
#define SQLIST_H
#define MAXSIZE 100
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
typedef struct 
{
    ElemType *Elem;
    int length;
}SqList;
Status InitList(SqList *L);
Status GetElem(SqList L,int i,ElemType *e);
int LocateElem(SqList L,ElemType e);
Status ListInsert(SqList *L,int i,ElemType e);
Status ListDelete(SqList *L,int i);
void MergeList_Sq(SqList LA,SqList LB,SqList *LC);



#endif