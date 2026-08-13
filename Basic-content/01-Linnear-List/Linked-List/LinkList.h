#ifndef LINKLIST_H
#define LINKLIST_H
typedef int ElemType;
typedef int Status;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

typedef struct Pnode
{
    float coef;  //系数
    int expn;    //指数
    struct Pnode *next;
}PNode,*Polynomial;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
Status InitList(LinkList *L);
Status GetElem(LinkList L,int i,ElemType *e);
LNode *LocateElem(LinkList L,ElemType e);
Status ListInsert(LinkList *L,int i,ElemType e);
Status ListDelete(LinkList *L,int i);
void CreateList_H(LinkList *L,int n);
void CreateList_R(LinkList *L,int n);
DuLNode* GetElem_DuL(DuLinkList *L,int i);
Status ListInsert_DuL(DuLinkList *L,int i,ElemType e);
Status ListDelete_DuL(DuLinkList *L,int i);
void MergeList_L(LinkList *LA,LinkList *LB,LinkList *LC);
void CreatePolyn(Polynomial *p,int n);
void AddPolyn(Polynomial *Pa,Polynomial *Pb);
#endif
