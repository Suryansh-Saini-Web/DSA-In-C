// ---------------Learning about Morris Postorder Traversal------------------------

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

TreeNode *FindPostorderPredecessor(TreeNode *PostorderPredecessor, TreeNode *curr){
    while(PostorderPredecessor->right != NULL && PostorderPredecessor->right != curr){
        PostorderPredecessor = PostorderPredecessor->right;
    }
    return PostorderPredecessor;
}

void reverse(TreeNode *from, TreeNode *to){
    if(from == to){
        return;
    }
    TreeNode *x = from, *y = from->right, *z;
    while(1){
        z = y->right;
        y->right = x;
        x = y;
        y = z;
        if(x == to){
            break;
        }
    }
}

void PrintReverse(TreeNode *from, TreeNode *to){
    reverse(from, to);
    TreeNode *temp = to;
    while(1){
        printf("%d ", temp->data);
        if(temp == from){
            break;
        }
        temp = temp->right;
    }
    reverse(to, from);
}

void MorrisPostorderTraversal(TreeNode *root){
    TreeNode dummy;
    dummy.left = root;
    dummy.right = NULL;
    TreeNode *curr = &dummy;
    while(curr != NULL){
        if(curr->left == NULL){
            curr = curr->right;
        }else{
            TreeNode *PostorderPredecessor = FindPostorderPredecessor(curr->left, curr);
            if(PostorderPredecessor->right == NULL){
                PostorderPredecessor->right = curr;
                curr = curr->left;
            }else{
                PrintReverse(curr->left, PostorderPredecessor);
                PostorderPredecessor->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main(){
    TreeNode *root = NULL;
    InsertTreeNode(&root, 15);
    InsertTreeNode(&root, 12);
    InsertTreeNode(&root, 19);
    InsertTreeNode(&root, 7);
    InsertTreeNode(&root, 16);
    InsertTreeNode(&root, 11);
    InsertTreeNode(&root, 23);
    printf("Morris Postorder Traversal: ");
    MorrisPostorderTraversal(root);
    return 0;
}