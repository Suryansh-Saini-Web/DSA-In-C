// -----------------Question - Leet Code problem - 75 (Sort Colors) - An unsorted array of numbers - 0, 1, 2. Sort the array.-----------------------

// ------------------------First Version (Uncomment to execute)------------------------- 

/*
#include<stdio.h>

int main(){
    int arr[] = {0, 2, 2, 1, 0, 2, 1, 2, 1, 0, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length; i++){
        for(int j = (i + 1); j < length; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i = 0; i < length; i++){
         printf("%d ", arr[i]);
    }
    return 0;
}
*/



// ------------------------Second Version (Uncomment to execute)------------------------- 

/*
#include<stdio.h>

int main(){
    int arr[] = {0, 2, 2, 1, 0, 2, 1, 2, 1, 0, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    int count[3] = {0};
    for(int i = 0; i < length; i++){
        count[arr[i]]++;
    }
    int index = 0;
    for(int value = 0; value < 3; value++){
        while(count[value]--){
            arr[index++] = value;
        }
    }
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
*/



// ------------------------Third Version ------------------------- 

#include<stdio.h>

int main(){
    int arr[] = {0, 2, 2, 1, 0, 2, 1, 2, 1, 0, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    int low = 0, mid = 0, high = length - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        if(arr[mid] == 1){
            mid++;
        }
        if(arr[mid] == 2){
            int temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}