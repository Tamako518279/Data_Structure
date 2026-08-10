#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main(void)
{
    SqList L;
    ElemType value;

    if (InitList(&L) == ERROR)
        return 1;

    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);

    if (GetElem(L, 2, &value) == OK)
        printf("The second element is: %d\n", value);

    free(L.Elem);
    return 0;
}