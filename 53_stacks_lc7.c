// ---------------Leet Code problem - Redundant Brackets.--------------------

#include<stdio.h>

void push(char stack[], int *stkptr, char ch){
    if(*stkptr >= 10){
        printf("Stack Overflowed\n");
        return;
    }
    stack[(*stkptr)++] = ch;
}

char pop(char stack[], int *stkptr){
    if(*stkptr == 0){
        return '\0';       
    }
    (*stkptr)--;
    return stack[*stkptr];
}

int main(){
    char string[] = {'(', 'a', '*', 'b', ')', '\0'};
    char stack[10];
    int stkptr = 0;            
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] >= 'a' && string[i] <= 'z'){
            i++;
            continue;;
        }
        if(string[i] == '(' || string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/'){
            push(stack, &stkptr, string[i]);
            i++;
            continue;
        }
        if(string[i] == ')'){
            char ch = pop(stack, &stkptr);
            if(ch == '\0' || ch == '('){
                printf("Redundant\n");
                return 0;
            }else{
                ch = pop(stack, &stkptr);
                while(ch != '('){
                    ch = pop(stack, &stkptr);
                }
            }
            i++;
        }
    }
    printf("No Redundancy\n");
    return 0;
}