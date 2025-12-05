// -----------------Learning how to create hash tables from scratch in C.--------------------------

// ---------- Question - Find out how many times each number occurs in the array.-------------------

// ---------------Version 1 - Collision handling using Linked list - (Uncomment to execute)-----------------

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    int freq;
    struct node *next;
} node;

int hash(int num, int tab_size){
    if(num < 0){
        num = -num;
    }
    return num % tab_size;
}

int main(){
    int arr[] = {-1, 5, 4, 4, 3, 4, 3, 0, 0};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int tab_size = arr_len * 2;
    node *table[tab_size];
    for(int i = 0; i < tab_size; i++){
        table[i] = NULL;
    }
    for(int i = 0; i < arr_len; i++){
        int index = hash(arr[i], tab_size);
        node *curr = table[index];
        while(curr != NULL){
            if(curr->num == arr[i]){
                curr->freq++;
                break;
            }
            curr = curr->next;
        }
        if(curr == NULL){
            node *newnode = (node *)malloc(sizeof(node));
            newnode->num = arr[i];
            newnode->freq = 1;
            newnode->next = table[index];
            table[index] = newnode;
        }
    }
    for(int i = 0; i < tab_size; i++){
        node *curr = table[i];
        while(curr != NULL){
            printf("%d occurs %d times.\n", curr->num, curr->freq);
            curr = curr->next;
        }
    }
    return 0;
}
*/



// ------------------------Version 2 - Collision handling using Linear probing-----------------

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num;
    int freq;
    int occup;
} item;

int hash(int tab_size, int num){
    if(num < 0){
        num = -num;
    }
    return num % tab_size;
}

void insert(item table[], int arr[], int arr_len, int tab_size){
    for(int i = 0; i < arr_len; i++){
        int index = hash(tab_size, arr[i]);
        while(table[index].occup == 1 && table[index].num != arr[i]){
            index = (index + 1) % tab_size;
        }
        if(table[index].occup == 0){
            table[index].num = arr[i];
            table[index].freq = 1;
            table[index].occup = 1;
        }else{
            table[index].freq++;
        }
    }
}


int main(){
    int arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int tab_size = arr_len * 2;
    item table[tab_size];
    for(int i = 0; i < tab_size; i++){
        table[i].num = 0;
        table[i].freq = 0;
        table[i].occup = 0;
    }
    insert(table, arr, arr_len, tab_size);
    for(int i = 0; i < tab_size; i++){
        if(table[i].occup == 1){
            printf("%d occurs %d times.\n", table[i].num, table[i].freq);
        }
    }
    return 0;
}