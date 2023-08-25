#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr!= head);
}

struct Node * insert_at_beginning(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p pionts the last node of the circular linked list
    p->next = ptr;
    ptr->next =head;
    head = ptr;
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
    fourth->next = head;
    printf("Circular linked list before insertion: \n");
    linked_list_traversal(head);
    head = insert_at_beginning(head, 101);
    printf("Circular linked list after insertion: \n");
    linked_list_traversal(head);

    return 0;
}