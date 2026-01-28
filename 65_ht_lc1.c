// ---------------Leet Code hash table problem - First non repeated character in string.--------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    int freq;
    struct node *next;
}node;

int hash(char ch){
    return ch % 30;
}

node *create(char ch){
    node *curr = malloc(sizeof(node));
    curr->ch = ch;
    curr->freq = 1;
    curr->next = NULL;
    return curr;
}

void insert(node *table[], int index, char ch){
    if(table[index] == NULL){
        node *curr = create(ch);
        table[index] = curr;
    }else{
        node *curr = table[index];
        if(curr->ch == ch){
            (curr->freq)++;
        }else{
            node *new = create(ch);
            new->next = curr;
            table[index] = new;
        }
    }
}

void prt(node *table[]){
    node *curr;
    for(int i = 0; i < 30; i++){
        curr = table[i];
        while(curr != NULL){
            printf("%c = %d\n", curr->ch, curr->freq);
            curr = curr->next;
        }
    }
}

int main(){
    char string[] = {'a', ' ', 'g', 'r', 'e', 'e', 'n', ' ', 'a', 'p', 'p', 'l', 'e', '\0'};
    node *table[30] = {NULL};
    int i = 0;
    while(string[i] != '\0'){
        int index = hash(string[i]);
        insert(table, index, string[i]);
        i++;
    }
    i = 0;
    while(string[i] != '\0'){
        int index = hash(string[i]);
        node *curr = table[index];
        while(curr->ch != string[i]){
            curr = curr->next;
        }
        if(curr->freq == 1){
            printf("First Non-Repeated character: %c", curr->ch);
            break;
        }
        i++;
    }
    // prt(table);
    return 0;
}