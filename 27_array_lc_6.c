// --------------------Leet Code problem 283 - (Move Zeroes)-------------------------

// ----------------First Version (Uncomment to execute)----------------

/*
#include<stdio.h>

int main(){
    int arr[] = {0, 1, 0, 3, 12};
    int length = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] != 0){
            arr[count] = arr[i];
            count++;
        }
    }
    while(count < length){
        arr[count++] = 0;
    }
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
*/

// ----------------Second Version---------------------

#include<stdio.h>

void swap(int arr[], int i, int index){
    int temp = arr[index];
    arr[index] = arr[i];
    arr[i] = temp;
}

int main(){
    int arr[] = {1, 0, 0, 3, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] != 0){
            if(i != index){
                swap(arr, i, index);
            }
            index++;
        }
    }
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}