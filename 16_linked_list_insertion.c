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
// Case 1
struct Node * insert_at_first(struct Node *head, int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;

}
// Case 2
struct Node * insert_at_index(struct Node *head, int data, int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p =head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
// Case 3
struct Node * insert_at_end(struct Node *head, int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p = head;
    while(p->next!=NULL)
    {
        p = p->next;

    }
    p->next = ptr;
    ptr->next = NULL;
    return head;  
} 
// Case 4
struct Node * insert_after_node(struct Node *head,struct Node * prevNode, int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

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
    printf("Linked list before insertion\n");
    linked_list_traversal(head);
    // head=insert_at_first(head, 999);              // for  case 1
    //head=insert_at_index(head, 100, 2);           // for case 2
    // head=insert_at_end(head, 1000000);          // for case 3
    head=insert_after_node(head, second, 555);    // for case 4
    printf("\nLinked list after insertion\n");
    linked_list_traversal(head);


    return 0;
}