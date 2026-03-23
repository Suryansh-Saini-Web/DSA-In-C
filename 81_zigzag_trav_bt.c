// ---------------Learning about Zig-Zag Traversal--------------

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *queue[10];
int count = 0;
int front = 0;
int rear = 0;

void enqueue(node *queue[], int *count, int *rear, node *value){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    (*count)++;
    queue[(*rear)++] = value;
    *rear = (*rear) % 10;
}

node *dequeue(node *queue[], int *count, int *front){
    if(*count == 0){
        printf("Queue Underflowed\n");
        return NULL;
    }
    (*count)--;
    node *num = queue[*front]; 
    (*front)++;
    *front = (*front) % 10;
    return num;
}

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
    enqueue(queue, &count, &rear, *curr);
    while(count > 0){
        node *temp = dequeue(queue, &count, &front);
        if(temp->left == NULL){
            temp->left = create(data);
            return;
        }else{
            enqueue(queue, &count, &rear, temp->left);
        }
        if(temp->right == NULL){
            temp->right = create(data);
            return;
        }else{
            enqueue(queue, &count, &rear, temp->right);
        }
    }
}

void trav(node *curr){
    while(count != 0){
        dequeue(queue, &count, &front);
    }
    if(curr == NULL){
        return;
    }
    int flag = 0;
    enqueue(queue, &count, &rear, curr);
    while(count > 0){
        int size = count;
        int arr[20];
        for(int i = 0; i < size; i++){
            node *temp = dequeue(queue, &count, &front);
            arr[i] = temp->data;
            if(temp->left != NULL){
                enqueue(queue, &count, &rear, temp->left);
            }
            if(temp->right != NULL){
                enqueue(queue, &count, &rear, temp->right);
            }
        }
        if(flag == 0){
            for(int i = 0; i < size; i++){
                printf("%d ", arr[i]);
            }
        }else{
            for(int i = size - 1; i >= 0; i--){
                printf("%d ", arr[i]);
            }
        }
        flag = !flag;
    }
}

int main(){
    node *root = NULL;
    insert(&root, 23);
    insert(&root, 13);
    insert(&root, 16);
    insert(&root, 7);
    insert(&root, 4);
    insert(&root, 9);
    insert(&root, 5);
    insert(&root, 19);
    insert(&root, 27);
    insert(&root, 23);
    trav(root);
    return 0;
}