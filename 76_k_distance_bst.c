// --------------Find all the nodes in the Binary Tree that are at K distance.------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

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

void find(node *curr, int k){
    if(curr == NULL || k < 0){
        return;
    }
    if(k == 0){
        printf("%d ", curr->data);
        return;
    }
    find(curr->left, k-1);
    find(curr->right, k-1);
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
    find(root, 3);
    return 1;
}