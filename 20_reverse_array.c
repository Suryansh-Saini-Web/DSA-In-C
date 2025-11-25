#include<stdio.h>
#include<stdlib.h>

void error(){
    printf("Invalid Input.\n");
    printf("Program Terminated.\n");
    exit(0);
}

void set(int arr[],int total_size, int *used_size){
    printf("Enter the size you want to utilize now: ");
    scanf("%d", used_size);
    if(total_size < *(used_size) || *(used_size) < 2){
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

void reverse(int arr[], int used_size){
    printf("Reversed Array:\n");
    int loop = used_size/2;
    for(int i = 0; i < loop; i++){
        int temp = arr[i];
        arr[i] = arr[used_size - (i+1)];
        arr[used_size - (i+1)] = temp;
    }
    display(arr, used_size);
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
    reverse(arr, used_size);
    return 0;
}