// --------------Leet Code problem - Reverse List in K Groups-----------------

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

int check_null(node *head, int k){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
        if(count == k){
            break;
        }
    }
    if(count >= k){
        return 1;
    }else{
        return 0;
    }
}

node *reverse(node *head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    int move = 0;
    node *temp = head;
    move = check_null(temp, k);
    if(move == 0){
        return head;
    }
    node *prev = NULL;
    node *next = NULL;
    node *curr = head;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    head->next = reverse(curr, k);
    return prev;
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
    int k = 4;
    head = reverse(head, k);
    print(head);
    return 0;
}