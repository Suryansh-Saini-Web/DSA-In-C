// -------------Leet code problem - Min stack - Find the minimum value in stack using O(1) space complexity.----------------

#include<stdio.h>

void push(int stack[], int *stkptr, int *min, int num){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    if(*stkptr == 0){
        *min = num;
        stack[(*stkptr)++] = num;
    }else if(num >= *min){
        stack[(*stkptr)++] = num;
    }else{
        stack[(*stkptr)++] = (2 * num) - *min;
        *min = num;
    }
}

void pop(int stack[], int *stkptr, int *min){
    if(*stkptr == 0){
        printf("Stack Underflowed\n");
        return;
    }
    (*stkptr)--;
    int popped = stack[(*stkptr)];
    if(popped >= *min){
        printf("Popped: %d\n", popped);
    }else{
        printf("Popped: %d\n", *min);
        *min = (2 * (*min)) - popped;
    }
}
 
int main(){
    int stack[10];
    int stkptr = 0;
    int min;
    push(stack, &stkptr, &min, 3);
    push(stack, &stkptr, &min, 2);
    push(stack, &stkptr, &min, 1);
    printf("Min = %d\n", min);
    pop(stack, &stkptr, &min);
    printf("Min = %d\n", min);
    return 0;
}