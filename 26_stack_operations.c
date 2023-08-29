#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size ;
    int top;
    int * arr;
};
int is_empty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int is_full(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr, int val){
    if(is_full(ptr)){
        printf("Stack overflow! Cannot push anymore.\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}


int pop(struct stack * ptr){
    if(is_empty(ptr)){
        printf("Stack underflow! Cannot pop anymore.\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int main(){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("%d\n", is_empty(sp));
    printf("%d\n", is_full(sp));
    push(sp, 47);
    push(sp, 7);
    push(sp, 89);
    push(sp, 52);
    push(sp, 63);
    push(sp, 78);
    push(sp, 1);
    push(sp, 75);
    push(sp, 21);
    push(sp, 3);

    // push(sp, 47);          //Just checking if the satck is overflow or not.....

    printf("%d\n", is_empty(sp));
    printf("%d\n", is_full(sp));

    printf("Popped %d from the stack.\n", pop(sp));
    printf("%d\n", is_full(sp));
 return 0;
}