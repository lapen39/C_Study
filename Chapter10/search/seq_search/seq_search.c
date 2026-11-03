#include <stdio.h>

#define SIZE 10

void seq_search(int list[], int size, int key);

int main(void){
    // 순차 탐색
    int key=6;
    int list[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    seq_search(list, SIZE, key);

    return 0;
}

void seq_search(int list[], int size, int key){
    for (int i = 0; i < size; i++){
        if (list[i] == key) printf("%d index: %d\n", key, i);
    }
}