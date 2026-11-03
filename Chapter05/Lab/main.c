#include <stdio.h>

int leap_year(int year);
int even_odd(int year1);

char encrpting(char data, char key);
char decrpting(char encrpted_data, char key);

double change_f2c(double f_temp);

int main(void){
    // 거스름돈 계산(모르겠음..)
    // 윤년 판단
    int year=2012;
    int result=leap_year(year);

    printf("%d leap_year?(True=1 False=0) %d\n", year, result);
    // 윤년 도전문제
    int year1=2013;
    int result1=even_odd(year1);

    printf("%d even?odd?(even=1 odd=0) %d\n", year1, result1);

    // 십진수 -> 이진수(모르겠음..)
    // XOR 활용 암호화
    char data='a', key=0xff;
    char encrpted_data=encrpting(data, key);
    char decrpted_data=decrpting(encrpted_data, key);

    printf("orig: %c\n", data);
    printf("encrpt: %c\n", encrpted_data);
    printf("decrpt: %c\n", decrpted_data);

    // 화씨 -> 섭씨
    double f_temp=100;
    double c_temp=change_f2c(f_temp);

    printf("%lf -> %lf\n", f_temp, c_temp);

    return 0;
}

int leap_year(int year){
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int even_odd(int year1){
    return year1 % 2 == 0;
}

char encrpting(char data, char key){
    return data ^ key;
}
char decrpting(char encrpted_data, char key){
    return encrpted_data ^ key;
}

double change_f2c(double f_temp){
    return (5.0 / 9.0) * (f_temp - 32);
}