// --------------- Convert Binary Number to Decimal Number. (Uncomment to execute) ----------------

// ----------------------First Version ------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a Binary Number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a valid number.\n");
    }else{
        int weight = 1;
        int digit;
        int output = 0;
        while(input != 0){
            digit = input % 10;
            if(digit > 1){
                printf("You have not entered a Binary number.\n");
                return 0;
            }
            output += digit * weight;
            weight <<= 1;
            input /= 10;
        }
        if(digit <= 1){
            printf("Decimal Number = %d\n", output);
        }  
    }
    return 0;
}
*/