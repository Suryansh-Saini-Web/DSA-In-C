// --------------Leet Code problem - First negative integer in every window of size K--------------------

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

int peek(int queue[], int count, int front){
    if(count == 0){
        return -1;
    }else{
        return queue[front];
    }
}

void prt(int result[], int index){
    printf("[");
    for(int i = 0; i < index; i++){
        printf("%d", result[i]);
        if((index - i) > 1){
            printf(", ");
        }
    }
    printf("]");
}

int main(){
    int N = 5;
    int A[] = {-8, 2, 3, -6, 10};
    int K = 2;
    int queue[10];
    int count = 0;
    int front = 0;
    int rear = 0;
    int result[N];
    int index = 0;
    int i = 0;
    for(int j = 0; j < N; j++){
        if(A[j] < 0){
            enqueue(queue, &count, &rear, j);
        }
        if((j - i + 1) < K){
            continue;
        }
        int val = peek(queue, count, front);
        if(count != 0 && val < i){
            dequeue(queue, &count, &front);
        }
        if(count != 0){
            result[index++] = A[val];
        }else{
            result[index++] = 0;
        }
        i++;
    }
    prt(result, index);
    return 0;
}