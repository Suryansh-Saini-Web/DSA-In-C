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

void insert(node **head, int value, int *count){
    (*count)++;
    node *curr = create(value);
    curr->next = *head;
    *head = curr;
}

void sum(node *head){
    int value = 0;
    while(head != NULL){
        value += head->data;
        head = head->next;
    }
    printf("Sum: %d\n", value);
}

void find_value(node *head, int index, int count){
    if(index < count){
        for(int i = 0; i < index; i++){
            head = head->next;
        }
        printf("%d\n", head->data);
    }else{
        printf("Index out of range.\n");
    }
}

void find_index(node *head, int value){
    int index = 0;
    while(head != NULL){
        if(head->data == value){
            printf("%d", index);
            return;
        }else{
            index++;
            head = head->next;
        }
    }
    printf("Value not in the list.");
}

int main(){
    node *head = NULL;
    node *tail = NULL;
    int count = 0;
    insert(&head, 18, &count);
    insert(&head, 24, &count);
    insert(&head, 8, &count);
    sum(head);
    find_value(head, 2, count);
    find_index(head, 24);
    return 0;
}