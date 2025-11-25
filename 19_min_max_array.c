// ---------------Finding minimum and maximum value element in an array.------------------

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
    if(*(used_size) > total_size || *(used_size) <= 0){
        error();
    }
    for(int i = 0; i < *(used_size); i++){
        printf("Enter value for %d index: ", i);
        scanf("%d", &arr[i]);
    }
}

void min(int arr[], int used_size){
    int index = 0;
    int min = arr[0];
    for(int i = 1; i < used_size; i++){
        if(min > arr[i]){
            min = arr[i];
            index = i;
        }
    }
    printf("Minimum element is %d at index %d\n", min, index);
}

void max(int arr[], int used_size){
    int index = 0;
    int max = arr[0];
    for(int i = 1; i < used_size; i++){
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    printf("Maximum element is %d at index %d\n", max, index);
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
    min(arr, used_size);
    max(arr, used_size);
    return 0;
}