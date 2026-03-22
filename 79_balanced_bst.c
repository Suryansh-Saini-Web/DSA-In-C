// ------------Find whether a Tree is Balanced or not.------------

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

int check(node *curr, int *balanced){
    if(curr == NULL || *balanced == 0){
        return 0;
    }
    int left = check(curr->left, balanced);
    int right = check(curr->right, balanced);
    int diff = left - right;
    if(diff < 0){
        diff = -diff;
    }
    if(diff > 1){
        *balanced = 0;
    }
    if(left > right){
        return left + 1;
    }else{
        return right + 1;
    }
}

int bal(node *curr){
    if(curr == NULL){
        return 1;
    }
    int balanced = 1;
    check(curr, &balanced);
    return balanced;
}

int main(){
    node *root = NULL;
    insert(&root, 13);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 14);
    insert(&root, 17);
    insert(&root, 6);
    if(bal(root)){
        printf("Tree is Balanced.\n");
    }else{
        printf("Tree is not Balanced");
    }
    return 0;
}