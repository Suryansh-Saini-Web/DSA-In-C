// --------------Learning about Vertical Order Traversal--------------

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

typedef struct Qnode{
    node *node;
    int hd;
}Qnode;

Qnode queue[10];
int Qcount = 0, rear = 0, front = 0;

void enqueue(node *node, int hd){
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
    Qcount++;
    rear = rear % 10;
}

Qnode dequeue(){
    Qcount--;
    Qnode temp = queue[front++];
    front = front % 10;
    return temp;
}

int arr[20][10];
int count[20] = {0};
int offset = 10;

void trav(node *root){
    if(root == NULL){
        return;
    }
    enqueue(root, 0);
    while(Qcount > 0){
        Qnode temp = dequeue();
        node *curr = temp.node;
        int hd = temp.hd;
        arr[hd + offset][count[hd + offset]++] = curr->data;
        if(curr->left){
            enqueue(curr->left, hd - 1);
        }
        if(curr->right){
            enqueue(curr->right, hd + 1);
        }
    }
    for(int i = 0; i < 20; i++){
        
        if(count[i] > 0){
            for(int j = 0; j < count[i]; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
}

int main(){
    node *root = NULL;
    insert(&root, 12);
    insert(&root, 16);
    insert(&root, 2);
    insert(&root, 9);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 17);
    insert(&root, 25);
    trav(root);
    return 0;
}