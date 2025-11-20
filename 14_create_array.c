#include<stdio.h>
#include<stdlib.h>

struct my_array{
    int total_size;
    int used_size;
    int *ptr;
};

void create(struct my_array *marks){
    printf("Enter the size of array: ");
    scanf("%d", &marks->total_size);
    printf("Enter the size you want to utilize now: ");
    scanf("%d", &marks->used_size);
    marks->ptr = (int *) malloc(marks->total_size * sizeof(int));
}

void set(struct my_array *marks){
    for(int i = 0; i < marks->used_size; i++){
        printf("Enter the value for index %d: ", i);
        scanf("%d", marks->ptr+i);
    }
}

void show(struct my_array *marks){
    for(int i = 0; i < marks->used_size; i++){
        printf("Value at index %d: %d\n", i, *(marks->ptr+i));
    }
}

int main(){
    struct my_array marks;
    create(&marks);
    set(&marks);
    show(&marks);
    return 0;
}