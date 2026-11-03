#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

double calculate_root(double a1, double b1, double c1, double *x1, double *x2);

int calculator(int x, int y, char op);
int calculator_switch(int x, int y, char op);

int main(void){
    // 이차 방정식
    double a1=1, b1=2, c1=-8;
    double x1, x2;
    int result_root=calculate_root(a1, b1, c1, &x1, &x2);

    if (result_root == 0) printf("No root\n");
    else                  printf("(%f, %f, %f) = %f, %f\n", a1, b1, c1, x1, x2);

    // 산술 계산기
    int x=10, y=2;
    char op='*';
    int result1=calculator(x, y, op);

    printf("(%d %c %d) = %d\n", x, op, y, result1);
    // 산술 계산기(switch 버전)
    int result2=calculator_switch(x, y, op);

    printf("(%d %c %d) = %d\n", x, op, y, result2);

    return 0;
}

double calculate_root(double a1, double b1, double c1, double *x1, double *x2){
    if (fabs(a1 - 0.0) < 1E-10) return 0;

    double dis = pow(b1, 2) - 4.0 * a1 * c1;

    if (dis < 0) return 0;

    *x1 = ((-b1) + sqrt(dis)) / (2.0 * a1);
    *x2 = ((-b1) - sqrt(dis)) / (2.0 * a1);

    return 1;
}

int calculator(int x, int y, char op){
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y;
    else if (op == '/') return x / y;
    else if (op == '%') return x % y;
    else{
        fprintf(stderr, "Unsupported operator\n");
        return 0;
    }
}
int calculator_switch(int x, int y, char op){
    switch(op){
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '%': return x % y;
        default:
            fprintf(stderr, "Unsupported operator\n");
            return 0;
    }
}