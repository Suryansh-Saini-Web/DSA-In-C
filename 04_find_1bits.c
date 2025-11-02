//------------------- Q2 - Write a function that takes an unsigned integer and returns the number of '1' bits it has. (Uncomment to execute)--------------------------

// ---------------First Version - Using Arithmetic Operators-----------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        int count = 0;
        while(input){
            if(input % 2 == 1){
                count++;
            }
            input /= 2;
        }
        printf("It has %d '1' bits.", count);
    }
    return 0;
}
*/



// ---------------Second Version - Using Bitwise Operators-----------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        int count = 0;
        while(input){
            if(input & 1 == 1){
                count++;
            }
            input = input >> 1;
        }
        printf("Number of '1' bit: %d", count);
    }
    return 0;
}
*/




// ---------------Third Version - Using Bitwise Operators-----------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        int count = 0;
        while(input){
            input &= (input - 1);
            count++;
        }
        printf("It has %d '1' bits.", count);
    }
    return 0;
}
*/