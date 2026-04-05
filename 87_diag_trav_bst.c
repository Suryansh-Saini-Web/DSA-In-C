// ---------------Learning about Diagonal Traversal of Binary Tree.------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}node;

node *create(int data){
    node *new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(node **root, int data){
    if(*root == NULL){
        *root = create(data);
        return;
    }
    if((*root)->data > data){
        insert(&(*root)->left, data);
    }else{
        insert(&(*root)->right, data);
    }
}

node *queue[10];
int front = 0, rear = 0, count = 0;

void enqueue(node *node){
    count++;
    queue[rear++] = node;
    rear = rear % 10;
}

node *dequeue(){
    count--;
    node *temp = queue[front++];
    front = front % 10;
    return temp;
}

void trav(node *root){
    if(root == NULL){
        return;
    }
    enqueue(root);
    while(count > 0){
        node *temp = dequeue();
        while(temp){
            printf("%d ", temp->data);
            if(temp->left){
                enqueue(temp->left);
            }
            temp = temp->right;
        }
    }
}

int main(){
    node *root = NULL;
    insert(&root, 8);
    insert(&root, 10);
    insert(&root, 3);
    insert(&root, 14);
    insert(&root, 13);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 4);
    trav(root);
    return 0;
}