#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to traverse and print the elements of the doubly linked list
void linked_list_traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a new node at the beginning of the doubly linked list
void insert_at_beginning(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

// Function to insert a new node at the end of the doubly linked list
void insert_at_end(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, make the new node the head
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        // Traverse to the end of the list
        struct Node *last = *head;
        while (last->next != NULL)
            last = last->next;

        // Link the new node to the last node
        last->next = new_node;
        new_node->prev = last;
    }
}

// Function to insert a new node after a specific node in the doubly linked list
void insert_after_node(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;

    prev_node->next = new_node;
}

// Function to delete a node by its value from the doubly linked list
void delete_node_by_value(struct Node **head, int key)
{
    struct Node *current = *head;

    // Traverse to find the node with the specified value
    while (current != NULL && current->data != key)
        current = current->next;

    if (current == NULL)
    {
        // Node with the specified value not found
        printf("Node with value %d not found\n", key);
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

// Function to delete the first node from the doubly linked list
void delete_first_node(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

// Function to delete the last node from the doubly linked list
void delete_last_node(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
        last = last->next;

    if (last->prev != NULL)
        last->prev->next = NULL;
    else
        *head = NULL;

    free(last);
}

// Function to delete a node at a specific position from the doubly linked list
void delete_node_at_position(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node *current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position to delete\n");
        return;
    }

    struct Node *temp = current->next;
    current->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = current;

    free(temp);
}

int main()
{
    struct Node *head = NULL;

    // Insert nodes at the end
    insert_at_end(&head, 7);
    insert_at_end(&head, 11);
    insert_at_end(&head, 47);
    insert_at_end(&head, 99);

    printf("Original Doubly Linked List:\n");
    linked_list_traversal(head);

    // Insert nodes at the beginning
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 3);

    // Insert a node after a specific node
    insert_after_node(head->next, 8);

    printf("\nDoubly Linked List after insertions:\n");
    linked_list_traversal(head);

    // Delete a node by value
    delete_node_by_value(&head, 11);

    // Delete the first and last nodes
    delete_first_node(&head);
    delete_last_node(&head);

    // Delete a node at a specific position
    delete_node_at_position(&head, 2);

    printf("\nDoubly Linked List after deletions:\n");
    linked_list_traversal(head);

    // Free allocated memory
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
