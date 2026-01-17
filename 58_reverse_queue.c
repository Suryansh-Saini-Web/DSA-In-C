// -----------------Reverse Queue.----------------------

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

void reverse(int queue[], int *count, int *front, int *rear){
    if(*count <= 1){
        return;
    }
    int num = dequeue(queue, count, front);
    reverse(queue, count, front, rear);
    enqueue(queue, count, rear, num);
}

int main(){
    int queue[10];
    int count = 0;
    int front = 0;
    int rear = 0;
    enqueue(queue, &count, &rear, 1);
    enqueue(queue, &count, &rear, 2);
    enqueue(queue, &count, &rear, 3);
    enqueue(queue, &count, &rear, 4);
    enqueue(queue, &count, &rear, 5);
    prt(queue, count, front);
    reverse(queue, &count, &front, &rear);
    prt(queue, count, front);
    return 0;
}