# include <stdio.h>

double compute_time(double salary, double goal);

double mile_to_meter(double mile, double mile2meter);

float compute_area(float base, float height);

double f_to_c(double f);

double compute(double x);

double compute_weight_on_moon(double weight, double gravity);

int main(void){
    // 1번 문제
    double salary=6000, goal=100000;
    double time=compute_time(salary, goal);

    printf("%.2lf\n", time);

    // 2번 문제
    double mile=2, mile2meter=1609;
    double meter=mile_to_meter(mile, mile2meter);

    printf("%f -> %f\n", mile, meter);

    // 3번 문제
    float base=6, height=3;
    float area=compute_area(base, height);

    printf("area: %f\n", area);

    // 4번 문제
    double f=32;
    double c=f_to_c(f);

    printf("%lf -> %lf\n", f, c);

    // 5번 문제
    double x=2.0;
    double result=compute(x);

    printf("result: %lf\n", result);

    // 6번 문제
    double weight=70, gravity=0.17;
    double weight_on_moon=compute_weight_on_moon(weight, gravity);

    printf("weight on the moon: %lf", weight_on_moon);

    return 0;
}

double compute_time(double salary, double goal){
    return goal / salary;
}

double mile_to_meter(double mile, double mile2meter){
    return mile * mile2meter;
}

float compute_area(float base, float height){
    return 0.5 * base * height;
}

double f_to_c(double f){
    return (5.0/9.0) * (f - 32);
}

double compute(double x){
    return 3 * (x * x) + 7 * x + 11;
}

double compute_weight_on_moon(double weight, double gravity){
    return weight * gravity;
}