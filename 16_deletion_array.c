#include<stdio.h>
#include<stdlib.h>

void error(){
    printf("Invalid Input.\n");
    printf("Program Terminated.\n");
    exit(0);
}

void set(int arr[], int total_size, int *used_size){
    printf("Enter the size you want to utilize now: ");
    scanf("%d", used_size);
    if(total_size < *(used_size) || *(used_size) <= 0){
        error();
    }else{
        for(int i = 0; i < *(used_size); i++){
            printf("Enter the value for index %d: ", i);
            scanf("%d", &arr[i]);
        }
    }
}

void display(int arr[], int used_size){
    for(int i = 0; i < used_size; i++){
        printf("Index %d: %d\n", i, arr[i]);
    }
}

void delete(int arr[], int *used_size){
    int index;
    printf("Enter the index you want to delete: ");
    scanf("%d", &index);
    if(*(used_size) <= index || index < 0){
        error();
    }else{
        (*used_size)--;
        for(int i = index; i < *(used_size); i++){
            arr[i] = arr[i+1];
        }
        printf("Deleted Successfully.\n");
    }
}

int main(){
    int total_size;
    printf("Enter the total size of the array you want to create: ");
    scanf("%d", &total_size);
    if(total_size <= 0){
        error();
    }
    int arr[total_size];
    int used_size;
    set(arr, total_size, &used_size);
    display(arr, used_size);
    delete(arr, &used_size);
    display(arr, used_size);
    return 0;
}