#include<stdio.h>

void init(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
}

void search(int arr[], int size){
    int value;
    printf("Enter the value you want to search: ");
    scanf("%d", &value);
    if(value < arr[0] || value > arr[size-1]){
        printf("Value not found in array.");
        return;
    }
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == value){
            printf("Value found at index %d", mid);
            return;
        }else if(arr[mid] < value){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    printf("Value not found in array.");
}

int main(){
    int size;
    printf("Enter the size of the arrray: ");
    scanf("%d", &size);
    if(size <= 0){
        printf("Error.");
        return 0;
    }
    int arr[size];
    init(arr, size);
    search(arr, size);
    return 0;
}