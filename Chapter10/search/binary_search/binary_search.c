#include <stdio.h>

#define SIZE 16

int binary_search(int grade[], int size, int key);

int main(void){
    // 이진 탐색
    int key=34;
    int grade[SIZE]={2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};

    int result=binary_search(grade, SIZE, key);

    printf("%d index: %d\n", key, result);
}

int binary_search(int grade[], int size, int key){
    int low=0, high=size-1, middle;

    while (low <= high){ // low <= high: 탐색 범위([low, high])
        printf("[%d %d]\n", low, high);

        middle = (low + high) / 2;

        if      (key == grade[middle]) return middle;
        else if (key > grade[middle])  low = middle + 1; // 중간 원소보다 key가 크다면 low 새로 설정
        else                           high = middle - 1;
    }
    return -1;
}