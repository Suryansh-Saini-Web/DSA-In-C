#include<stdio.h>
#include<stdlib.h>

void error(){
    printf("Invalid Input.\n");
    printf("Program Terminated.\n");
    exit(0);
}

void set(int arr[], int total_size, int *used_size){
    printf("Enter the size of array you want to utilize now: ");
    scanf("%d", used_size);
    if(total_size < *(used_size) < 0){
        error();
    }else{
        for(int i = 0; i < *(used_size); i++){
            printf("Enter value for index %d: ", i);
            scanf("%d", &arr[i]);
        }
    }
    
}

void display(int arr[], int used_size){
    for(int i = 0; i < used_size; i++){
        printf("Index %d: %d\n", i, arr[i]);
    }
}

void insert(int arr[], int *used_size, int total_size){
    int index, value;
    printf("Enter the index at which you want to insert value: ");
    scanf("%d", &index);
    if(total_size == *(used_size)){
        error();
    }else if(*(used_size) < index < 0 ){
        error();
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
        error();
    }
    int arr[total_size];
    int used_size;
    set(arr, total_size, &used_size);
    display(arr, used_size);
    insert(arr, &used_size, total_size);
    display(arr, used_size);
    return 0;
}