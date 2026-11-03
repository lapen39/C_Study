#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int calculate_divisor(int a1, int b1);

int get_min(int a2, int b2, int c2);

void height_and_age_limit(int height, int age);

void month_to_eng(int month);

void is_vowel(char letter);

double calculate_avg_weight(double height1);
void what_weight(double avg_weight, double weight);

int calculate_price(int time, int age1);

double calculate_fx(double x);

void quadrant(int x1, int y1);

int main(void){
    // 1번 문제: 약수 판별
    int a1=32, b1=8;
    int is_divisor=calculate_divisor(a1, b1);

    if (is_divisor == 1) printf("%d is %d's divisor\n", b1, a1);
    else                 printf("%d is not %d's divisor\n", b1, a1);

    // 2번 문제: 최솟값 결정
    int a2=30, b2=20, c2=10;
    int min_num=get_min(a2, b2, c2);

    printf("min num: %d\n", min_num);

    // 3번 문제: 가위바위보 게임(모르겠음..!!!)

    // 4번 문제: 놀이공원 키 제한
    int height=145, age=11;
    
    height_and_age_limit(height, age);

    // 5번 문제: 월 영어로 출력
    int month=10;
    
    month_to_eng(month);

    // 6번 문제: 모음-자음 구분
    char letter='o';

    is_vowel(letter);

    // 7번 문제: 저체중, 표준, 과체중 판단
    double height1=180.0, weight=80.0;
    double avg_weight=calculate_avg_weight(height1);
    
    what_weight(avg_weight, weight);

    // 8번 문제: 자유이용권 가격 계산
    int time=18, age1=33;
    int price=calculate_price(time, age1);

    printf("price: %d\n", price);

    // 9번 문제: 함수값 계산
    double x=3.0;
    double fx=calculate_fx(x);

    printf("f(%.2f) = %.2f\n", x, fx);

    // 10번 문제: 속하는 사분면 출력
    int x1=10, y1=20;

    quadrant(x1, y1);

    // 11번 문제: 줄임말 번역(대소문자 구분 없이 어케함....?)

    // 12번 문제: 복권(이건 또 뭐 어떻게 하는데;)

    return 0;
}

int calculate_divisor(int a1, int b1){
    if (a1 % b1 == 0) return 1;
    else              return 0;
}

int get_min(int a2, int b2, int c2){
    if (a2 < b2){
        if (a2 < c2) return a2;
        else return c2;
    }
    else{
        if (b2 < c2) return b2;
        else return c2;
    }
}

void height_and_age_limit(int height, int age){
    if (height >= 140 && age >= 10){
        printf("You can ride\n");
        return;
    }
    else{
        printf("Sorry\n");
        return;
    }
}

void month_to_eng(int month){
    switch(month){
        case 1:
            printf("Jan\n");
            break;
        case 2:
            printf("Feb\n");
            break;
        case 3:
            printf("Mar\n");
            break;
        case 4:
            printf("Apr\n");
            break;
        case 5:
            printf("May\n");
            break;
        case 6:
            printf("Jun\n");
            break;
        case 7:
            printf("Jul\n");
            break;
        case 8:
            printf("Aug\n");
            break;
        case 9:
            printf("Sep\n");
            break;
        case 10:
            printf("Oct\n");
            break;
        case 11:
            printf("Nov\n");
            break;
        case 12:
            printf("Dec\n");
            break;
    }
}

void is_vowel(char letter){
    switch(letter){
        case 'a':
            printf("Vowel\n");
            break;
        case 'e':
            printf("Vowel\n");
            break;
        case 'i':
            printf("Vowel\n");
            break;
        case 'o':
            printf("Vowel\n");
            break;
        case 'u':
            printf("Vowel\n");
            break;
        default:
            printf("Consonant\n");
            break;
    }
}

double calculate_avg_weight(double height1){
    return (height1 - 100.0) * 0.9;
}
void what_weight(double avg_weight, double weight){
    if (avg_weight > weight){
        printf("Under Weight\n");
        return ;
    }
    else if (avg_weight == weight){
        printf("Average Weight\n");
        return ;
    }
    else{
        printf("Over Weight\n");
        return ;
    }
}

int calculate_price(int time, int age1){
    if (time <= 17){
        if ((3 <= age1 && age1 <= 12) || age1 >= 65) return 25000;
        else                                         return 34000;
    }
    else return 10000;
}

double calculate_fx(double x){
    if (x <= 0) return pow(x, 2) - (9 * x) + 2;
    else        return 7 * x + 2;
}

void quadrant(int x1, int y1){
    if (x1 > 0 && y1 > 0){
        printf("1 quadrant\n");
        return ;
    }
    else if (x1 < 0 && y1 > 0){
        printf("2 quadrant\n");
        return ;
    }
    else if (x1 < 0 && y1 < 0){
        printf("3 quadrant\n");
        return ;
    }
    else{
        printf("4 quadrant\n");
        return ;
    }
}