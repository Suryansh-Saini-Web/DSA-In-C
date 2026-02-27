// -----------------Find Minimum value in the binary search tree.-----------------

#include<stdio.h>
#include<stdlib.h>

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

int min(node *curr){
    if(curr == NULL){
        return -1;
    }
    if(curr->left == NULL){
        return curr->data;
    }else{
        return min(curr->left);
    }
}

int main(){
    node *root = NULL;
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 9);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 10);
    printf("Minimum Value: %d\n", min(root));
    return 0;
}