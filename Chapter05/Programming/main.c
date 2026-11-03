#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int share(int a, int b);
int modulo(int a, int b);

double compute_add(double x, double y);
double compute_sub(double x, double y);
double compute_mul(double x, double y);
double compute_div(double x, double y);

int compute_max(int a1, int a2, int a3);

double cm_to_inch(double height, double inch);
int inch_to_fit(double cm2inch, double fit);
double modulo_fit(int inch2fit, double cm2inch, double fit);

void print_digits(int n);

int mul_2(int x2, int count);

double calculate_surface(double radius);
double calculate_volume(double radius);

double calculate_height(double wand_height, double wand_shadow, double distance);

void quadrant(int x3, int y3);

double calculate_radius(double si2al, double degree);

int main(void){
    // 1번 문제
    int a=10, b=3;
    int result_share=share(a, b);
    int result_modulo=modulo(a, b);

    printf("(%d / %d) = %d\n", a, b, result_share);
    printf("(%d %% %d) = %d\n", a, b, result_modulo);

    // 2번 문제
    double x=2.0, y=3.0;
    double add=compute_add(x, y);
    double sub=compute_sub(x, y);
    double mul=compute_mul(x, y);
    double div=compute_div(x, y);

    printf("%.2lf %.2lf %.2lf %.2lf\n", add, sub, mul, div);

    // 3번 문제
    int a1=2, a2=3, a3=4;
    int max=compute_max(a1, a2, a3);

    printf("max: %d\n", max);

    // 4번 문제
    double height=163, inch=2.54, fit=12;
    double cm2inch=cm_to_inch(height, inch);
    int inch2fit=inch_to_fit(cm2inch, fit);
    double remain_inch=modulo_fit(inch2fit, cm2inch, fit);

    printf("%.2lf -> %dfit %.2lfinch\n", height, inch2fit, remain_inch);

    // 5번 문제
    int n=23;

    print_digits(n);

    // 6번 문제(이거 맞나.?)
    double x1=1.0, y1=0.9;
    printf("(%f - %f) == %f => %d\n", x1, y1, x1 - y1, fabs(x1 - y1) > 1E-10);

    // 7번 문제
    int x2=10, count=3;
    int result_mul=mul_2(x2, count);

    printf("(%d << %d) -> %d\n", x2, count, result_mul);

    // 8번 문제
    double radius=10.0;
    double surface=calculate_surface(radius);
    double volume=calculate_volume(radius);

    printf("surface = %.2f\n", surface);
    printf("volume = %.2f\n", volume);

    // 9번 문제
    double wand_height=100.0, wand_shadow=20.0, distance=1000.0;
    double result_height=calculate_height(wand_height, wand_shadow, distance);

    printf("height = %.2f\n", result_height);

    // 10번 문제
    int x3=10, y3=10;

    quadrant(x3, y3);

    // 11번 문제
    double si2al=900.0, degree=7.2;
    double result_radius=calculate_radius(si2al, degree);

    printf("radius = %.2f\n", result_radius);

    // 12번 문제(별로 안 하고싶다...)

    return 0;
}

int share(int a, int b){
    return a / b;
}
int modulo(int a, int b){
    return a % b;
}

double compute_add(double x, double y){
    return x + y;
}
double compute_sub(double x, double y){
    return x - y;
}
double compute_mul(double x, double y){
    return x * y;
}
double compute_div(double x, double y){
    return x / y;
}

int compute_max(int a1, int a2, int a3){
    int temp;

    temp = (a1 < a2) ? a2 : a1;
    temp = (temp < a3) ? a3 : temp;

    return temp;
}

double cm_to_inch(double height, double inch){
    return height / inch;
}
int inch_to_fit(double cm2inch, double fit){
    return cm2inch / fit;
}
double modulo_fit(int inch2fit, double cm2inch, double fit){
    return cm2inch - (inch2fit * fit);
}

void print_digits(int n){
    if (n > 100){
        printf("Error\n");

        return;
    }

    int tens = n / 10;
    int ones = n % 10;

    printf("input: %d -> ten: %d, one: %d\n", n, tens, ones);
}

int mul_2(int x2, int count){
    return x2 << count;
}

double calculate_surface(double radius){
    return 4.0 * M_PI * pow(radius, 2);
}
double calculate_volume(double radius){
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double calculate_height(double wand_height, double wand_shadow, double distance){
    return (distance * wand_height) / wand_shadow;
}

void quadrant(int x3, int y3){
    (x3 > 0 && y3 > 0) ? printf("1 quadrant\n") : printf(" ");
    (x3 < 0 && y3 > 0) ? printf("2 quadrant\n") : printf(" ");
    (x3 < 0 && y3 < 0) ? printf("3 quadrant\n") : printf(" ");
    (x3 > 0 && y3 < 0) ? printf("4 quadrant\n") : printf(" ");
}

double calculate_radius(double si2al, double degree){
    return (si2al * 360) / (2 * M_PI * degree);
}