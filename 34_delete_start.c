// ----------------Delete node from Beginning.--------------------

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
}

void delete(node **head){
    if(*head == NULL){
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main(){
    node *head = NULL;
    insert(&head, 19);
    insert(&head, 18);
    insert(&head, 21);
    print(head);
    delete(&head);
    printf("\n");
    print(head);
    return 0;
}