// -------------------Leet Code problem 189 - (Rotate Array)-------------

// ------------First Version (Uncomment to execute)-------------

/*
#include<stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = (sizeof(arr) / sizeof(arr[0]));
    int nums[length];
    int k = 2;
    for(int i = 0; i < length; i++){
        int index = (i + k) % length;
        nums[index] = arr[i];
    }
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}
*/


// -------------------Second Version---------------


#include<stdio.h>

void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int length, int k){
    reverse(arr, 0, length - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, length - 1);
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    rotate(arr, length, k);
    return 0;
}
