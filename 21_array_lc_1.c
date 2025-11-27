// -----------------Leet Code problem 136 - Single Number - In an array every element appears twice except for one. Find that single one.---------------------------

// -------------------First Version (Uncomment to execute) ---------------------

/*
#include<stdio.h>

int main(){
    int arr[] = {12, 5, 3, 5, 12};
    int length = 5;
    for(int i = 0; i < length; i++){
        if(arr[i] != -99){
            for(int j = i+1; j < length; j++){
                if(arr[j] != -99){
                    if(arr[i] == arr[j]){
                        arr[i] = -99;
                        arr[j] = -99;
                        break;
                    }
                }  
            }
        }
    }
    for(int i = 0; i < length; i++){
        if(arr[i] != -99){
            printf("%d", arr[i]);
        }        
    }
    return 0;
}
*/

// -------------------Second Version---------------------

#include<stdio.h>

int main(){
    int arr[] = {12, 5, 3, 5, 12};
    int length = 5;
    int result = 0;
    for(int i = 0; i < length; i++){
        result = result ^ arr[i];
    }
    printf("Unique number is: %d", result);
}