// ----------Learning about Pre-order tree traversal.---------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create(int data){
    node *curr = malloc(sizeof(node));
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

void insert(node **curr, int data){
    if(*curr == NULL){
        *curr = create(data);
        return;
    }
    if(data > (*curr)->data){
        insert(&(*curr)->right, data);
    }else{
        insert(&(*curr)->left, data);
    }
}

void prt(node *curr){
    if(curr == NULL){
        return;
    }
    printf("%d ", curr->data);
    prt(curr->left);
    prt(curr->right);
}

int main(){
    node *root = NULL;
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 10);
    prt(root);
    return 0;
}