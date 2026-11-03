#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void get_dice_face(void);

void get_random(void);

int get_sum(int a);

int power(int base, int power_raised);

void show_digit(int n);

double recursive(int a);

int fib(int n);

int main(void){
    // 1번 문제 (scanf() 사용해야 함)

    // 2번 문제
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 100; i++){
        get_dice_face();
    }

    // 3번 문제 (scanf())

    // 4번 문제
    for (int i = 0; i < 3; i++){
        get_random();
    }

    // 5번 문제 (다른 파일 만들어야 함)

    // 6번 문제
    int a=10;

    int sum=get_sum(a);

    printf("sum of 1 to %d = %d\n", a, sum);

    // 7번 문제
    int base=2, power_raised=10;

    int result_power=power(base, power_raised);

    printf("%d^%d = %d\n", base, power_raised, result_power);

    // 8번 문제
    int n=1234;

    show_digit(n);

    printf("\n");

    // 9번 문제 (문자열 내용 포함됨)

    // 10번 문제(6번 문제의 int a=10 사용)
    double result_recursive=recursive(a);

    printf("%f\n", result_recursive);

    // 11번 문제(6번 문제의 int a=10 사용)
    int result_fib;

    for (int i = 0; i <= a; i++){
        result_fib=fib(i);
        printf("fib(%d) = %d\n", i, result_fib);
    }

    return 0;
}

void get_dice_face(void){
    static int count[6]={0}; // 각 면이 나온 횟수
    static int call=0; // 함수 호출 횟수
    int face=rand() % 6;

    count[face]++; // 해당 면의 횟수 증가
    call++; // 함수 호출 횟수 증가

    if (call == 100){ // 100번째 호출이면 결과 출력
        for (int i = 0; i < 6; i++){
            printf("%d->%d\n", i + 1, count[i]);
        }
    }
}

void get_random(void){
    static int inited=0;

    if (inited == 0){
        printf("reset\n");
        
        srand((unsigned int)time(NULL));
        inited = 1;
    }
    printf("%d\n", rand());
}

int get_sum(int a){
    if (a < 1) return 0; // 합에서는 0(0을 더하는건 상관없어서)
    else       return a + get_sum(a - 1);
}

int power(int base, int power_raised){
    if (power_raised < 1) return 1; // 곱에서는 1(0을 곱하면 전체 결과가 0이 돼서)
    else                  return base * power(base, power_raised - 1);
}

void show_digit(int n){
    if (n > 0){
        show_digit(n / 10); // show_digit()은 n > 0이 거짓이 될 때까지 호출
        printf("%d ", n % 10); // 재귀 호출이 끝나면 실행
    }
    /*
    print(1234)
     ├─ print(123) 호출  ← 먼저 실행, 끝나길 기다림
     │   ├─ print(12) 호출
     │   │   ├─ print(1) 호출
     │   │   │   ├─ print(0) 호출 → a > 0 거짓, 아무것도 안 하고 끝
     │   │   │   └─ printf(1 % 10) → "1" 출력
     │   │   └─ printf(12 % 10) → "2" 출력
     │   └─ printf(123 % 10) → "3" 출력
     └─ printf(1234 % 10) → "4" 출력
    */
}

double recursive(int a){
    if (a < 1) return 0;
    else       return 1.0 / a + recursive(a - 1);
}

int fib(int n){
    if      (n == 0) return 0;
    else if (n == 1) return 1;
    else             return fib(n - 1) + fib(n - 2);
}