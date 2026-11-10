#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void avg_score(int *list, int students);
typedef struct movie{
    char title[100];
    double rating;
} MOVIE;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 동적 배열을 이용한 성적 처리
    int *list;
    int students;
    printf("학생의 수: ");
    scanf("%d", &students);
    list = (int *)malloc(sizeof(int) * students);
    if (list == NULL){
        printf("동적 메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < students; i++){
        printf("학생 #%d 성적: ", i + 1);
        scanf("%d", &list[i]);
    }
    getchar();

    avg_score(list, students);
    free(list);

    // 어떤 문자열이라도 저장하는 동적 메모리
    char *p;
    int size = 10, index = 0;
    char c;
    p = (char *)malloc(sizeof(char) * size);
    if (p == NULL){
        printf("동적 메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }
    
    printf("입력할 문자열: ");
    do{
        c = getchar();
        if (index >= (size - 1)){
            size *= 2;
            p = (char *)realloc(p, sizeof(char) * size);
            if (p == NULL){
                printf("동적 메모리 할당 오류\n");
                exit(EXIT_FAILURE);
            }
        }

        p[index++] = c;
    } while (c != '\n');
    p[index] = '\0';

    printf("입력된 문자열: %s\n", p);
    free(p);

    // 영화 관리 프로그램
    MOVIE *movies;
    int movie_size;
    printf("영화의 개수: ");
    scanf("%d", &movie_size);
    getchar();

    movies = (MOVIE *)malloc(sizeof(MOVIE) * movie_size);
    if (movies == NULL){
        printf("동적 메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < movie_size; i++){
        printf("영화 제목: ");
        fgets(movies[i].title, 100, stdin);
        movies[i].title[strcspn(movies[i].title, "\n")] = '\0';

        printf("영화 평점: ");
        scanf("%lf", &(movies[i].rating));
        getchar();
    }

    printf("=============================================\n");
    printf("제목\t평점\n");
    printf("=============================================\n");
    for (int i = 0; i < movie_size; i++){
        printf("%s\t%.2f\n", movies[i].title, movies[i].rating);
    }
    printf("=============================================\n");
    free(movies);

    return 0;
}

void avg_score(int *list, int students){
    int sum = 0;
    for (int i = 0; i < students; i++){
        sum += list[i];
    }
    
    printf("성적 평균 = %.2f\n", (double)sum / students);
}