// -----------------Check whether a Binary Search Tree is valid or not. -----------------

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node *left; 
    struct node *right; 
}node;

node *create(int val){
    node *new = malloc(sizeof(node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insert(node **curr, int val){
    if(*curr == NULL){
        *curr = create(val);
        return;
    }
    if((*curr)->data > val){
        insert(&(*curr)->left, val);
    }else{
        insert(&(*curr)->right, val);
    }
}

int validate(node *curr, int min, int max){
    if(curr == NULL){
        return 1;
    }
    if(curr->data >= min && curr->data < max){
        return (validate(curr->left, min, curr->data) && validate(curr->right, curr->data, max));
    }
    return 0;
}

int main(){
    node *root = NULL;
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 9);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 10);
    int min = LONG_MIN;
    int max = LONG_MAX;
    int ans = validate(root, min, max);
    if(ans){
        printf("Tree is Valid\n");
    }else{
        printf("Tree is not valid\n");
    }
    return 0;
}