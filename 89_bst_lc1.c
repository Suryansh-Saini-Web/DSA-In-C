// --------------Leet code question - Least Common Ancestor of Binary Tree-----------------------

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

node *lca(node *root, int val1, int val2){
    if(root == NULL){
        return NULL;
    }
    if(val1 == root->data || val2 == root->data){
        return root;
    }
    node *left = lca(root->left, val1, val2);
    node *right = lca(root->right, val1, val2);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL){
        return right;
    }else{
        return left;
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
    int val1 = 1;
    int val2 = 4;
    node *ans = lca(root, val1, val2);
    if(ans == NULL){
        printf("Least common ancestor of %d and %d is: NULL", val1, val2);
    }else{
        printf("Least common ancestor of %d and %d is: %d", val1, val2, ans->data); 
    }
    return 0;
}