// --------------Leet Code problem - Find whether a linked list is cyclic or not.-----------------

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

void link(node *head){
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
}

void cyclic(node *head){
    node *fast = head;
    node *slow = head;
    while(1){
        if(fast == NULL || slow == NULL || fast->next == NULL){
            printf("List is not cyclic.\n");
            return;
        }
        fast = (fast->next)->next;
        slow = slow->next;
        if(fast == slow){
            printf("List is cyclic.\n");
            return;
        }
    }
}

int main(){
    node *head = NULL;
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    link(head);
    cyclic(head);
    return 0;
}