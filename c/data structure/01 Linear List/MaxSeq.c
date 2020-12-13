#include <stdio.h>

int MaxSubseqSum4(int List[], int N);

int main(void)
{
    int num,i;
    int List[100000];

    scanf("%d",&num);
    // TODO:malco
    for(i=0;i<num;i++)
    {
        scanf("%d",&List[i]);
    }

    printf("%d",MaxSubseqSum4(List, num));

    return 0;
}

int MaxSubseqSum4(int List[], int N)
{
    int i;
    int ThisSum, MaxSum;

    ThisSum = MaxSum =0;

    for (i=0; i<N; i++)
    {
        ThisSum += List[i];

        if(ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
        }
    }
    return MaxSum;
}