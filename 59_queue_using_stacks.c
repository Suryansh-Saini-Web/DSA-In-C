// -------------Creating Queue using Stacks.----------------

#include<stdio.h>

void push(int stack[], int *stkptr, int num){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    stack[(*stkptr)++] = num;
}

void enqueue(int stack[], int *stkptr, int num){
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

int dequeue(int stack[], int stack2[], int *stkptr, int *stkptr2){
    if(*stkptr2 > 0){
        int num = pop(stack2, stkptr2);
        return num;
    }
    if(*stkptr == 0){
        printf("Stack Underflowed\n");
        return -1;
    }else{
        while(*stkptr > 0){
            int num = pop(stack, stkptr);
            push(stack2, stkptr2, num);
        }
        int num = pop(stack2, stkptr2);
        return num;
    }   
}

int main(){
    int stack[10];
    int stack2[10];
    int stkptr = 0;
    int stkptr2 = 0;
    enqueue(stack, &stkptr, 1);
    enqueue(stack, &stkptr, 2);
    enqueue(stack, &stkptr, 3);
    int num = dequeue(stack, stack2, &stkptr, &stkptr2);
    printf("%d\n", num);
    return 0;
}