// ----------------Find whether a number is power of 2 or not. (Uncomment to execute) -------------------------

// ----------------------First Version-------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a Number: ");
    scanf("%d", &input);
    if(input <= 0){
        printf("It is not a power of 2.\n");
    }else{
        while(input != 0){
            if(input == 1){
                printf("It is a power of 2.\n");
                return 0;
            }
            if((input % 2) != 0){
                printf("It is not a power of 2.\n");
                return 0;
            }
            input /= 2;
        }
    }
    return 0;
}
*/



// ----------------------Second Version-------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a Number: ");
    scanf("%d", &input);
    if(input <= 0){
        printf("It is not a power of 2.\n");
    }else if(input == 1){
        printf("It is a power of 2.\n");
    }else if((input & 1) == 1){
        printf("It is not a power of 2.\n");
    }else{
        int count = 0;
        while(input != 0){
            input = input >> 1;
            if((input & 1) == 1){
                count++;
            }
            if(count > 1){
                printf("It is not a power of 2.\n");
                return 0;
            }
        }
        if(count == 1){
            printf("It is a power of 2.\n");
        }
    }
    return 0;
}
*/



// ----------------------Third Version-------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input <= 0){
        printf("It is not a power of 2.");
    }else{
        while(input != 0){
            int lastbit = input & 1;
            input = input >> 1;
            if(lastbit == 1 && input != 0){
               printf("It is not a power of 2.");
               return 0;
            }
        }
        printf("It is a power of 2.");
    }
    return 0;
}
*/



// ----------------------Fourth Version-------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input > 0 && (input & (input-1)) == 0){
        printf("It is a power of 2.");
    }else{
        printf("It is not power of 2.");
    }
    return 0;
}
*/