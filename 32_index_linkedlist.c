// ----------------Learning how to insert a value at a particular index in a linked list.-----------------------

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

void error(){
    printf("Enter a valid index.");
    exit(0);
}

void insert(node **head, int value, int index){
    if(index < 0){
        error();
    }
    node *curr = create(value);
    if(index == 0){
        curr->next = *head;
        *head = curr;
        return;
    }else{
        node *temp = *head;
        for(int i = 0; i < index; i++){
            if(temp == NULL){
                error();
            }
            if(i == index - 1){
                curr->next = temp->next;
                temp->next = curr;
                return;
            }
            temp = temp->next;  
        }
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
    insert(&head, 18, 0);
    insert(&head, 22, 1);
    insert(&head, 24, 2);
    insert(&head, 11, 0);
    print(head);
    return 0;
}