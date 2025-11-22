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
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            printf("Found Value at index %d", i);
            return;
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