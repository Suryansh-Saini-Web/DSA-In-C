// -----------Leet Code Problem - 876 (Middle of the linked list)-----------------

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

node *middle(node *head){
    if(head == NULL || head->next == NULL || (head->next)->next == NULL){
        printf("Error - No middle found.\n");
        exit(0);
    }
    node *fast = head;
    node *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow;
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
    head = middle(head);
    print(head);
    return 0;
}