#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define SIZE 5

void print_image(int image[][SIZE]);
void brighten_image(int image[][SIZE]);

int main(void){
    // 영상 처리
    int image[SIZE][SIZE]={
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50}};

    print_image(image);
    brighten_image(image);
    print_image(image);

    return 0;
}

void print_image(int image[][SIZE]){
    int r, c;

    for (r = 0; r < SIZE; r++){
        for (c = 0; c < SIZE; c++){
            printf("%03d ", image[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}
void brighten_image(int image[][SIZE]){
    int r, c;
    int *p;

    p = &image[0][0];

    for (r = 0; r < SIZE; r++){
        for (c = 0; c < SIZE; c++){
            *p += 10;
            p++;
        }
    }
}