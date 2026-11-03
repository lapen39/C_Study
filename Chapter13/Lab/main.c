#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define SIZE 100

// 2차원 공간 상의 점을 구조체로
struct point{
    int x;
    int y;
};
// 사각형을 point
struct rect{
    struct point p1;
    struct point p2;
};
// 벡터 연산
struct vector{
    double x;
    double y;
};
struct vector get_vector_sum(struct vector a, struct vector b);
// 벡터 연산 - 도전 문제
struct vector get_vector_sum_chall(struct vector *p1, struct vector *p2);
// 2차원 공간 상의 점을 MYPOINT 타입으로
typedef struct point1{
    int x;
    int y;
} MYPOINT;
MYPOINT translate(MYPOINT p, MYPOINT delta);
// 4지 선다 퀴즈 프로그램
struct QUESTION{
    char question[SIZE];
    char item1[SIZE];
    char item2[SIZE];
    char item3[SIZE];
    char item4[SIZE];
    int solution;
};
struct QUESTION bank[SIZE] = {
    {"임베디드 장치에 가장 적합한 프로그래밍 언어는?", "1. Python", "2. Java", "3. C", "4.Javascript", 3},
    {"서로 다른 자료형을 모을 수 있는 구조는?", "1. 배열", "2. 변수", "3. 구조체", "4. 포인터", 3},
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 2차원 공간 상의 점을 구조체로 표현
    struct point p1, p2;
    int xdiff, ydiff;
    double dist;

    p1.x = 10;
    p1.y = 10;
    p2.x = 20;
    p2.y = 20;

    xdiff = p1.x - p2.x;
    ydiff = p1.y - p2.y;

    dist = sqrt(pow(xdiff, 2.0) + pow(ydiff, 2.0));

    printf("거리 = %f\n", dist);

    // 사각형을 point 구조체로 표현
    struct rect r;
    int w, h, area, peri;

    r.p1.x = 10;
    r.p1.y = 10;
    r.p2.x = 20;
    r.p2.y = 20;

    w = r.p2.x - r.p1.x;
    h = r.p2.y - r.p1.y;
    area = w * h;
    peri = (2 * w) + (2 * h);

    printf("면적 = %d / 둘레 = %d\n", area, peri);

    // 벡터 연산
    struct vector a = {2.0, 3.0};
    struct vector b = {5.0, 6.0};
    struct vector sum = get_vector_sum(a, b);

    printf("벡터의 합 = (%.1f, %.1f)\n", sum.x, sum.y);

    // 벡터 연산 - 도전 문제
    struct vector a_chall = {2.0, 3.0};
    struct vector b_chall = {5.0, 6.0};
    struct vector sum_chall = get_vector_sum_chall(&a_chall, &b_chall);

    printf("벡터의 합 = (%.1f, %.1f)\n", sum_chall.x, sum_chall.y);

    // 2차원 공간 상의 점을 POINT 타입으로 정의
    MYPOINT p = {2, 3};
    MYPOINT delta = {10, 10};
    MYPOINT result = translate(p, delta);

    printf("(%d, %d) + (%d, %d) -> (%d, %d)\n", p.x, p.y, delta.x, delta.y, result.x, result.y);

    // 4지 선다 퀴즈 프로그램
    int select;
    for (int i = 0; i < 2; i++){
        printf("%s\n", bank[i].question);
        printf("%s  ", bank[i].item1);
        printf("%s  ", bank[i].item2);
        printf("%s  ", bank[i].item3);
        printf("%s  ", bank[i].item4);

        scanf("%d", &select);

        if (select == bank[i].solution) printf("맞았습니다.\n");
        else                            printf("틀렸습니다.\n");
    }

    return 0;
}

struct vector get_vector_sum(struct vector a, struct vector b){
    struct vector result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

struct vector get_vector_sum_chall(struct vector *p1, struct vector *p2){
    struct vector result;

    result.x = p1->x + p2->x;
    result.y = p1->y + p2->y;

    return result;
}

MYPOINT translate(MYPOINT p, MYPOINT delta){
    MYPOINT new_p;
    new_p.x = p.x + delta.x;
    new_p.y = p.y + delta.y;

    return new_p;
}