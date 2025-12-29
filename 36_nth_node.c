// ------------Remove Nth node from end of the list.----------------

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

void insert(node **head, int *count, int value){
    node *curr = create(value);
    curr->next = *head;
    *head = curr;
    (*count)++;
}

void print(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void delete(node **head, int count, int n){
    if(count == 0 || n <= 0 || n > count){
        printf("Invalid Input.\n");
        exit(0);
    }
    int loop = count - n;
    node *curr = *head;  
    if(loop == 0){
        *head = curr->next;
        free(curr);
    }else{
        node *prev = NULL;
        node *next = NULL;
        for(int i = 0; i < loop; i++){
            prev = curr;
            curr = curr->next;
        }
        next = curr->next;
        free(curr);
        prev->next = next;
    }
}

int main(){
    node *head = NULL;
    int count = 0;
    insert(&head, &count, 19);
    insert(&head, &count, 18);
    insert(&head, &count, 17);
    insert(&head, &count, 16);
    insert(&head, &count, 15);
    print(head);
    printf("\n");
    delete(&head, count, 4);
    print(head);
    return 0;
}