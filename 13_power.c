// ---------------------Calculate the result of x to the power n. (Uncomment to  execute)-----------------

// -------------------First Version (Recursive Method)------------

/*
#include<stdio.h>

int out(int num, int pwr){
    if(pwr == 0){
        return 1;
    }else{
        return num * out(num, (pwr-1));
    }
}

int main(){
    int num, pwr;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the power of number: ");
    scanf("%d", &pwr);
    if(num < 0 || pwr < 0){
        printf("Invalid Input.");
        return 0;
    }
    if(num == 0 && pwr == 0){
        printf("Please enter a valid power.");
        return 0;
    }
    printf("Answer: %d", out(num, pwr));
    return 0;
}
*/



// -------------------Second Version (Iterative Method)------------

/*
#include<stdio.h>

int out(int num, int pwr){
    int out = 1;
    for(int i = pwr; i; i--){
        out *= num;
    }
    return out;
}

int main(){
    int num, pwr;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the power of number: ");
    scanf("%d", &pwr);
    if(num < 0 || pwr < 0){
        printf("Invalid Input.");
        return 0;
    }
    if(num == 0 && pwr == 0){
        printf("Please enter a valid power.");
        return 0;
    }
    printf("Answer: %d", out(num, pwr));
    return 0;
}
*/



// -------------------Third Version (Iterative Method)------------

/*
#include<stdio.h>

int out(int num, int pwr){
    if(pwr == 0){
        return 1;
    }
    int half = out(num, (pwr/2));
    if((pwr & 1) == 0){
        return half * half;
    }else{
        return num * half * half;
    }
}

int main(){
    int num, pwr;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the power of number: ");
    scanf("%d", &pwr);
    if(num < 0 || pwr < 0){
        printf("Invalid Input.");
        return 0;
    }
    if(num == 0 && pwr == 0){
        printf("Please enter a valid power.");
        return 0;
    }
    printf("Answer: %d", out(num, pwr));
    return 0;
}
*/