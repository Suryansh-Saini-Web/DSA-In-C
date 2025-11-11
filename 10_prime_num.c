// -----------------Find whether a number is prime or not. (Uncomment to execute)----------------

/*
#include<stdio.h>
#include<math.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input <= 1){
        printf("It is not a prime number.");
    }else if(input <= 3){
        printf("It is a prime number.");
    }else if((input & 1) == 0 || input % 3 == 0){
        printf("It is not a prime number.");
    }else{
        int limit = sqrt(input);
        for(int i = 5; i <= limit; i += 6){
            if(input % i == 0 || input % (i+2) == 0){
                printf("It is not a prime number.");
                return 0;
            }
        }
        printf("It is a prime numeber.");
    }
    return 0;
}
*/