// ----------------Determining Height and Depth of a Node in the Tree-------------------

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
    }else{
        if((*curr)->data > data){
            insert(&(*curr)->left, data);
        }else{
            insert(&(*curr)->right, data);
        }
    }
}

int depth(node *curr, int val){
    int depth = -1;
    int found = 0;
    while(curr != NULL){
        depth++;
        if(curr->data == val){
            found = 1;
            break;
        }
        if(curr->data > val){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    if(found){
        return depth;
    }else{
        return -1;
    }
}

node *findNode(node *curr, int val){
    if(curr == NULL){
        return NULL;
    }
    if(curr->data == val){
        return curr;
    }else if(curr->data > val){
        return findNode(curr->left, val);
    }else{
        return findNode(curr->right, val);
    }
}

int findHt(node *curr){
    if(curr == NULL){
        return -1;
    }
    int left = findHt(curr->left);
    int right = findHt(curr->right);
    if(left > right){
        return 1 + left;
    }else{
        return 1 + right;
    }
}

int height(node *curr, int val){
    node *target = findNode(curr, val);
    if(target == NULL){
        return -1;
    }else{
        return findHt(target);
    }
}

int main(){
    node *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 3);
    printf("Depth: %d\n", depth(root, 20));
    printf("Height: %d", height(root, 11));
    return 0;
}