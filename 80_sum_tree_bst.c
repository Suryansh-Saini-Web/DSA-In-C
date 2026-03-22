// ------------Find whether a Binary Tree is Sum Tree or not.------------

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

int sumTree(node *curr, int *tree){
    if(curr->left == NULL && curr->right == NULL){
        return curr->data;
    }
    int left = 0;
    int right = 0;
    if(curr->left != NULL){
        left = sumTree(curr->left, tree);
    }
    if(curr->right != NULL){
        right = sumTree(curr->right, tree);
    }
    int sum = left + right;
    if(curr->data != sum){
        *tree = 0;
    }
    return sum + curr->data; 
}

int checkTree(node *curr){
    if(curr == NULL){
        return 1;
    }
    int tree = 1; 
    sumTree(curr, &tree);
    return tree;
}

int main(){
    node *root = NULL;
    insert(&root, 160);
    insert(&root, 40);
    insert(&root, 40);
    insert(&root, 20);
    insert(&root, 20);
    insert(&root, 20);
    insert(&root, 20);
    if(checkTree(root)){
        printf("This Binary Tree is a Sum Tree.\n");
    }else{
        printf("This Binary Tree is not a Sum Tree.\n");
    }
    return 0;
}