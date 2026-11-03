#define _USE_MATH_DEFINES

#define D_SIZE 6
#define P_SIZE 10
#define ROW 3
#define COL 5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void rand_dice(int freq[], int n);

void rand_price(int prices[], int size);
int find_min(int prices[], int size);

void rand_s(int s[][COL], int row, int col);

int main(void){
    // 주사위 던지기
    int freq[D_SIZE]={0};

    rand_dice(freq, 1000);

    printf("==================\n");
    printf("num\tfreqency\n");
    printf("==================\n");

    for (int i = 0; i < D_SIZE; i++){
        printf("%d\t%d\n", i + 1, freq[i]);
    }

    // 극장 예약 시스템 (scanf() 사용)

    // 최솟값 찾기
    int prices[P_SIZE]={0};

    printf("===================================\n");
    printf("1  2  3  4  5  6  7  8  9  10\n");
    printf("===================================\n");

    rand_price(prices, P_SIZE);

    int minimum=find_min(prices, P_SIZE);

    printf("minimum: %d\n", minimum);

    // 2차원 배열
    int s[ROW][COL];

    rand_s(s, ROW, COL);

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%02d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void rand_dice(int freq[], int n){
    for (int i = 0; i < n; i++){
        ++freq[rand() % 6];
    }
}

void rand_price(int prices[], int size){
    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++){
        prices[i] = (rand() % 100) + 1;
        
        printf("%d ", prices[i]);
    }
    printf("\n");
}
int find_min(int prices[], int size){
    int min=prices[0];

    for (int i = 0; i < size; i++){
        if (prices[i] < min) min = prices[i];
    }
    return min;
}

void rand_s(int s[][COL], int row, int col){
    srand((unsigned int)time(NULL));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            s[i][j] = rand() % 100;
        }
    }
}