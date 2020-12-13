#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxTree (10)
#define Null (-1)
#define ElementType char
#define Tree int

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;

} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int N;
    int Root = -1;
    printf("input number of node\n");
    // scanf("%d\n", &N);
    scanf("%d", &N);
    printf("input over\n");

    if (N > 0)
    {
        int i;
        int check[N];
        char cl, cr;

        for (i = 0; i < N; i++)
        {
            check[i] = 0;
        }

        for (i = 0; i < N; i++)
        {
            printf("input node %d\n", i+1);
            //注意scanf中间的空格
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);

            /* deal with cl */
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }

            /* deal with cr */
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }
        /* find root node*/
        for (i = 0; i < N; i++)
        {
            if (!check[i])
            {
                break;
            }
            Root = i;
        }
    }
}

int main(void)
{
    int root;
    root = BuildTree(T1);
    
    printf("break here");

    return 0;
}