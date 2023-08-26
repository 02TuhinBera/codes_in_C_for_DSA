#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head; 
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != NULL);
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
    head->prev = NULL;
    head->data = 7;
    head->next = second;

    // Link second to third
    second->prev = head;
    second->data = 11;
    second->next = third;

    // Link third to fourth
    third->prev = second;
    third->data = 47;
    third->next = fourth;

    // Link fourth to NULL
    fourth->prev = third;
    fourth->data = 99;
    fourth->next = NULL;

    linked_list_traversal(head);

    return 0;
}