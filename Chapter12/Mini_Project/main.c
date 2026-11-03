#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char solution[100] = "meet at midnight";
    char answer[100] = "____ __ ________";
    char ch;

    while (1){
        printf("문자열을 입력하시오: %s\n", answer);
        printf("글자를 추측하시오: ");
        ch = _getch();

        for (int i = 0; solution[i] != '\0'; i++){
            if (solution[i] == ch) answer[i] = ch;
        }
        if (strcmp(solution, answer) == 0) break;
    }
    return 0;
}