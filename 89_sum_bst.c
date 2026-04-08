// -------------Question - Sum of nodes on the longest path from root to leaf node.--------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}node;

typedef struct result{
    int sum;
    int ht;
}result;

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

result solve(node *root){
    result res;
    if(root == NULL){
        res.ht = 0;
        res.sum = 0;
        return res;
    }
    result left = solve(root->left);
    result right = solve(root->right);
    if(left.ht > right.ht){
        res.ht = left.ht + 1;
        res.sum = left.sum + root->data;
    }else if(right.ht > left.ht){
        res.ht = right.ht + 1;
        res.sum = right.sum + root->data;
    }else{
        res.ht = right.ht + 1;
        res.sum = (left.sum > right.sum ? left.sum : right.sum) + root->data;
    }
    return res;
}

int sum(node *root){
    result res = solve(root);
    return res.sum;
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
    printf("Sum: %d", sum(root));
    return 0;
}