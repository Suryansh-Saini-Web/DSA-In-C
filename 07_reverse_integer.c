// --------------- Reverse an integer (Uncomment to execute) ----------------------

// ------------------First Version -------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a Number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.\n");
    }else if(input == 0){
        printf("Reversed Number: 0");
    }else{
        printf("Reversed Number: ");
        while(input != 0){
            int output = input % 10;
            printf("%d", output);
            input /=  10;
        } 
    }
    return 0;
}
*/



// ------------------Second Version -------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a Number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.\n");
    }else{
        int output = 0;
        while(input != 0){
            int digit = input % 10;
            output = output * 10 + digit;
            input /=  10;
        } 
        printf("Reversed Number: %d", output);
    }
    return 0;
}
*/