#include<stdio.h>

int binary_search(int arr[], int size, int element){
    int low, mid, high;
    low=0;
    high=size-1;
    // Start searching
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return -1;


}


int main(){
int arr[] = {1, 2, 5, 9, 12, 17, 25, 39, 47, 65, 85, 99, 125, 500};
int size = sizeof(arr)/sizeof(int);
int element;
printf("Enter the number which you are going to search: ");
scanf("%d", &element);
int search_index = binary_search(arr, size, element);
if (search_index != -1) {
    printf("The element %d was found at index %d", element, search_index);
    }
 else {
    printf("The element %d was not found in the array", element);
    }
 return 0;
}