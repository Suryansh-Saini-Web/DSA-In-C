// --------------Leet Code problem - Reverse First K elements of Queue.------------------------

#include<stdio.h>

void enqueue(int queue[], int *count, int *rear, int value){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    (*count)++;
    queue[(*rear)++] = value;
    *rear = (*rear) % 10;
}

int dequeue(int queue[], int *count, int *front){
    if(*count == 0){
        printf("Queue Underflowed\n");
        return -1;
    }
    (*count)--;
    int num = queue[*front]; 
    (*front)++;
    *front = (*front) % 10;
    return num;
}

void prt(int queue[], int count, int front){
    printf("[");
    while(count){
        front = front % 10;
        printf("%d", queue[front++]);
        if(count > 1){
            printf(", ");
        };
        count--;
    }
    printf("]\n");
}

void init(int queue[], int *count, int *rear){
    enqueue(queue, count, rear, 1);
    enqueue(queue, count, rear, 2);
    enqueue(queue, count, rear, 3);
    enqueue(queue, count, rear, 4);
    enqueue(queue, count, rear, 5);
}

void reverse(int queue[], int *count, int *rear, int *front, int K){
    if(*count == 0 || K == 0){
        return;
    }
    int num = dequeue(queue, count, front);
    reverse(queue, count, rear, front, (K - 1));
    enqueue(queue, count, rear, num);
    return;
}

int main(){
    int K = 3;
    int queue[10];
    int count = 0;
    int front = 0;
    int rear = 0;
    init(queue, &count, &rear);
    prt(queue, count, front);
    reverse(queue, &count, &rear, &front, K);
    int loop = count - K;
    while(loop--){
        int num = dequeue(queue, &count, &front);
        enqueue(queue, &count, &rear, num);
    }
    prt(queue, count, front);
    return 0;
}