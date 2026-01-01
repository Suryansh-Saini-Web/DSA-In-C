// --------------Leet Code problem 24 - Swap Nodes in Pairs-----------------

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

node *swap(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *prev = head;
    head = head->next;
    node *next = head->next;
    next = swap(next);
    head->next = prev;
    prev->next = next;
    return head;
}
int main(){
    node *head = NULL;
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    print(head);
    printf("\n");
    head = swap(head);
    print(head);
    return 0;
}