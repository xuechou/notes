#define MAXSIZE 200

typedef int Position;
typedef int ElementType; //TODO:

typedef struct
{
    ElementType Data[MAXSIZE];
    Position Last;
} ListType;