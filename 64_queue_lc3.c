// --------------Leet Code problem - Interleave the first half of the queue with the second half.------------------------

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
    enqueue(queue, count, rear, 6);
}

int main(){
    int queue[10];
    int queue2[10];
    int count = 0;
    int count2 = 0;
    int front = 0;
    int front2 = 0;
    int rear = 0;
    int rear2 = 0;
    init(queue, &count, &rear);
    prt(queue, count, front);
    int loop = count / 2;
    for(int i = 0; i < loop; i++){
        int num = dequeue(queue, &count, &front);
        enqueue(queue2, &count2, &rear2, num);
    }
    for(int i = 0; i < loop; i++){
        int num = dequeue(queue2, &count2, &front2);
        enqueue(queue, &count, &rear, num);
        int num2 = dequeue(queue, &count, &front);
        enqueue(queue, &count, &rear, num2);
    }
    prt(queue, count, front);
    return 0;
}