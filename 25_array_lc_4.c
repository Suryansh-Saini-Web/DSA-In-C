// ---------------------Leet Code problem 349 - (Intersection of two arrays). Given two integer arrays, return an array of their intersection. Each element must be unique.-----------------------


#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int small(int size1, int size2){
    if(size1 <= size2){
        return size1;
    }else{
        return size2;
    }
}

void set(int result[], int *ptr, int num){
    for(int i = 0; i < *(ptr); i++){
        if(result[i] == num){
            return;
        }
    }
    result[*(ptr)] = num;
    (*ptr)++;
}

void intersection(int result[],int *ptr, int arr1[], int arr2[], int size1, int size2){
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < size1 && ptr2 < size2){
        if(arr1[ptr1] == arr2[ptr2]){
            set(result, ptr, arr1[ptr1]);
            ptr1++;
            ptr2++;
        }else if(arr1[ptr1] > arr2[ptr2]){
            ptr2++;
        }else{
            ptr1++;
        }
    }
}

void display(int arr[], int length){
    printf("Intersections: ");
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr1[] = {1, 2, 2, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int length = small(size1, size2);
    sort(arr1, size1);
    sort(arr2, size2);
    int result[length];
    int count = 0; 
    intersection(result, &count, arr1, arr2, size1, size2);
    display(result, count);
    return 0;
}