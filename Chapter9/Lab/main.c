#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void save(int amount);

int gcd(int x, int y);

int main(void){
    // 은행 계좌 구현
    printf("==========================\n");
    printf("input\touput\tamount\n");
    printf("==========================\n");

    save(10000);
    save(50000);
    save(-10000);
    save(30000);
    printf("==========================\n");

    // 최대공약수 계산
    printf("%d\n", gcd(30, 20));

    return 0;
}

void save(int amount){
    static long balance=0;

    if (amount >= 0){
        printf("%d\t\t", amount);
    }
    else{
        printf("\t%d\t", -amount);
    }

    balance += amount;

    printf("%d\n", balance);
}

int gcd(int x, int y){
    if (y == 0) return x;
    else        return gcd(y, x % y);
}