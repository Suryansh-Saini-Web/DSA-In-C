// ----------------Learning about Post Order Tree Traversal---------------------

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
    }else{
        if((*curr)->data > data){
            insert(&(*curr)->left, data);
        }else{
            insert(&(*curr)->right, data);
        }
    }
}

void trav(node *curr){
    if(curr == NULL){
        return;
    }
    trav(curr->left);
    trav(curr->right);
    printf("%d ", curr->data);
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
    trav(root);
    return 0;
}