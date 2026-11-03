#include <stdio.h>

double compute_volume(double width, double height, double length);

double pyeong_to_meter2(double pyeong, double SQMETER_PYEONG);

int main(void){
    // 1번 문제
    double num=123.567;
    
    printf("num to float -> %lf\n", num);
    printf("num to exponent -> %e\n", num);

    // 2번 문제
    int data=0xff; //16진수 ff를 정수로 바로 정의

    printf("8 -> %o\n", data);
    printf("10 -> %d\n", data);
    printf("16 -> %#x\n", data);

    // 3번 문제
    int x=10, y=20;
    int temp;

    temp=x;
    x=y;
    y=temp;

    printf("x=%d, y=%d", x, y);

    // 4번 문제
    double width=30, height=30, length=30;
    double volume=compute_volume(width, height, length);

    printf("(%lf * %lf * %lf) = %lf\n", width, height, length, volume);

    // 5번 문제
    const double SQMETER_PYEONG=3.3058;
    double pyeong=31;
    double pyeong2meter2=pyeong_to_meter2(pyeong, SQMETER_PYEONG);

    printf("%lf -> %lf\n", pyeong, pyeong2meter2);

    // 6번 문제
    double result=3.32e-3 + 9.76e-8;

    printf("(3.32e-3 + 9.76e-8) = %lf\n", result);

    /*7번 문제는 실습 과제*/
    // 8번 문제
    int data1=80;

    printf("%d -> %c\n", data1, data1);

    /*9번, 10번 문제는 실습 과제*/
    // 11번 문제
    printf("\"ASCII code\", \'A\', \'B\', \'C\'\n");
    printf("\\t \\a \\n\n");

    // 12번 문제
    int i=255;

    // 12-1번
    printf("8 -> %o\n", i);
    printf("16 -> %x\n", i);
    // 12-2번
    i = -1;

    printf("16 -> %x", i);

    return 0;
}

double compute_volume(double width, double height, double length){
    return width * height * length;
}

double pyeong_to_meter2(double pyeong, double SQMETER_PYEONG){
    return pyeong * SQMETER_PYEONG;
}