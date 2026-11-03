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
    int is_equal = equal_author(b1, b2);

    printf("equal_author()의 반환값: %d\n", is_equal);

    // 3번 문제
    struct email e1 = {"안부 메일", "chulsoo@hankuk.ac.kr", "hsh@hankuk.ac.kr", "안녕하십니까? 새해 복 많이 받으세요.", "2023/1/1", 1};
    printf("제목: %s\n", e1.title);
    printf("수신자: %s\n", e1.sender);
    printf("발신자: %s\n", e1.receiver);
    printf("내용: %s\n", e1.content);
    printf("날짜: %s\n", e1.date);
    printf("우선순위: %d\n", e1.pri);

    return 0;
}

int equal_author(struct book b1, struct book b2){
    if (strcmp(b1.author, b2.author) == 0) return 1;
    else                                   return 0;
}