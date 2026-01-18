// -----------------Creating my own Queue data structure using arrays.----------------------

#include<stdio.h>

void enqueue(int queue[], int *count, int *rear, int value){
    if(*count == 10){
        printf("Queue Overflowed\n");
        return;
    }
    int i = 0;
    int loop = *count;
    while(loop--){
        if(queue[(*rear) - (i + 1)] <= value){
            break;
        }else{
            queue[(*rear) - i] = queue[(*rear) - (1 + i)];
            i++;
        }
    }
    (*count)++;
    queue[(*rear) - i] = value;
    (*rear)++;
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

int main(){
    int queue[10];
    int count = 0;
    int front = 0;
    int rear = 0;
    enqueue(queue, &count, &rear, 11);
    enqueue(queue, &count, &rear, 10);
    enqueue(queue, &count, &rear, 9);
    enqueue(queue, &count, &rear, 8);
    prt(queue, count, front);
    return 0;
}