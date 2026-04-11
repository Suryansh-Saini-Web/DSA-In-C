// ---------------Leet Code Question - Minimum time taken to burn Binary Tree--------------------

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode *create(int data){
    TreeNode *new = malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void InsertTreeNode(TreeNode **root, int data){
    if(*root == NULL){
        *root = create(data);
        return;
    }
    if((*root)->data > data){
        InsertTreeNode(&(*root)->left, data);
    }else{
        InsertTreeNode(&(*root)->right, data);
    }
}

int hash(TreeNode *key){
    return ((unsigned long)key) % 20;
}

typedef struct MapNode{
    TreeNode *key;
    TreeNode *value;
    struct MapNode *next;
}MapNode;

MapNode *ChildParentMap[20] = {NULL};

void StoreParent(TreeNode *child, TreeNode *parent){
    if(child == NULL){
        return;
    }
    int index = hash(child);
    MapNode *new = malloc(sizeof(MapNode));
    new->key = child;
    new->value = parent;
    new->next = ChildParentMap[index];
    ChildParentMap[index] = new;
    StoreParent(child->left, child);
    StoreParent(child->right, child);
}

TreeNode *FindTarget(TreeNode *root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        return root;
    }
    TreeNode *target = FindTarget(root->left, value);
    if(target == NULL){
        target = FindTarget(root->right, value);
    }
    return target;
}

TreeNode *queue[20];
int count = 0, front = 0, rear = 0;

void enqueue(TreeNode *node){
    queue[rear++] = node;
    count++;
    rear = rear % 20;
}

TreeNode *dequeue(){
    TreeNode *temp = queue[front++];
    count--;
    front = front % 20;
    return temp;
}

typedef struct VisitNode{
    TreeNode *node;
    struct VisitNode *next;
}VisitNode;

VisitNode *VisitMap[20] = {NULL};

void MarkVisited(TreeNode *node){
    int index = hash(node);
    VisitNode *new = malloc(sizeof(VisitNode));
    new->node = node;
    new->next = VisitMap[index];
    VisitMap[index] = new;
}

int IsVisited(TreeNode *node){
    int index = hash(node);
    VisitNode *temp = VisitMap[index];
    while(temp != NULL){
        if(temp->node == node){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

TreeNode *GetParent(TreeNode *child){
    int index = hash(child);
    MapNode *temp = ChildParentMap[index];
    while(temp != NULL){
        if(temp->key == child){
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

int BurnTree(TreeNode *root, int target){
    if(root == NULL){
        return 0;
    }
    StoreParent(root->left, root);
    StoreParent(root->right, root);
    TreeNode *TargetNode = FindTarget(root, target);
    enqueue(TargetNode);
    MarkVisited(TargetNode);
    int TimeSec = 0;
    while(count > 0){
        int burned = 0;
        int size = count;
        for(int i = 0; i < size; i++){
            TreeNode *curr = dequeue();
            if(curr->left && !IsVisited(curr->left)){
                enqueue(curr->left);
                MarkVisited(curr->left);
                burned = 1;
            }
            if(curr->right && !IsVisited(curr->right)){
                enqueue(curr->right);
                MarkVisited(curr->right);
                burned = 1;
            }
            TreeNode *parent = GetParent(curr);
            if(parent && !IsVisited(parent)){
                enqueue(parent);
                MarkVisited(parent);
                burned = 1;
            }
        }
        if(burned){
            TimeSec++;
        }
    }
    return TimeSec;
}

int main(){
    TreeNode *root = NULL;
    InsertTreeNode(&root, 19);
    InsertTreeNode(&root, 17);
    InsertTreeNode(&root, 21);
    InsertTreeNode(&root, 23);
    InsertTreeNode(&root, 15);
    InsertTreeNode(&root, 6);
    InsertTreeNode(&root, 32);
    int TimeSec = BurnTree(root, 23);
    printf("Time taken (in seconds) to burn the tree: %d", TimeSec);
    return 0;
}