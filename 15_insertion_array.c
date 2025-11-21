#include<stdio.h>
#include<stdlib.h>

void set(int arr[], int total_size, int *used_size){
    printf("Add values into array:-\n");
    printf("Enter the size of array you want to utilize now: ");
    scanf("%d", used_size);
    if(*(used_size) <= total_size){
        for(int i = 0; i < *(used_size); i++){
            printf("Enter value for index %d: ", i);
            scanf("%d", &arr[i]);
        }
    }else{
        printf("Invalid Input.\n");
        printf("Program Terminated.\n");
        exit(0);
    }
    
}

void display(int arr[], int *used_size){
    if(*(used_size) >  0){
        printf("Displaying Array:-\n");
        for(int i = 0; i < *(used_size); i++){
            printf("Index %d: %d\n", i, arr[i]);
        }
    }
}

void insert(int arr[], int *used_size, int total_size){
    int index, value;
    printf("Enter the index at which you want to insert value: ");
    scanf("%d", &index);
    if(total_size == *(used_size)){
        printf("Array is full.\n");
        printf("Program Terminated.\n");
        exit(0);
    }else if(*(used_size) < index || index < 0 ){
        printf("Invalid Input.\n");
        printf("Program Terminated.\n");
        exit(0);
    }else{
        printf("Enter the value which you want to insert: ");
        scanf("%d", &value);
        for(int i = *(used_size); i > index; i--){
            arr[i] = arr[i-1]; 
        }
        arr[index] = value;
        (*used_size)++;
    }
}

int main(){
    int total_size;
    printf("Enter the size of array you want to create: ");
    scanf("%d", &total_size);
    if(total_size <= 0){
        printf("Invalid Input.\n");
        printf("Program Terminated.\n");
        exit(0);
    }
    int arr[total_size];
    printf("Message: Array created successfully.\n");
    int used_size;
    set(arr, total_size, &used_size);
    display(arr, &used_size);
    insert(arr, &used_size, total_size);
    display(arr, &used_size);
    return 0;
}