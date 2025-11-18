#include<stdio.h>
#include<stdlib.h>

struct my_array{
    int total_size;
    int used_size;
    int *ptr;
};

void create(struct my_array *marks, int total_size, int used_size){
    marks->total_size = total_size;
    marks->used_size = used_size;
    marks->ptr = (int *) malloc(total_size * sizeof(int));
}

void set(struct my_array *marks){
    for(int i = 0; i < marks->used_size; i++){
        printf("Enter the value for index %d: ", i);
        scanf("%d", (marks->ptr+i));
    }
}

void show(struct my_array *marks){
    for(int i = 0; i < marks->used_size; i++){
        printf("Value at index %d: %d\n", i, *(marks->ptr+i));
    }
}

int main(){
    int total_size, used_size;
    printf("Enter the size of array: ");
    scanf("%d", &total_size);
    printf("Enter the size you want to utilize now: ");
    scanf("%d", &used_size);
    struct my_array marks;
    create(&marks, total_size, used_size);
    set(&marks);
    show(&marks);
    return 0;
}