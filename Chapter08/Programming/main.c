#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int even(int n1);
int absolute(int n1);
int sign(int n1);

int is_multiple(int n2, int m2);

double get_bigger(double n3, double m3);

int check_alpha(char c);

double cal_area(double radius);

int is_leap(int year);

int f_round(double f);

int get_tax(int income);

double dgree_to_radian(double deg);
double sin_dgree(double deg);

void randint(void);

int sum_dice(int n11);

int get_first_digit(int n12);

double get_distance(double x1, double y1, double x2, double y2);

int is_prime(int a);

double get_euler(int n15);

// void print(void);
// void account(int money);
// void input(int money);
// void output(int money);

int main(void){
    // 1번 문제
    int n1=12;

    int is_even=even(n1);
    int abs=absolute(n1);
    int is_sign=sign(n1);

    printf("even() result: %d\n", is_even);
    printf("absolute() result: %d\n", abs);
    printf("sign() result: %d\n", is_sign);

    // 2번 문제
    int n2=30, m2=5;

    int is_mul=is_multiple(n2, m2);

    if (is_mul == 1) printf("%d is %d's multiple\n", n2, m2);
    else             printf("%d is not %d's multiple\n", n2, m2);

    // 3번 문제
    double n3=1.5, m3=2.5;

    double bigger=get_bigger(n3, m3);

    printf("bigger(-1 is same) : %f\n", bigger);
    
    // 4번 문제
    char c='k';

    int is_alpha=check_alpha(c);

    if (is_alpha == 1) printf("%c is alphabet\n", c);
    else               printf("%c is not alphabet\n", c);

    // 5번 문제
    double radius=10.0;

    double area=cal_area(radius);

    printf("area: %.2f\n", area);

    // 6번 문제
    int year=2013;

    int leap=is_leap(year);

    if (leap == 1) printf("%d is leap\n", year);
    else           printf("%d is not leap\n", year);

    // 7번 문제
    double f=3.141592;

    int result_round=f_round(f);

    printf("round: %d\n", result_round);

    // 8번 문제
    int income=2500;

    int tax=get_tax(income);

    printf("tax: %d\n", tax);

    // 9번 문제
    for (int deg = 0; deg <= 180; deg += 10){
        double s_value=sin_dgree((double)deg);

        printf("sin(%f) = %f\n", (double)deg, s_value);
    }

    // 10번 문제
    for (int i = 0; i < 10; i++){
        randint();
    }
    printf("\n");

    // 11번 문제
    int person=sum_dice(3);
    int computer=sum_dice(3);

    if      (person > computer) printf("person win\n");
    else if (person < computer) printf("computer win\n");
    else                        printf("draw\n");

    // 12번 문제
    int n12=1099999;

    int first_dig=get_first_digit(n12);

    printf("first digit : %d\n", first_dig);

    // 13번 문제
    double x1=1.0, y1=1.0, x2=10.0, y2=10.0;

    double distance=get_distance(x1, y1, x2, y2);

    printf("distance : %f\n", distance);

    // 14번 문제
    int n14=10;

    for (int i = 2; i <= n14 - 2; i++){ // i <= n14 - 2 : n14 - i는 최소 2가 되어야 하기 때문
        if (is_prime(i) && is_prime(n14 - i)){
            printf("%d = %d + %d\n", n14, i, n14 - i);
        }
    }

    // 15번 문제
    int n15=30;

    double euler=get_euler(n15);

    printf("euler = %f\n", euler);

    // 16번 문제 (scanf() 안 쓰면 무한 루프임;;)
    // int choice=2, money=0;

    // while (1){
    //     print();

    //     if (1 > choice || choice > 4){
    //         printf("No menu\n");
    //         continue;
    //     }

    //     if (choice == 1){
    //         account(money);
    //     }
    //     else if (choice == 2){
    //         input(money);
    //     }
    //     else if (choice == 3){
    //         output(money);
    //     }
    //     else{
    //         break;
    //     }
    // }

    return 0;
}

int even(int n1){
    if (n1 % 2 == 0) return 1;
    else            return 0;
}
int absolute(int n1){
    if (n1 < 0) return -n1;
    else       return n1;
}
int sign(int n1){
    if      (n1 < 0) return -1;
    else if (n1 > 0) return 1;
    else             return 0;
}

int is_multiple(int n2, int m2){
    if (n2 % m2 == 0) return 1;
    else              return 0;
}

double get_bigger(double n3, double m3){
    if      (fabs(n3 - m3) < 1E-9) return -1;
    else if (n3 < m3)              return m3;
    else                           return n3;
}

int check_alpha(char c){
    if ('a' <= c && c <= 'z') return 1;
    else                      return 0;
}

double cal_area(double radius){
    return M_PI * pow(radius, 2);
}

int is_leap(int year){
    if      (year % 400 == 0)                  return 1;
    else if (year % 4 == 0 && year % 100 != 0) return 1;
    else                                       return 0;
}

int f_round(double f){
    return (int)(f + 0.5);
}

int get_tax(int income){
    if (income <= 1000) return income * 0.08;
    
    return 1000 * 0.08 + (income - 1000) * 0.1;
}

double dgree_to_radian(double deg){
    return (M_PI * deg) / 180.0;
}
double sin_dgree(double deg){
    return sin(dgree_to_radian(deg));
}

void randint(void){
    int num=10 + rand() % (90 - 10 + 1);

    printf("%d ", num);
}

int sum_dice(int n11){
    int sum=0;

    for (int i = 0; i < n11; i++){
        sum = sum + (1 + rand() % 6);
    }

    return sum;
}

int get_first_digit(int n12){
    while (n12 > 9){
        n12 /= 10; // 10으로 계속 나누면 정수부가 0~9사이가 됨
    }

    return n12;
}

double get_distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int is_prime(int a){
    if (a < 2) return 0;

    for (int i = 2; i < a; i++){
        if (a % i == 0) return 0;
    }

    return 1;
}

double get_euler(int n15){
    double result=1.0, e=1.0;

    for (int i = 1; i < n15; i++){
        result *= i;
        e += 1.0 / result;
    }

    return e;
}

// void print(void){
//     printf("******* Welcome to Express ATM ******* \n");
//     printf("<1> account\n");
//     printf("<2> input\n");
//     printf("<3> output\n");
//     printf("<4> close\n");
// }
// void account(int money){
//     printf("account: %d won\n", money);
// }
// void input(int money){
//     int in_money=10000;

//     money += in_money;
//     account(money);
// }
// void output(int money){
//     int out_money=5000;

//     if (money < out_money){
//         printf("Error\n");
//         output(money);
//     }

//     account(money);
// }