// -------------Building my own Binary Search Tree.------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}node;

node *create(int data){
    node *curr = malloc(sizeof(node));
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

// Insertion using Iterative approach

// void insert(node **root, int data){
//     node *new = create(data);
//     if(*root == NULL){
//         *root = new;
//     }else{
//         node *curr = *root;
//         node *prev = NULL;
//         int left = 0;
//         while(curr != NULL){
//             if(curr->data < data){
//                 prev = curr;
//                 left = 0;
//                 curr = curr->right;
//             }else{
//                 prev = curr;
//                 left = 1;
//                 curr = curr->left;
//             }
//         }
//         if(left){
//             prev->left = new;
//         }else{
//             prev->right = new;
//         }
//     }
// }

// Insertion using recursion
void insert(node **curr, int data){
    if(*curr == NULL){
        node *new = create(data);
        *curr = new;       
        return;
    }
    if((*curr)->data < data){
        insert(&((*curr)->right), data);
    }else{
        insert(&((*curr)->left), data);
    }
}

void prt(node *curr){
    if(curr == NULL){
        return;
    }
    prt(curr->left);
    printf("%d ", curr->data);
    prt(curr->right);
}

int main(){
    node *root = NULL;
    insert(&root, 5);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 15);
    prt(root);
    return 0;
}