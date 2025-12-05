// -------------------LeetCode problem - 1 (Two Sum) - Given an array "nums" and an integer "target", return indices of the two numbers such that they add up to "target".------------------

// ------------------------First Version (Uncomment to execute)-----------

/*
#include<stdio.h>

int main(){
    int arr[] = {3, 3};
    int target = 6;
    int length = 2;
    for(int i = 0; i < length; i++){
        for(int j = i+1; j < length; j++){
            if(arr[i] + arr[j] == target){
                printf("Index 1: %d\n", i);
                printf("Index 2: %d", j);
                break;
            }
        }
    }
    return 0;
}
*/


// ------------------------Second Version (using hash table)---------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    int index;
    struct node *next;
} node;

int hash(int key, int table_size){
    if(key < 0){
        key = -key;
    }
    return key % table_size;
}

void insert(node *table[], int table_size, int key, int index){
    int h = hash(key, table_size);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->key = key;
    newnode->index = index;
    newnode->next = table[h];
    table[h] = newnode;
}

int search(node *table[], int key, int table_size){
    int h = hash(key, table_size);
    node *curr = table[h];
    while(curr){
        if(curr->key == key){
            return curr->index;
        }
        curr = curr->next;
    }
    return -1;
}

int *two_sum(int arr[], int target, int length){
    int *result = malloc(2 * sizeof(int));
    int table_size = 2 * length;
    node *table[table_size];
    for(int i = 0; i < table_size; i++){
        table[i] = NULL;
    }
    for(int i = 0; i < length; i++){
        int complement = target - arr[i];
        int index = search(table, complement, table_size);
        if(index != -1){
            result[0] = index;
            result[1] = i;
            return result;
        }
        insert(table, table_size, arr[i], i);
    }
    return NULL;
}

int main(){
    int arr[] = {2, 7, 11, 15};
    int target = 18;
    int length = sizeof(arr) / sizeof(arr[0]);
    int *result = two_sum(arr, target, length);
    if(result){
        printf("Indices: %d, %d", result[0], result[1]);
        free(result);
    }else{
        printf("No solution found");
    }
    return 0;
}