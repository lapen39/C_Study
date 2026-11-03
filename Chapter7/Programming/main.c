#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// void timer(int initial);

void calc_sum(void);

double get_pow(float r, int n);

int main(void){
    // // 1번 문제
    // int initial=10;

    // timer(initial);

    // 2번 문제
    calc_sum();

    // 3번 문제(scanf() 안 쓰기엔 애매함)

    // 4번 문제(배열 써야할거 같음)

    // 5번 문제
    float r=2.0;
    int n=10;
    double result=get_pow(r, n);

    printf("%f ^ %d = %f\n", r, n, result);

    return 0;
}

// void timer(int initial){
//     for (int i=0; i < 10; i++){
//         printf("%d ", initial);
//         Sleep(1000);
//         initial--;
//     }

//     printf("\a");
// }

void calc_sum(void){
    int total=0;

    for (int i=0; i < 100; i++){
        if (i % 3 == 0){
            total += i;
        }
    }

    printf("sum of 1~100 3's multiple = %d\n", total);
}

double get_pow(float r, int n){
    return pow(r, n);
}