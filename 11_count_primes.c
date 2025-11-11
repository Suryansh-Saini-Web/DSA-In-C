// --------------------LeetCode problem 204 - Count Primes - Given an integer n, find the number of prime numbers that are strictly less than n. (Uncomment to execute)-----------------------

// -------------------First Version--------------------------

/*
#include<stdio.h>
#include<math.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    printf("Prime Number Count: ");
    int count = 0;
    if(input <= 1){
        printf("%d", count);
    }else if(input <= 3){
        count++;
    }else if(input <= 4){
        count += 2;
    }else{
        input--;
        while(input){
            if(input <= 3){
                count += 2;
                break;
            }else if((input & 1) == 0 || input % 3 == 0){
                input--;
                continue;
            }else{
                int limit = sqrt(input);
                int found = 0;
                for(int i = 5; i <= limit; i += 6){
                    if(input % i == 0 || input % (i+2) == 0){
                        found = 1;
                        input--;
                        break;
                    }
                }
                if(!found){
                    count++;
                    input--;
                }
            }   
        }
    } 
    printf("%d", count);
    return 0;
}
*/



// ------------------------Second Version (Sieve of Eratosthenes)------------------------------

/*
#include<stdio.h>

int main(){
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    int count = 0;
    printf("Prime Number Count: ");
    if(input <= 1){
        printf("%d", count);
    }else{
        int prime[input];
        for(int i = 0; i < input; i++){
            prime[i] = 1;
        }
        prime[0] = prime[1] = 0;
        for(int i = 2; i*i <= input; i++){
            if(prime[i]){
                for(int j = i*i; j < input; j += i){
                    prime[j] = 0;
                }
            }
        }
        for(int i = 2; i < input; i++){
            if(prime[i]){
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}
*/