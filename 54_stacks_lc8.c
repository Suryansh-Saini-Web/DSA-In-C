// ---------------Leet Code problem - The Celebrity Problem.--------------------

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

int main(){
    int celebrity[3][3] = {{0, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    int stack[10];
    int stkptr = 0;    
    push(stack, &stkptr, 0);        
    push(stack, &stkptr, 1);        
    push(stack, &stkptr, 2);
    while(stkptr != 1){
        int a = pop(stack, &stkptr);        
        int b = pop(stack, &stkptr);
        if(celebrity[a][b] == 1){
            push(stack, &stkptr, b); 
        }else{
            push(stack, &stkptr, a);
        }        
    }
    int pc =  pop(stack, &stkptr);
    for(int i = 0; i < 3; i++){
        if(pc == i){
            continue;
        }
        if(celebrity[pc][i] != 0 || celebrity[i][pc] != 1){
            printf("No Celebrity\n");
            return 0;
        }
    }
    printf("Celebrity = %d", pc);
    return 0;
}