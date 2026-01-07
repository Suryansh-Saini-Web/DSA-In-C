// --------------Leet Code problem - Detect and remove loop in linked list.-----------------

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

void rmv(node *ptr1, node *ptr2, node *ptr3){
    // ptr1 = head, ptr2 and ptr3 = meeting point
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // Now, ptr1 and ptr2 are at starting point of loop
    while(ptr3->next != ptr1){
        ptr3 = ptr3->next;
    }
    ptr3->next = NULL;
    printf("Loop Removed.\n");
}

void detect(node *head){
    node *fast = head;
    node *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = (fast->next)->next;
        slow = slow->next;
        if(fast == slow){
            printf("Loop Detected.\n");
            rmv(head, fast, slow);
            return;
        }
    }
    printf("There is no loop.\n");
}

void print(node *head){
    if(head == NULL){
        return;
    }
    printf("%d ", head->data);
    print(head->next);
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
    // You can comment this above "link" function to find whether code is working or not.
    detect(head);
    print(head);
    return 0;
}