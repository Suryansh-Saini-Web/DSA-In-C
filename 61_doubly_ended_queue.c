// ----------------Designing Doubly Ended Queue.---------------

#include<stdio.h>

void pushTop(int queue[], int *count, int *rear, int num){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    (*count)++;
    queue[(*rear)++] = num;
    *rear = (*rear) % 10;
}

int pullTop(int queue[], int *count, int *rear){
    if(*count == 0){
        printf("Queue Underflowed\n");
        return -1;
    }
    (*count)--;
    (*rear)--;
    if(*rear == -1){
        *rear = 9;
    }
    return queue[*rear];
}

void pushBottom(int queue[], int *count, int *front, int num){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    (*count)++;
    (*front)--;
    if(*front == -1){
        *front = 9;
    }
    queue[*front] = num;
}

int pullBottom(int queue[], int *count, int *front){
    if(*count == 0){
        printf("Queue Underflowed\n");
        return -1;
    }
    (*count)--;
    int num = queue[(*front)++];
    *front = (*front) % 10;
    return num;
}

int getBottom(int queue[], int count, int front){
    if(count == 0){
        printf("Queue Empty\n");
        return -1;
    }
    return queue[front];
}

int getTop(int queue[], int count, int rear){
    if(count == 0){
        printf("Queue Empty\n");
        return -1;
    }
    rear--;
    if(rear == -1){
        rear = 9;
    }
    return queue[rear];
}

int main(){
    int queue[10];
    int count = 0;
    int rear = 0;
    int front = 0;
    pushBottom(queue, &count, &front, 1);
    pushTop(queue, &count, &rear, 2);
    printf("%d\n", getTop(queue, count, rear));
    printf("%d\n", getBottom(queue, count, front));
    pullBottom(queue, &count, &front);
    pullTop(queue, &count, &rear);
    return 0;
}