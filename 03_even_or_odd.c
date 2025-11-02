// --------------Find whether the number provided, is even or odd.  (Uncomment to execute)---------------------

// ---------------------First Version - Using Remainder Method-----------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive numeber.");
    }else{
        if(input % 2 == 0){
            printf("It is an even number.");
        }else{
            printf("It is an odd number.");
        }
    }
    return 0;
}
*/




// ---------------------Second Version - Using Bitwise Operators-----------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input & 1 == 1){
        printf("The number is odd.\n");
    }else{
        printf("The number is even.");
    }
    return 0;
}
*/

// Operations done using Bitwise operators are faster than Arithmetic operators.



