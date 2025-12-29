// ------------Reverse Linked List using Recursion.------------------


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

node *reverse(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *rest = reverse(head->next);
    node *next = head->next;
    next->next = head;
    head->next = NULL;
    return rest;
}

int main(){
    node *head = NULL;
    insert(&head, 19);
    insert(&head, 18);
    insert(&head, 17);
    insert(&head, 16);
    insert(&head, 15);
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
    return 0;
}