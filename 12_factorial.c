// -------------------Find factorial of a number. (Uncomment to execute)----------------

// -------------------First Version (Recursive Method)-------------------

/*
#include<stdio.h>

long long int factorial(int input){
    if(input <= 1){
        return 1;
    }else{
        return input * factorial(input-1);
    }
}

int main(){
    int input;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        printf("Factorial: %lld", factorial(input));
    }
    return 0;
}
*/



// -------------------Second Version (Iterative Method)------------------- 

/*
#include<stdio.h>

long long int factorial(int input){
    long long int out = 1;
    for(int i = input; i > 1; i--){
        out *= i;
    }
    return out;
}

int main(){
    int input;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        printf("Factorial: %lld", factorial(input));
    }
    return 0;
}
*/