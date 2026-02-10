// -----------Find whether an element is present in the Binary Search Tree.----------------------

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
    if((*curr)->data < data){
        insert(&(*curr)->right, data);
    }else{
        insert(&(*curr)->left, data);
    }
}

void find(node *curr, int value){
    if(curr == NULL){
        printf("Not found\n");
        return;
    }
    if(curr->data == value){
        printf("Found\n");
        return;
    }
    if(value > curr->data){
        find(curr->right, value);
    }else{
        find(curr->left, value);
    }
}

// void prt(node *curr){
//     if(curr == NULL){
//         return;
//     }
//     prt(curr->left);
//     printf("%d ", curr->data);
//     prt(curr->right);
// }

int main(){
    node *root = NULL;
    insert(&root, 1);
    insert(&root, 5);
    insert(&root, 1);
    insert(&root, 17);
    insert(&root, 19);
    insert(&root, 6);
    insert(&root, 13);
    find(root, 13);
    // prt(root);
    return 0;
}