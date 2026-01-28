// -----------------Leet Code problem - First repeated character in a string.-------------------

#include<stdio.h>

typedef struct item{
    char ch;
    int freq;
    int occ;
}item;

int hash(char ch){
    return ch % 30;
}

void prt(item table[]){
    for(int i = 0; i < 30; i++){
        if(table[i].occ == 1){
            printf("%c = %d\n", table[i].ch, table[i].freq);
        }
    }
}

int main(){
    char string[] = {'a', ' ', 'g', 'r', 'e', 'e', 'n', ' ', 'a', 'p', 'p', 'l', 'e', '\0'};
    item table[30];
    for(int i = 0; i < 30; i++){
        table[i].occ = 0;
    }
    int i = 0;
    while(string[i] != '\0'){
        int index = hash(string[i]);
        if(table[index].occ == 1 && table[index].ch == string[i]){
            (table[index].freq)++;
            i++;
            continue;
        }
        while(table[index].occ == 1){
            index = (index + 1) % 30;
        }
        table[index].ch = string[i];
        table[index].freq = 1;
        table[index].occ = 1;
        i++;
    }
    i = 0;
    while(string[i] != '\0'){
        int index = hash(string[i]);
        while(table[index].ch != string[i]){
            index = (index + 1) % 30;
        }
        if(table[index].freq > 1){
            printf("First Repeated character: %c", table[index].ch);
            break;
        }
        i++;
    }
    // prt(table);
    return 0;
}