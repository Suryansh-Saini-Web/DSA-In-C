#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(int value){
    node *curr = (node *)malloc(sizeof(node));
    curr->data = value;
    curr->next = NULL;
    return curr;
}

void insert_start(node **head, node **tail, int value){
    node *curr = create(value);
    if(*head == NULL){
        *head = curr;
        *tail = curr;
    }else{
        curr->next = *head;
        *head = curr;
    }
}

void insert_end(node **head, node **tail, int value){
    node *curr = create(value);
    if(*tail == NULL){
        *head = curr;
        *tail = curr;
    }else{
        (*tail)->next = curr;
        *tail = curr;
    }
}

void print(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    node *head = NULL;
    node *tail = NULL;
    insert_start(&head, &tail, 18);
    insert_start(&head, &tail, 17);
    insert_end(&head, &tail, 19);
    insert_end(&head, &tail, 20);
    print(head);
    return 0;
}
