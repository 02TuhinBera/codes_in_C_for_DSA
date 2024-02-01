#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the deque
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure to represent a double-ended queue
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty deque
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("Element %d inserted at the front.\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("Element %d inserted at the rear.\n", data);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    struct Node* temp = deque->front;

    if (deque->front == deque->rear) {
        // Only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    printf("Element %d deleted from the front.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }

    struct Node* temp = deque->rear;

    if (deque->front == deque->rear) {
        // Only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    printf("Element %d deleted from the rear.\n", temp->data);
    free(temp);
}

// Function to display elements of the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* current = deque->front;

    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the deque
void freeDeque(struct Deque* deque) {
    struct Node* current = deque->front;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    initializeDeque(deque); // Reset deque after freeing memory
}

int main() {
    struct Deque myDeque;
    initializeDeque(&myDeque);

    insertFront(&myDeque, 1);
    insertFront(&myDeque, 2);
    insertRear(&myDeque, 3);
    displayDeque(&myDeque);

    deleteFront(&myDeque);
    deleteRear(&myDeque);
    displayDeque(&myDeque);

    freeDeque(&myDeque);

    return 0;
}
