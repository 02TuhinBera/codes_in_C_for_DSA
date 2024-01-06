#include <stdio.h>
#define MAX 10 // Maximum size of the deque

int deque[MAX];
int front = -1, rear = -1;

// Function prototypes
void insert_front(int value);
void insert_rear(int value);
void delete_front();
void delete_rear();
void display();

int main() {
    int choice, value;

    do {
        printf("\n1. Insert at front");
        printf("\n2. Insert at rear");
        printf("\n3. Delete from front");
        printf("\n4. Delete from rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insert_front(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insert_rear(value);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to insert an element at the front of the deque
void insert_front(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = value;
}

// Function to insert an element at the rear of the deque
void insert_rear(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

// Function to delete an element from the front of the deque
void delete_front() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Function to delete an element from the rear of the deque
void delete_rear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Function to display the elements of the deque
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
    }
}