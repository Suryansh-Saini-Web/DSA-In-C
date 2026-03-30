// ---------------Learning about Boundary Traversal.----------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *queue[10];
int count = 0;
int front = 0;
int rear = 0;

void enqueue(node *queue[], int *count, int *rear, node *value){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    (*count)++;
    queue[(*rear)++] = value;
    *rear = (*rear) % 10;
}

node *dequeue(node *queue[], int *count, int *front){
    if(*count == 0){
        printf("Queue Underflowed\n");
        return NULL;
    }
    (*count)--;
    node *num = queue[*front]; 
    (*front)++;
    *front = (*front) % 10;
    return num;
}

node *create(int data){
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(node **curr, int data){
    if(*curr == NULL){
        *curr = create(data);
        return;
    }
    enqueue(queue, &count, &rear, *curr);
    while(count > 0){
        node *temp = dequeue(queue, &count, &front);
        if(temp->left == NULL){
            temp->left = create(data);
            return;
        }else{
            enqueue(queue, &count, &rear, temp->left);
        }
        if(temp->right == NULL){
            temp->right = create(data);
            return;
        }else{
            enqueue(queue, &count, &rear, temp->right);
        }
    }
}

void left_trav(node *curr){
    if(curr == NULL){
        return;
    }
    printf("%d ", curr->data);
    left_trav(curr->left);
    left_trav(curr->right);
}

void right_trav(node *curr){
    if(curr == NULL){
        return;
    }
    right_trav(curr->left);
    right_trav(curr->right);
    printf("%d ", curr->data);
}

void trav(node *curr){
    if(curr == NULL){
        return;
    }
    printf("%d ", curr->data);
    left_trav(curr->left);
    right_trav(curr->right);
}

int main(){
    node *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 8);
    trav(root);
    return 0;
}