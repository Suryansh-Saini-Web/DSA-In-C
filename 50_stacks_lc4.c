// ---------------Leet Code problem - Insert an element at bottom of the stack.--------------------

#include<stdio.h>

void push(int stack[], int *stkptr, int num){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    stack[(*stkptr)++] = num;
}

int pop(int stack[], int *stkptr){
    (*stkptr)--;
    return stack[*stkptr];
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

void insert(int stack[], int *stkptr, int num){
    if(*stkptr == 0){
        push(stack, stkptr, num);
        return;
    }
    int temp = pop(stack, stkptr);
    insert(stack, stkptr, num);
    push(stack, stkptr, temp);
}

int main(){
    int stack[10];
    int stkptr = 0;
    push(stack, &stkptr, 2);            
    push(stack, &stkptr, 3);            
    push(stack, &stkptr, 4);            
    push(stack, &stkptr, 5);
    print(stack, stkptr);
    insert(stack, &stkptr, 1); 
    print(stack, stkptr);
    return 0;
}