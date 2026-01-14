// -------------Leet code problem - Min stack - Find the minimum value in stack using O(n) space complexity.----------------

#include<stdio.h>

int peek(int stack[], int stkptr){
    stkptr--;
    return stack[stkptr];
}

void push(int stack[], int *stkptr, int num){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    stack[(*stkptr)++] = num;
}

void push1(int stack[], int *stkptr, int num){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    if(*stkptr == 0){
        stack[(*stkptr)++] = num;
        return;
    }
    int top = peek(stack, *stkptr);
    if(top > num){
        stack[(*stkptr)++] = num;
    }else{
        stack[(*stkptr)++] = top;
    }
}

void pop(int stack[], int *stkptr){
    if(*stkptr == 0){
        printf("Stack Underflowed\n");
        return;
    }
    (*stkptr)--;
}

void pop1(int stack[], int *stkptr){
    if(*stkptr == 0){
        return;
    }
    (*stkptr)--;
}

int main(){
    int stack[10];
    int min[10];
    int stkptr = 0;
    int minptr = 0;
    push(stack, &stkptr, 2);
    push1(min, &minptr, 2);
    push(stack, &stkptr, 3);
    push1(min, &minptr, 3);
    pop(stack, &stkptr);
    pop1(min, &minptr);
    printf("Minimum = %d\n", peek(min, minptr));
    push(stack, &stkptr, 1);
    push1(min, &minptr, 1);
    printf("Minimum = %d\n", peek(min, minptr));
    return 0;
}