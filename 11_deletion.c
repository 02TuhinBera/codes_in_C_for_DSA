//  Here we are deleting a element and shifting all rest of the element to the left side.

#include<stdio.h>

void display(int arr[], int n) {
    // code for traversal.
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ind_deletion(int arr[], int size, int index) {
    // code for deletion.
    
    for (int i = index; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5,  index = 2;
    display(arr, size);
    ind_deletion(arr, size, index);
    size--;
    display(arr, size); 
    return 0;
}
