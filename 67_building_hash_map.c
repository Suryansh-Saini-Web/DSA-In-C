// ----------------Designing my own Hash Map.------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    int position;
    struct node *next;
}node;

int hash(char ch){
    return ch % 30;
}

node *create(char ch, int pos){
    node *curr = malloc(sizeof(node));
    curr->ch = ch;
    curr->position = pos;
    curr->next = NULL;
    return curr;
}

void put(node *table[], char ch, int pos){
    int index = hash(ch);
    node *curr = create(ch, pos);
    curr->next = table[index];
    table[index] = curr;
}

void map(node *table[]){
    for(int i = 0; i < 30; i++){
        if(table[i] == NULL){
            continue;
        }else{
            node *curr = table[i];
            while(curr != NULL){
                printf("Character: %c, Position: %d\n", curr->ch, curr->position);
                curr = curr->next;
            }
        }
    }
}

void get(node *table[], char ch){
    int index = hash(ch);
    node *curr = table[index];
    if(curr != NULL){
        while(curr->ch != ch){
            curr = curr->next;
        }
        printf("Character: %c, Position: %d\n", ch, curr->position);
    }else{
        printf("NULL\n");
    } 
}

void rmv(node *table[], char ch){
    int index = hash(ch);
    if(table[index] == NULL){
        printf("NULL\n");
    }else{
        node *curr = table[index];
        node *prev = NULL;
        while(curr->ch != ch){
            prev = curr;
            curr = curr->next;
            if(curr == NULL){
                printf("NULL\n");
                return;
            }
        }
        if(prev == NULL){
            table[index] = curr->next;
            printf("Removed\n");
        }else{
            prev->next = curr->next;
            printf("Removed\n");
        }
    }
}

int main(){
    node *table[30] = {NULL};
    put(table, 'a', 1);
    put(table, 'b', 2);
    put(table, 'c', 3);
    put(table, 'd', 4);
    get(table, 'd');
    rmv(table, 'd');
    map(table);
    return 0;
}