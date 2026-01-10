// ---------------Leet Code problem - Two Stack - Represent two stacks using only one array. The stack should support - push(), pop() and return -1 in case of underflow or overflow.--------------------

#include<stdio.h>

void push1(int arr[], int *stk1ptr, int *stk2ptr, int num){
    if(*stk1ptr > *stk2ptr || *stk1ptr > 9){
        printf("Stack Overflowed\n");
        return;
    }
    arr[(*stk1ptr)++] = num;
}

void push2(int arr[], int *stk2ptr, int *stk1ptr, int num){
    if(*stk1ptr > *stk2ptr || *stk2ptr < 0){
        printf("Stack Overflowed\n");
        return;
    }
    arr[(*stk2ptr)--] = num;
}

int pop1(int arr[], int *stk1ptr){
    if(*stk1ptr <= 0){
        return -1;
    }
    return arr[--(*stk1ptr)];
}

int pop2(int arr[], int *stk2ptr){
    if(*stk2ptr >= 9){
        return -1;
    }
    return arr[++(*stk2ptr)];
}

int main(){
    int arr[10];
    int stk1ptr = 0;
    int stk2ptr = 9;
    push1(arr, &stk1ptr, &stk2ptr, 1);
    push2(arr, &stk2ptr, &stk1ptr, 4);
    printf("%d\n", pop1(arr, &stk1ptr));
    printf("%d\n", pop2(arr, &stk2ptr));
    return 0;
}