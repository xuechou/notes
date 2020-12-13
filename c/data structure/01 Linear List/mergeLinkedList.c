#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
bool Insert(List L, ElementType X);
List MakeEmpty();
List append(List L, List data);
List Merge(List L1, List L2);
List appendOld(List L, int data);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Read()
{
    int len, data;
    List L=NULL;
    printf("input num of list\n");
    scanf("%d\n", &len);

    printf("input item of list\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &data);
        L = appendOld(L, data);
    }
    
    return L;
}

void Print(List L)
{
    while (L != NULL)
    {
        printf("%d", L->Data);
        L = L->Next;
    }
    printf("\n");
}


List Merge(List L1, List L2)
{
    
    List head, L, L1Temp, L2Temp;

    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    head = L;

    L1Temp = L1;
    L2Temp = L2;

    L1 = L1->Next;
    L2 = L2->Next;

    while ((L1 != NULL) && (L2 != NULL))
    {
        if (L1->Data < L2->Data)
        {
            L->Next = L1;
            L = L1;

            L1 = L1->Next;

            if (L1 == NULL)
            {
                L->Next = L2;
            }
        }
        else
        {
            L->Next = L2;
            L = L2;

            L2 = L2->Next;

            if (L2 == NULL)
            {
                L->Next = L1;
            }
        }
    }

    L1Temp->Next = NULL;
    L2Temp->Next = NULL;

    return head;
}

List append(List L, List newL)
{
    List pNext = L;
    if (L == NULL)
    {
        L = newL;
        L->Next = NULL;
    }
    else
    {
        while (pNext->Next != NULL)
        {
            pNext = pNext->Next;
        }
        pNext->Next = newL;
        pNext->Next = NULL;
    }

    return L;
}

List appendOld(List L, int data)
{
    List pNext = L;
    List s = MakeEmpty();

    s->Data = data;

    if (L == NULL)
    {
        L = s;
    }
    else
    {
        while (pNext->Next != NULL)
        {
            pNext = pNext->Next;
        }
        pNext->Next = s;
    }

    return L;
}

/* 初始化 */
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;

    return L;
}