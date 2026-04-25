// -------------------Learning about Morris Preorder Traversal-----------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *CreateTreeNode(int data){
    TreeNode *new = malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void InsertTreeNode(TreeNode **root, int data){
    if(*root == NULL){
        *root = CreateTreeNode(data);
        return;
    }
    if((*root)->data > data){
        InsertTreeNode(&(*root)->left, data);
    }else{
        InsertTreeNode(&(*root)->right, data);
    }
}

TreeNode *FindPreorderPredecessor(TreeNode *PreorderPredecessor){
    while(PreorderPredecessor->right != NULL){
        PreorderPredecessor = PreorderPredecessor->right;
    }
    return PreorderPredecessor;
}

void MorrisPreorderTraversal(TreeNode *root){
    TreeNode *curr = root;
    while(curr != NULL){
        printf("%d ", curr->data);
        if(curr->left != NULL){
            TreeNode *PreorderPredecessor = FindPreorderPredecessor(curr->left);
            PreorderPredecessor->right = curr->right;
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
}

int main(){
    TreeNode *root = NULL;
    InsertTreeNode(&root, 12);
    InsertTreeNode(&root, 19);
    InsertTreeNode(&root, 14);
    InsertTreeNode(&root, 9);
    InsertTreeNode(&root, 15);
    InsertTreeNode(&root, 6);
    printf("Morris Preorder Traversal: ");
    MorrisPreorderTraversal(root);
    return 0;
}