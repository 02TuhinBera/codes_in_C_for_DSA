#include<stdio.h>

int linear_search(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int main(){
int arr[] = {1, 25, 65, 78, 5, 96, 856, 45, 74, 369, 8};
int size = sizeof(arr)/sizeof(int);
int element = 5;
int search_index = linear_search(arr, size, element);
printf("The element %d was found at  %d index", element, search_index);
 return 0;
}