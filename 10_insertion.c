//  Here we are inserting a element and shifting all rest of the element to the right side.

#include<stdio.h>

void display(int arr[], int n) {
    // code for traversal.
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int ind_insertion(int arr[], int size, int element, int capacity, int index) {
    // code for insertion.
    if (size >= capacity) {
        return -1;
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5, element = 47, index = 3;
    
    display(arr, size);
    ind_insertion(arr, size, element, 100, index);
    size++;
    display(arr, size);
    
    return 0;
}
