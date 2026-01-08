// -------------Creating my own stack data structure using linked list.----------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(int value){
    node *new = malloc(sizeof(node));
    new->data = value;
    new->next = NULL;
    return new;
}

void push(node **head, int num){
    node *curr = create(num);
    curr->next = *head;
    *head = curr;
}

void isempty(node *head){
    if(head == NULL){
        printf("True\n");
    }else{
        printf("False\n");
    }
}

void pop(node **head){
    if(*head == NULL){
        printf("Stack Underflowed\n");
        return;
    }
    node *temp = *head;
    printf("Popped: %d\n", temp->data);
    *head = temp->next;
    free(temp);
}

void peek(node *head){
    if(head == NULL){
        return;
    }
    printf("%d\n", head->data);
}

void print(node *head){
    printf("[");
    while(head != NULL){
        printf("%d", head->data);
        if(head->next != NULL){
            printf(", ");
        }
        head = head->next;
    }
    printf("]\n");
}

int main(){
    node *head = NULL;
    isempty(head);
    push(&head, 1);  
    push(&head, 2);  
    peek(head);
    pop(&head);
    print(head);
    return 0;
}