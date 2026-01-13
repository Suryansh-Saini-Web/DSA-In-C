// ---------------Leet Code problem - Sort Stack.--------------------

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

int peek(int stack[], int stkptr){
    stkptr--;
    return stack[stkptr];
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
    int top = peek(stack, *stkptr);
    if(num >= top){
        push(stack, stkptr, num);
        return;
    }else{
        int temp = pop(stack, stkptr);
        insert(stack, stkptr, num);
        push(stack, stkptr, temp);
    }
}

void sort(int stack[], int *stkptr){
    if(*stkptr <= 1){
        return;
    }
    int top = pop(stack, stkptr);
    sort(stack, stkptr);
    insert(stack, stkptr, top);
}

int main(){
    int stack[10];
    int stkptr = 0;            
    push(stack, &stkptr, 7); 
    push(stack, &stkptr, 5); 
    push(stack, &stkptr, -1);           
    push(stack, &stkptr, -5);           
    push(stack, &stkptr, 17);            
    push(stack, &stkptr, 11);            
    push(stack, &stkptr, 34);
    push(stack, &stkptr, 9);
    print(stack, stkptr);
    sort(stack, &stkptr); 
    print(stack, stkptr);
    return 0;
}