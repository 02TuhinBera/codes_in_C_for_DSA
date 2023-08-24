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

    linked_list_traversal(head);

    return 0;
}