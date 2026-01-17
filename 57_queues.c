// -----------------Creating my own Queue data structure using arrays.----------------------

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

int peek(){

}

int isEmpty(){

}

int isFull(){

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
    enqueue(queue, &count, &rear, 6);
    enqueue(queue, &count, &rear, 7);
    enqueue(queue, &count, &rear, 8);
    enqueue(queue, &count, &rear, 9);
    enqueue(queue, &count, &rear, 10);
    enqueue(queue, &count, &rear, 11);
    dequeue(queue, &count, &front);
    enqueue(queue, &count, &rear, 11);
    prt(queue, count, front);
    return 0;
}