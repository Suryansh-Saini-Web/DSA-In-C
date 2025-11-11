// -------------------LeetCode problem - 1009 Complement of Base 10 integer (Uncomment to execute) ------------

// -----------First Version----------------

/*
#include<stdio.h>
#include<math.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else if(input == 0){
        printf("1");
    }else{
        int copy = input;
        int length = 0;
        while(copy != 0){
            length++;
            copy = copy >> 1;
        }
        int mask = (pow(2, length)) - 1;
        int complement = input ^ mask;
        printf("%d", complement);
    }
    return 0;
}
*/



// ---------------------Second Version---------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Please enter a positive number.");
    }else if(input == 0){
        printf("1");
    }else{
        int copy = input;
        int length = 0;
        while(copy != 0){
            length++;
            copy = copy >> 1;
        }
        int mask = (1 << length) - 1;
        int complement = input ^ mask;
        printf("%d", complement);
    }
    return 0;
}
*/