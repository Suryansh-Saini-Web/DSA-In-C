// ---------------Constant - O(1) example. (Uncomment to execute)-----------------

/*
#include<stdio.h>

int main(){
    int arr[5] = {5, 8, 2, 4, 1};
    int index = 3;
    printf("Value at index %d = %d", index, arr[index]);
    return 0;
}
*/



// ---------------Linear - O(n) example. (Uncomment to execute)-----------------

/*
#include<stdio.h>

int main(){
    int arr[8] = {8, 6, 9, 3, 6, 2, 5, 1};
    int length = sizeof(arr)/ sizeof(arr[0]);
    for(int i = 0; i < length; i++){
        printf("Value at index %d = %d\n", i, arr[i]);
    }
    return 0;
}
*/



// ---------------Log - O(log n) example. (Uncomment to execute)-----------------

/*
#include<stdio.h>

int main(){
    int arr[9] = {8, 13, 23, 34, 48, 56, 63, 73, 89};
    int length = sizeof(arr)/sizeof(arr[0]);
    int target = 8;
    int start_index = 0;
    int end_index = length - 1;
    while(start_index <= end_index){
        int mid_index = (start_index + end_index)/2;
        if(arr[mid_index] == target){
            printf("Found target at index %d.\n", mid_index);
            break;
        }else if(arr[mid_index] < target){
            start_index = mid_index + 1;
        }else if(arr[mid_index] > target){
            end_index = mid_index - 1;
        }
    }
    return 0;
}
*/



// ---------------Quadratic - O(n^2) example. (Uncomment to execute)-----------------

/*
#include<stdio.h>

int main(){
    int arr[10] = {34, 23, 45, 67, 32, 65, 89, 67, 90, 12};
    int length = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i = 0; i < (length - 1); i++){
        for(int j = 0; j < (length - i - 1); j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
*/
