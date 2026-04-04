// -------------Learning about Right View of Binary Tree.----------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
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

int arr[20][1];
int count[20] = {0};

void store(node *root, int idx){
    if(root == NULL){
        return;
    }
    if(count[idx] == 0){
        arr[idx][0] = root->data;
        count[idx] = 1;
    }
    store(root->right, idx + 1);
    store(root->left, idx + 1);
}

void rtVu(node *root){
    if(root == NULL){
        return;
    }
    store(root, 0);
    for(int i = 0; i < 20; i++){
        if(count[i]){
            printf("%d ", arr[i][0]);
        }
    }
}

int main(){
    node *root = NULL;
    insert(&root, 15);
    insert(&root, 13);
    insert(&root, 17);
    insert(&root, 19);
    insert(&root, 6);
    insert(&root, 3);
    insert(&root, 20);
    insert(&root, 0);
    rtVu(root);
    return 0;
}