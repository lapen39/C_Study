#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

double get_income_tax_rate(double avg_taxtion);
double get_income_tax(double avg_taxtion, double income_tax_rate);
double get_deduction(double avg_taxtion);
double calculate_tax_amount(double avg_taxtion, double income_tax_rate, double tax_deduction);

int main(void){
    // 소득세 계산기
    double avg_taxtion = 35000000.0;
    double income_tax_rate=get_income_tax_rate(avg_taxtion);
    double income_tax=get_income_tax(avg_taxtion, income_tax_rate);
    double tax_deduction=get_deduction(avg_taxtion);
    double tax_amount=calculate_tax_amount(avg_taxtion, income_tax_rate, tax_deduction);

    printf("income tax rate: %.2f\n", income_tax_rate);
    printf("(Before deduction)income tax: %.2f\n", income_tax);
    printf("tax deduction: %.2f\n", tax_deduction);
    printf("tax amount: %.2f\n", tax_amount);

    return 0;
}

double get_income_tax_rate(double avg_taxtion){
    if (0 < avg_taxtion && avg_taxtion < 12000000) return 0.06;
    else if (avg_taxtion < 46000000)               return 0.15;
    else if (avg_taxtion < 88000000)               return 0.24;
    else if (avg_taxtion < 150000000)              return 0.35;
    else if (avg_taxtion < 300000000)              return 0.38;
    else if (avg_taxtion < 500000000)              return 0.40;
    else if (avg_taxtion < 1000000000)             return 0.42;
    else                                           return 0.45;
}
double get_income_tax(double avg_taxtion, double income_tax_rate){
    return avg_taxtion * income_tax_rate;
}
double get_deduction(double avg_taxtion){
    if (0 < avg_taxtion && avg_taxtion < 12000000) return 0;
    else if (avg_taxtion < 46000000)               return 1080000;
    else if (avg_taxtion < 88000000)               return 5220000;
    else if (avg_taxtion < 150000000)              return 14900000;
    else if (avg_taxtion < 300000000)              return 19400000;
    else if (avg_taxtion < 500000000)              return 25400000;
    else if (avg_taxtion < 1000000000)             return 35400000;
    else                                           return 65400000;
}
double calculate_tax_amount(double avg_taxtion, double income_tax_rate, double tax_deduction){
    return (avg_taxtion * income_tax_rate) - tax_deduction;
}