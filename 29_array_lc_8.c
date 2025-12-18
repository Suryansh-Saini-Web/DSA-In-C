// -------------------Leet Code problem (Array sorted and rotated)---------------------

#include<stdio.h>

int main(){
    int arr[] = {1, 4, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int greater = 0;
    for(int i = 0; i < size; i++){
        int index = (i + 1) % size;
        if(arr[i] > arr[index]){
            greater++;
        }
    }
    if(greater > 1){
        printf("False");
    }else{
        printf("True");
    }
    return 0;
}