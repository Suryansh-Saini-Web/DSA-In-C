// -------------Creating my own stack data structure using arrays.----------------

#include<stdio.h>

void push(int stack[], int *stkptr, int size, int num){
    if(*stkptr >= size){
        printf("Stack Overflowed\n");
        return;
    }
    stack[(*stkptr)++] = num;
}

void isempty(int stkptr){
    if(stkptr == 0){
        printf("True\n");
    }else{
        printf("False\n");
    }
}

void pop(int stack[], int *stkptr){
    if(*stkptr == 0){
        printf("Stack Underflowed\n");
        return;
    }
    (*stkptr)--;
    printf("Popped: %d\n", stack[*stkptr]);
}

void peek(int stack[], int stkptr){
    stkptr--;
    if(stkptr < 0){
        return;
    }
    printf("%d\n", stack[stkptr]);
}

void print(int stack[], int stkptr){
    printf("[");
    while(stkptr--){
        printf("%d", stack[stkptr]);
        if(stkptr > 0){
            printf(", ");
        }
    }
    printf("]\n");
}

int main(){
    int size = 100;
    int stack[size];
    int stkptr = 0;
    isempty(stkptr);
    push(stack, &stkptr, size, 1);
    push(stack, &stkptr, size, 2);            
    peek(stack, stkptr);
    pop(stack, &stkptr);
    print(stack, stkptr);
    return 0;
}