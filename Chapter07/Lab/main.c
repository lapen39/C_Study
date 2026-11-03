#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int calculate_gcd(int x, int y);

void calculate_halflife(int halflife);

// void find_right_triangle(int a, int b, int c);

// double calc_pi(int loop);

void calc_interest(int investment, double rate, int year);

int main(void){
    // 최대 공약수
    int x=25, y=10;
    int gcd=calculate_gcd(x, y);

    printf("gcd = %d\n", gcd);

    // 반감기
    int halflife=10;
    
    calculate_halflife(halflife);

    // 숫자 추측 게임(난수 발생기 시드 설정? 그게 뭔데)

    // // 직각 삼각형 찾기
    // int a, b, c;
    
    // find_right_triangle(a, b, c);

    // // 파이 구하기
    // int loop=10000000;
    // double pi=calc_pi(loop);

    // printf("pi = %f\n", pi);

    // 복리 이자 계산
    int investment=1000000, year=10;
    double rate=5.0;
    
    calc_interest(investment, rate, year);

    // 자동으로 수학문제 생성(난수는 진짜 뭔말인지 모르겠음;;)

    // 도박 확률(또 난수...)

    return 0;
}

int calculate_gcd(int x, int y){
    while (y != 0){
        int r;

        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void calculate_halflife(int halflife){
    double i=100.0, current=100.0;
    int years=0;

    while (current > (i / 10.0)){
        years += halflife;
        current /= 2.0;

        printf("remain after %d years = %f\n", years, current);
    }
    
    printf("time to under 1/10 = %d years\n", years);
}

// void find_right_triangle(int a, int b, int c){
//     for (a = 1; a <= 100; a++){
//         for (b = 1; b <= 100; b++){
//             for (c = 1; c <= 100; c++){
//                 if ((a * a + b * b) == c * c) printf("%d %d %d\n", a, b, c);
//             }
//         }
//     }
// }

// double calc_pi(int loop){
//     double divisor=1.0, divident=4.0, sum=0.0;

//     for (int i = 0; i < loop; i++){
//         sum += divident / divisor;
//         divident *= (-1.0);
//         divisor += 2.0;
//     }

//     return sum;
// }

void calc_interest(int investment, double rate, int year){
    double total;

    rate /= 100.0;
    total = investment;
    
    for (int i=0; i < year; i++){
        total *= (1 + rate);

        printf("%2d   %10.1f\n", i + 1, total);
    }
}