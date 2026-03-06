// --------------Learning about Level Order Traversal.------------------

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
    if((*curr)->data > data){
        insert(&(*curr)->left, data);
    }else{
        insert(&(*curr)->right, data);
    }
}

void traverse(node *curr){
    if(curr != NULL){
        enqueue(queue, &count, &rear, curr);
    }
    while(count > 0){
        curr = dequeue(queue, &count, &front);
        printf("%d ", curr->data);
        if(curr->left != NULL){
            enqueue(queue, &count, &rear, curr->left);
        }
        if(curr->right != NULL){
            enqueue(queue, &count, &rear, curr->right);
        }
    }
}

int main(){
    node *root = NULL;
    insert(&root, 10);
    insert(&root, 8);
    insert(&root, 15);
    insert(&root, 1);
    insert(&root, 9);
    insert(&root, 13);
    insert(&root, 18);
    insert(&root, 16);
    insert(&root, 20);
    traverse(root);
    return 0;
}