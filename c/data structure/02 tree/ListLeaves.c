#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// typedef struct TNode *Position;
typedef char ElementType;
#define Tree int
#define Null (-1)
#define MaxTree (10)

/*----------- tree start-----------------*/
// typedef Position BinTree; /* 二叉树类型 */
struct TNode
{                     /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    Tree Left;        /* 指向左子树 */
    Tree Right;       /* 指向右子树 */
};
/*----------- tree end-----------------*/

/*----------- queue start-----------------*/
typedef struct TNode queueElementType;
#define ERROR (-1)

typedef int Position;
struct QNode
{
    queueElementType *Data; /* 存储元素的数组 */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);
bool IsFull(Queue Q);
bool AddQ(Queue Q, queueElementType X);
bool IsEmpty(Queue Q);
queueElementType DeleteQ(Queue Q);
void LevelorderTraversal(struct TNode T1[], int Root);
Tree BuildTree(int N, struct TNode T[]);

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (queueElementType *)malloc(MaxSize * sizeof(queueElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool AddQ(Queue Q, queueElementType X)
{
    if (IsFull(Q))
    {
        printf("队列满");
        return false;
    }
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}

queueElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("队列空");
        // return  ERROR;
    }
    else
    {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}

/* ----------- queue end----------------*/

Tree BuildTree(int N, struct TNode T[])
{
    int i, j,k;
    int Root = -1;
    char cl, cr;
    int check[MaxTree];

    if (N)
    {
        for (j = 0; j < N; j++)
            check[j] = 0;

        for (i = 0; i < N; i++)
        {
            T[i].Data = i;
            //printf("input node %d\n", i);
            //fflush(stdin); /* TODO: */
            scanf("\n%c %c", &cl, &cr);

            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;

            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;
        }

        for (k = 0; k < N; k++)
        {
            if (!check[k])
                break;
        }

        Root = k;
    }
    return Root;
}

struct TNode T1[MaxTree];
void LevelorderTraversal(struct TNode T1[], int Root);

int main()
{

    int i = 0;
    int N, R;
    //nt check1[MaxTree];
    //printf("input num of node of T\n");
    //fflush(stdin); /* TODO: */
    scanf("%d", &N);
    //printf("num is %d\n", N);

    R = BuildTree(N, &T1[0]);

    //level travesal BinTree
    LevelorderTraversal(&T1[0], R);

    return 0;
}

void LevelorderTraversal(struct TNode T1[], int Root)
{
    Queue Q;
    int count = 0;
    struct TNode tempNode;

    if (Root == Null)
    {
        return; /* 若是空树则直接返回 */
    }

    Q = CreateQueue(10); /* 创建空队列Q */
    AddQ(Q, T1[Root]);   /* 首先让根节点入队 */

    while (!IsEmpty(Q))
    {
        tempNode = DeleteQ(Q);

        /* print leaves node */
        if (tempNode.Left == Null && tempNode.Right == Null)
        {
            if (count == 0)
            {
                printf("%d", tempNode.Data);
                count++;
            }
            else
            {
                printf(" %d", tempNode.Data);
            }
        }

        if (tempNode.Left != Null)
        {
            AddQ(Q, T1[tempNode.Left]);
        }
        if (tempNode.Right != Null)
        {
            AddQ(Q, T1[tempNode.Right]);
        }
    }
}