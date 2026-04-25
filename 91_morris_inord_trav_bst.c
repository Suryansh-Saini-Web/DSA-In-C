// --------------Learning about Morris Inorder Traversal-----------

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
    }else{
        if((*root)->data > data){
            InsertTreeNode(&(*root)->left, data);
        }else{
            InsertTreeNode(&(*root)->right, data);
        }
    }
}

TreeNode *FindInorderPredecessor(TreeNode *InorderPredecessor, TreeNode *curr){
    while(InorderPredecessor->right != NULL && InorderPredecessor->right != curr){
        InorderPredecessor = InorderPredecessor->right;
    }
    return InorderPredecessor;
}

void MorrisInorderTraversal(TreeNode *root){
    TreeNode *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            printf("%d ", curr->data);
            curr = curr->right;
        }else{
            TreeNode *InorderPredecessor = FindInorderPredecessor(curr->left, curr);
            if(InorderPredecessor->right == NULL){
                InorderPredecessor->right = curr;
                curr = curr->left;
            }else{
                InorderPredecessor->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }
    }
}

int main(){
    TreeNode *root = NULL;
    InsertTreeNode(&root, 6);
    InsertTreeNode(&root, 5);
    InsertTreeNode(&root, 4);
    InsertTreeNode(&root, 1);
    InsertTreeNode(&root, 3);
    InsertTreeNode(&root, 7);
    InsertTreeNode(&root, 2);
    printf("Morris Inorder Traversal: ");
    MorrisInorderTraversal(root);
    return 0;
}