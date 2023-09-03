#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * top = NULL;

int linked_list_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


int is_empty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }

}

struct Node * push(struct Node * top, int x){
    if(is_full(top)){
        printf("Stack overflow\n");
    }
    else{
        struct Node * n=(struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}


int pop(struct Node * tp){
    if(is_empty(tp)){
        printf("Stack underflow\n");
    }
    else{
        struct Node * n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
        
    }
}



int main(){
    top =push(top, 47);
    top =push(top, 89);
    top =push(top, 23);

    linked_list_traversal(top);

    int element = pop(top);
    printf("Popped element is %d\n", element);

    linked_list_traversal(top);

 return 0;
}