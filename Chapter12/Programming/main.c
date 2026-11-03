#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define MAX_WORD 100

void read_line(char buf[], int size);
void reverse_s(void);
void del_gap(void);
void del_str(void);
int str_chr(char *str, int count, char c);
int check_freq(char *buf, int c);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1번 문제
    reverse_s();

    // 2번 문제
    del_gap();

    // 3번 문제
    del_str();

    // 4번 문제
    char str[100];
    printf("문자열을 입력하시오: ");
    read_line(str, sizeof(str));

    int count = 0;
    char c;
    printf("문자를 입력하시오: ");
    scanf("%c", &c);
    getchar();

    int result = str_chr(str, count, c);

    printf("%c의 개수: %d\n", c, result);

    // 5번 문제
    char buf[BUFSIZ];
    printf("문자열을 입력하시오: ");
    read_line(buf, sizeof(buf));

    char ch;
    for (ch = 'a'; ch <= 'z'; ch++){
        printf("%c: %d\n", ch, check_freq(buf, ch));
    }

    return 0;
}

void read_line(char buf[], int size){
    fgets(buf, size, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

void reverse_s(void){
    char s[100] = "";
    printf("문자열을 입력하시오: ");
    read_line(s, sizeof(s));

    int len = strlen(s);

    printf("역순 문자열: ");
    for (int i = len - 1; i >= 0; i--){
        printf("%c", s[i]);
    }
    printf("\n");
}

void del_gap(void){
    char s[100] = "";
    printf("문자열을 입력하시오: ");
    read_line(s, sizeof(s));

    char del_gap_s[100] = "";
    char *token = strtok(s, " ");
    while (token != NULL){
        strcat(del_gap_s, token);
        token = strtok(NULL, " ");
    }
    printf("공백 제거 문자열: %s\n", del_gap_s);
}

void del_str(void){
    char s[100] = "";
    printf("문자열을 입력하시오: ");
    read_line(s, sizeof(s));

    char c;
    printf("제거할 문자: ");
    scanf("%c", &c);
    getchar();

    char delim[2] = {c, '\0'}; // strtok()는 문자열 처리 함수라서 c를 문자열로 만들어줘야 함

    char del_str_s[100] = "";
    char *token = strtok(s, delim);
    while (token != NULL){
        strcat(del_str_s, token);
        token = strtok(NULL, delim);
    }
    printf("결과 문자열 = %s\n", del_str_s);
}

int str_chr(char *str, int count, char c){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if (str[i] == c){
            count++;
        }
    }
    return count;
}

int check_freq(char *buf, int c){
    int count = 0;
    for (int i = 0; i < strlen(buf); i++){
        if (buf[i] == c){
            count++;
        }
    }
    return count;
}