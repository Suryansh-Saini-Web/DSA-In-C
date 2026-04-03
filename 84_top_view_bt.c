// --------------------Learning about Top View----------------

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
int offset = 10;
int count[20] = {0};

void store(node *root, int hd){
    if(root == NULL){
        return;
    }
    if(count[hd + offset] == 0){
        arr[hd + offset][0] = root->data;
        count[hd + offset]++;
    }
    store(root->left, hd - 1);
    store(root->right, hd + 1);
}

void topView(node *root){
    if(root == NULL){
        return;
    }
    store(root, 0);
    for(int i = 0; i < 20; i++){
        if(count[i] > 0){
            printf("%d ", arr[i][0]);
        }
    }
}

int main(){
    node *root = NULL;
    insert(&root, 25);
    insert(&root, 29);
    insert(&root, 16);
    insert(&root, 31);
    insert(&root, 19);
    insert(&root, 17);
    insert(&root, 13);
    insert(&root, 7);
    topView(root);
    return 0;
}