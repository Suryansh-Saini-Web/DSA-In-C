// ------------Traversing Linked List using recursion.----------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(int value){
    node *curr = malloc(sizeof(node));
    curr->data = value;
    curr->next = NULL;
    return curr;
}

void insert(node **head, int value){
    node *curr = create(value);
    curr->next = *head;
    *head = curr;
}

void print(node *head){
    if(head == NULL){
        return;
    }
    printf("%d ", head->data);
    print(head->next);
}

int main(){
    node *head = NULL;
    insert(&head, 19);
    insert(&head, 18);
    insert(&head, 17);
    insert(&head, 16);
    insert(&head, 15);
    print(head);
    return 0;
}