// ------------Find Diameter of the tree.-------------

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
 
int height(node *curr, int *ans){
    if(curr == NULL){
        return 0;
    }
    int left = height(curr->left, ans);
    int right = height(curr->right, ans);
    if(*ans < (left + right)){
        *ans = left + right;
    }
    if(left > right){
        return left + 1;
    }else{
        return right + 1;
    }
}

int diameter(node *curr){
    if(curr == NULL){
        return -1;
    }
    int ans = 0;
    height(curr, &ans);
    return ans;
}

int main(){
    node *root = NULL;
    insert(&root, 11);
    insert(&root, 14);
    insert(&root, 19);
    insert(&root, 16);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 24);
    printf("Diameter: %d", diameter(root));
    return 0;
}