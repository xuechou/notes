#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 200

typedef int Position;
typedef int ElementType; //TODO:

typedef struct
{
    ElementType Data[MAXSIZE];
    Position Last;
} ListType;

ListType InitList();
Position Find(ListType list, ElementType element);
bool Insert(ListType list, int index);
bool Delete(ListType list, int index);
int Length(ListType list);

ListType InitList()
{
    ListType List;
    List.Last = 0;
    return List;
}

Position Find(ListType list, ElementType element)
{
    int index;
    
    for(index=0; index<list.Last; index++)
    {
        if(list.Data[index] == element)
            return index;

    }
    return -1;
}