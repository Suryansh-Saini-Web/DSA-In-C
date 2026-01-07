// --------------Leet Code problem - Remove duplicates from sorted linked list.-----------------

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

void delete(node *head){
    node *prev = head;
    node *curr = prev->next;
    node *next = curr->next;
    prev->next = next;
    free(curr);
}

void duplicate(node *head){
    while(head != NULL && head->next != NULL){
        if(head->data == (head->next)->data){
            delete(head);
        }else{
            head = head->next;
        }
    }
}

int main(){
    node *head = NULL;
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 1);
    duplicate(head);
    print(head);
    return 0;
}