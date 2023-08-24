#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int linked_list_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Csae 1 = Deleting the first element from the linked list
struct Node * delete_first(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}



//  Case 2 = Deletion at a given  index
struct Node * delete_at_index(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i = 0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}



// Case 3 = Deleting theb last node
struct Node * delete_at_last(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4 = Deletion at a given value
struct Node * delete_at_a_given_value(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!= value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first to second
    head->data = 7;
    head->next = second;

    // Link second to third
    second->data = 11;
    second->next = third;

    // Link third to fourth
    third->data = 47;
    third->next = fourth;

    // Link fourth to NULL
    fourth->data = 99;
    fourth->next = NULL;
    printf("Linked list before deletion\n");
    linked_list_traversal(head);

    // head = delete_first(head);                           //  Case 1
    // head = delete_at_index(head, 2);                    //  Case 2
    // head = delete_at_last(head);                       //  Case 3    
    head = delete_at_a_given_value(head, 47);            //  Case 4
    printf("Linked list after deletion\n");
    linked_list_traversal(head);

    return 0;
}