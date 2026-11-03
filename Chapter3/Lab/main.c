#define PI 3.14159265359

#include <stdio.h>

double compute_area(double radius);

double compute_usd(int krw, double rate);

double compute_sum(double num1, double num2, double num3);
double compute_avg(double sum);

double compute_area1(double w, double h);
double compute_perimeter(double w, double h);

int compute_sum1(int x, int y, int z);

int main(void){
    // 원의 면적
    double radius=5.0;
    double area=compute_area(radius);

    printf("area: %lf\n", area);

    // 환율 계산
    double rate=1400;
    int krw=1000000;
    double usd=compute_usd(krw, rate);

    printf("%d -> %lf\n", krw, usd);

    // 평균 계산
    double num1=10.2, num2=21.5, num3=32.9;
    double sum=compute_sum(num1, num2, num3);
    double avg=compute_avg(sum);

    printf("sum: %.2lf\n", sum);
    printf("average: %.2lf\n", avg);

    // 사각형의 둘레와 면적
    double w=10.0, h=5.0;
    double area1=compute_area1(w, h);
    double perimeter=compute_perimeter(w, h);

    printf("area: %lf\n", area1);
    printf("perimeter: %lf\n", perimeter);

    // 변수의 초기값
    int x=10, y=20, z=30;
    int sum1=compute_sum1(x, y, z);

    printf("%d + %d + %d = %d", x, y, z, sum1);

    return 0;
}

double compute_area(double radius){
    return PI * radius * radius;
}

double compute_usd(int krw, double rate){
    return krw / rate;
}

double compute_sum(double num1, double num2, double num3){
    return num1 + num2 + num3;
}
double compute_avg(double sum){
    return sum / 3.0;
}

double compute_area1(double w, double h){
    return w * h;
}
double compute_perimeter(double w, double h){
    return 2 * (w + h);
}

int compute_sum1(int x, int y, int z){
    return x + y + z;
}