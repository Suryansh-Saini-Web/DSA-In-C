// ----------------Leet Code problem - Reverse String---------------

#include<stdio.h>

void push(char stk[], int *stkptr, char ch){
    if(*stkptr >= 15){
        printf("Stack Overflowed\n");
        return;
    }
    stk[(*stkptr)++] = ch;
}

char pop(char stk[], int *stkptr){
    if(*stkptr <= 0){
        printf("Stack Underflowed");
        return '\0';
    }
    return stk[--(*stkptr)];
}

int main(){
    char stk[15];
    int stkptr = 0;
    push(stk, &stkptr, 'S');
    push(stk, &stkptr, 'U');
    push(stk, &stkptr, 'R');
    push(stk, &stkptr, 'Y');
    push(stk, &stkptr, 'A');
    printf("%c", pop(stk, &stkptr));
    printf("%c", pop(stk, &stkptr));
    printf("%c", pop(stk, &stkptr));
    printf("%c", pop(stk, &stkptr));
    printf("%c", pop(stk, &stkptr));
    return 0;
}