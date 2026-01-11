// ----------------Leet Code problem - Valid Parantheses---------------

#include<stdio.h>

void push(char stk[], int *stkptr, char ch){
    if(*stkptr >= 100){
        printf("Stack Overflowed\n");
        return;
    }
    stk[(*stkptr)++] = ch;
}

char pop(char stk[], int *stkptr){
    if(*stkptr <= 0){
        printf("Not Balanced ");
        return '\0';
    }
    return stk[--(*stkptr)];
}

int main(){
    char string[] = {'[', '(', ')', ']', '{', '}', '{', '[', '(', ')', ']', '(', ')', '}', '\0'};
    char stk[100];
    int stkptr = 0;
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] == '[' || string[i] == '{' || string[i] == '('){
            push(stk, &stkptr, string[i]);
            i++;
            continue;
        }
        if(string[i] == '}' || string[i] == ']' || string[i] == ')'){
            char ch = pop(stk, &stkptr);
            if(ch == '\0'){
                return 0;
            }
            if(string[i] == '}' && ch != '{'){
                printf("Not Balanced\n");
                return 0;
            }
            if(string[i] == ']' && ch != '['){
                printf("Not Balanced\n");
                return 0;
            }
            if(string[i] == ')' && ch != '('){
                printf("Not Balanced\n");
                return 0;
            }
            i++;
        }
    }
    if(stkptr <= 0){
        printf("Balanced\n");
    }else{
        printf("Not Balanced\n");
    }
    return 0;
}