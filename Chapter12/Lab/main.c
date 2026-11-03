#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define WORDS 5

int count_word(char s[]);

void check_pass(void);

void short_ans(void);

void s_printf(void);

int check_dic(char dic[][2][30]);

void encrypt(char cipher[], int shift);

int main(void){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // 단어 세기
    int wc = count_word("the c book...");
    printf("count : %d\n", wc);

    // 유효한 암호 확인
    check_pass();

    // 단답형 퀴즈
    short_ans();

    // 영상 파일 이름 자동 생성
    s_printf();

    // 한영 사전 구현
    char dic[WORDS][2][30] = {
        {"book", "책"},
        {"boy", "소년"},
        {"computer", "컴퓨터"},
        {"language", "언어"},
        {"rain", "비"}
    };
    
    int result = check_dic(dic);
    if (result == 0) printf("사전에서 발견되지 않았습니다.\n");

    // 메시지 암호화
    char cipher[50];
    printf("문자열을 입력하시오: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    int shift = 3; // 이동거리
    encrypt(cipher, shift);

    return 0;
}

int count_word(char s[]){
    int i, wc = 0, waiting = 1;

    for (i = 0; s[i] != '\0'; i++){ // NULL: 포인터끼리 비교 / '\0': 문자끼리 비교
        if (isalpha(s[i])){
            if (waiting){
                wc++;
                waiting = 0;
            }
        }
        else{ // waiting = 1: 단어가 아니면(공백, 구두점 등) 기다림
            waiting = 1;
        }
    }
    return wc;
}

void check_pass(void){
    int low_count = 0, up_count = 0, dig_count = 0, len;
    char pass[100] = "";

    fgets(pass, sizeof(pass), stdin); // gcc 사용 중이라 fgets() 써야 함(gets_s() 안 써짐)
    pass[strcspn(pass, "\n")] = '\0';

    len = strlen(pass); // 문자열의 길이

    if (len < 7){
        printf("Error\n");
        exit(1);
    }

    for (int i = 0; i < len; i++){
        if (islower(pass[i])) ++low_count;
        if (isupper(pass[i])) ++up_count;
        if (isdigit(pass[i])) ++dig_count;
    }

    if (low_count > 0 && up_count > 0 && dig_count > 0){
        printf("Good\n");
    }
    else{
        printf("Bad\n");
    }
}

void short_ans(void){
    char key[] = "C";
    char buffer[80] = "";

    do{
        printf("What is the most widely used language for embedded devices? ");

        fgets(buffer, sizeof(buffer), stdin); // stdin: 키보드(표준 입력)
        buffer[strcspn(buffer, "\n")] = '\0';
    } while (strcmp(key, buffer) != 0);

    printf("Correct!\n");
}

void s_printf(void){
    char file_name[100];

    for (int i = 0; i < 6; i++){
        sprintf(file_name, "image%d.jpg", i);
        printf("%s\n",file_name);
    }
}

int check_dic(char dic[][2][30]){
    char word[30];

    printf("단어를 입력하시오: ");
    scanf("%s", word);

    getchar();

    for(int index = 0; index < WORDS; index++){
        if (strcmp(dic[index][0], word) == 0){
            printf("%s: %s\n", word, dic[index][1]);
            return 1;
        }
    }
    return 0;
}

void encrypt(char cipher[], int shift){
    int i = 0;
    while (cipher[i] != '\0'){
        if (cipher[i] >= 'A' && cipher[i] <= 'z'){ // 문자가 알파벳인지 검사
            cipher[i] += shift;

            if (cipher[i] > 'z'){ // 경계를 넘어갔는지 검사
                cipher[i] -= 26;
            }
        }
        i++;
    }
    printf("암호화된 문자열: %s\n", cipher);
}