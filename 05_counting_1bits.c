// -------------------(LeetCode problem 338 - Counting Bits) - Given an integer n, return an array such that for each i (0 <= i <= n), array[i] is the number of 1's bit in the binary representaion of i.

// -------------------First Version----------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    int arr[input+1];
    for(int i = 0; i <= input; i++){
        int count = 0;
        int copy = i;
        while(copy){
            copy &= (copy - 1);
            count++;
        }
        arr[i] = count;
        printf("Number of '1' bit in %d: %d\n", i, arr[i]);
    }
    return 0;
}
*/



// -------------------Second Version (With O(n) Time and Space Complexity ----------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    int arr[input+1];
    arr[0] = 0;
    for(int i = 1; i <= input; i++){
        arr[i] = arr[i >> 1] + (i & 1);
    }
    printf("Number of 1's bit in following numbers:\n");
    for(int i = 0; i <= input; i++){
        printf("%d -> %d\n", i, arr[i]);
    }
    return 0;
}
*/