#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
}

int main()
{
    // struct stack S;
    // S.size = 80;
    // S.top = -1;
    // S.arr = (int*)malloc(S.size*sizeof(int)); 


    struct stack *S;                     // We can use both of them
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    // S->arr[0]=2;                   // By implementing a number in this array, we are checking the stack is full or not.
    // S->top++;

    if (is_empty(S))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }
    return 0;
}