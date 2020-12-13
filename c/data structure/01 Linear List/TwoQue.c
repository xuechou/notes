#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

List Merge(List L1, List L2);

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

List Merge(List L1, List L2)
{
    int lenL;
    List Lhead,LTail; //result
    //  initial a  link list to store result, length L1 + L2
    lenL = Llength(L1) + Llength(L2);
    Lhead = MakeEmpty();
    LTail = Lhead;

    //  compare L1[0] > L2[0]
    while ((L1 == NULL ) && (L2 == NULL))
    {
        if (L1->Data < L2->Data)
        {
            append(LTail, L1->Data);

            L1 = L1->Next;
            //TODO: L1 == NULL ?
            if (L1 == NULL)
            {
                //todo:
            }
        }
        else
        {
            append(LTail, L2->Data);

            L2 = L2->Next;
            //TODO: L1 == NULL ?
            if (L2 == NULL)
            {
                //todo:
            }
        }
    }

    return Lhead;
}

/* 初始化 */
List MakeEmpty(void)
{
    List L;

    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;

    return L;
}


void append(List LTail, int data)
{
    List s = MakeEmpty();

    s->Data = data;
    s->Next = NULL;

    LTail->Next = s;

    LTail = s;
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert( List L, ElementType X, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;
 
    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL ) { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}