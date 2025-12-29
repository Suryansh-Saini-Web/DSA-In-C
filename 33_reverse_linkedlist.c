// ----------------------First Version (Uncomment to Execute----------------------

/*
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
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(node **head){
    if(*head == NULL){
        return;
    }
    node *curr = (*head)->next;
    (*head)->next = NULL;
    node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = *head;
        *head = curr;
        curr = next;
    }
}

int main(){
    node *head = NULL;
    insert(&head, 18);
    insert(&head, 17);
    insert(&head, 16);
    insert(&head, 15);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}
*/

// ----------------------Second Version----------------------

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
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(node **head){
    node *curr = *head;
    node *prev = NULL;
    node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main(){
    node *head = NULL;
    insert(&head, 18);
    insert(&head, 17);
    insert(&head, 16);
    insert(&head, 15);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}
