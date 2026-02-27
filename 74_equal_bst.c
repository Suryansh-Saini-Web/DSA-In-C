// ------------Check whether both the trees are equal or not. -------------

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

int equal(node *first, node *second){
    if(first == NULL && second == NULL){
        return 1;
    }
    if(first != NULL && second != NULL){
        if(first->data == second->data){
            if(equal(first->left, second->left) == 0 || equal(first->right, second->right) == 0){
                return 0;
            }else{
                return 1;
            }
        }else{
            return 0;
        }
    }else{
        return 0;
    }  
}

int main(){
    node *tree1 = NULL;
    node *tree2 = NULL;
    insert(&tree1, 11);
    insert(&tree1, 13);
    insert(&tree1, 7);
    insert(&tree2, 11);
    insert(&tree2, 7);
    insert(&tree2, 13);
    int ans = equal(tree1, tree2);
    if(ans){
        printf("Both Trees are equal.\n");
    }else{
        printf("Both Trees are not equal.\n");
    }
    return 0;
}