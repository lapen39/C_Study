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

// 1번 문제
enum genre{COMIC, SF, DOCU, DRAMA};
typedef enum genre GENRE;
struct book{
    char title[SIZE];
    char author[SIZE];
    GENRE type;
};
char *genre_name[] = {"COMIC", "SF", "DOCU", "DRAMA"};
// 2번 문제
int equal_author(struct book b1, struct book b2);
// 3번 문제
struct email{
    char title[SIZE];
    char sender[SIZE];
    char receiver[SIZE];
    char content[SIZE];
    char date[SIZE];
    int pri;
};
// 4번 문제
typedef struct complex{
    double real;
    double imag;
} COMPLEX;
COMPLEX complex_add(COMPLEX c1, COMPLEX c2);
// 5번 문제
struct point{
    int x, y;
};
int equal_p(struct point a1, struct point a2);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1번 문제
    /*
    struct book b1 = {"바람과 함께 사라지다", "마가렛 미첼", DRAMA};
    printf("{%s, %s, %s}\n", b1.title, b1.author, genre_name[b1.type]);
    */

    // 2번 문제
    struct book b1 = {"노인과 바다", "헤밍웨이", DRAMA};
    struct book b2 = {"누구를 위하여 종을 울리나", "헤밍웨이", DRAMA};
    int is_equal_b = equal_author(b1, b2);

    printf("equal_author()의 반환값: %d\n", is_equal_b);

    // 3번 문제
    struct email e1 = {"안부 메일", "chulsoo@hankuk.ac.kr", "hsh@hankuk.ac.kr", "안녕하십니까? 새해 복 많이 받으세요.", "2023/1/1", 1};
    printf("제목: %s\n", e1.title);
    printf("수신자: %s\n", e1.sender);
    printf("발신자: %s\n", e1.receiver);
    printf("내용: %s\n", e1.content);
    printf("날짜: %s\n", e1.date);
    printf("우선순위: %d\n", e1.pri);

    // 4번 문제
    COMPLEX a, b;
    a.real = 1.00;
    a.imag = 2.00;
    b.real = 2.00;
    b.imag = 3.00;

    COMPLEX result_add = complex_add(a, b);
    printf("%.2f+%.2fi\n", result_add.real, result_add.imag);

    // 5번 문제
    struct point a1, a2;
    a1.x = 1;
    a1.y = 2;
    a2.x = 3;
    a2.y = 5;

    int is_equal_p = equal_p(a1, a2);
    if (is_equal_p == 1) printf("(%d, %d) == (%d, %d)\n", a1.x, a1.y, a2.x, a2.y);
    else printf("(%d, %d) != (%d, %d)\n", a1.x, a1.y, a2.x, a2.y);

    return 0;
}

int equal_author(struct book b1, struct book b2){
    if (strcmp(b1.author, b2.author) == 0) return 1;
    else                                   return 0;
}

COMPLEX complex_add(COMPLEX c1, COMPLEX c2){
    COMPLEX add;
    add.real = c1.real + c2.real;
    add.imag = c1.imag + c2.imag;

    return add;
}

int equal_p(struct point a1, struct point a2){
    if ((a1.x == a2.x) && (a1.y == a2.y)) return 1;
    else return 0;
}