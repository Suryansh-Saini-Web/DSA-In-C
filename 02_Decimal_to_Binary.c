// -----------------First Version - Using Division Method (Uncomment to execute) --------------------

/*
#include<stdio.h>

int main(){
    int input;
    int binary[32];
    int index = 0;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else if(input == 0){
        printf("0"); 
    }else{
        while(input){
            binary[index++] = input % 2;
            input /= 2;
        }
        printf("It's Binary is: ");
        for(int i = index - 1; i >= 0; i--){
            printf("%d", binary[i]);
        }
    }
    return 0;
}
*/



// -----------------Second Version - Using Bitwise Operators  (Uncomment to execute)--------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else{
        printf("It's Binary is: ");
        int started = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (input >> i) & 1;
            if(bit){
                started = 1;
            }
            if(started){
                printf("%d", bit);
            }
        }
        if(!started){
            printf("0");
        }
    }
    return 0;
}
*/