#define _USE_MATH_DEFINES

#define SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void get_frac(double f, int *pi, double *pd);

// void get_int(int a[], int size);

void array_fill(int A[], int size);

void my_strlen(char *p);

void pointer_type(char str[]);

void array_print(int *b, int size);

void reverse_array(int *p, int size);

double *get_max(double A[], int D_size);

void convert(double grades[], double scores[], int size);

void array_copy(int copy_A[], int copy_B[], int size);

void array_add(int salary_A[], int bonus_B[], int total_C[], int size);

int array_sum(int salary_A[], int size);

int search(int salary_arr[], int size, int search_value);

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);

int main(void){
    // 1번 문제
    double f=3.14;
    int i;
    double d;

    get_frac(f, &i, &d);

    // // 2번 문제
    // int a[3];

    // get_int(a);

    // 3번 문제
    int A[10];

    array_fill(A, 10);

    // 4번 문제
    char string[]="HELLO";

    my_strlen(string);

    // 5번 문제
    char str[1000];

    pointer_type(str);

    // 6번 문제
    int b[10]={1, 2, 3, 4, 5};

    array_print(b, 10);

    // 7번 문제
    int c[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    reverse_array(c, 10);

    // 8번 문제
    double D[]={1.23, 3.14, 9.16, 100.90};
    int D_size=sizeof(D)/sizeof(D[0]);
    double *pd=get_max(D, D_size);

    printf("max: %f\n", *pd);

    // 9번 문제
    double grades[]={0.00, 0.50, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.3};
    double scores[SIZE];

    convert(grades, scores, SIZE);

    // 10번 문제
    int copy_A[]={1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    int copy_B[SIZE];

    array_copy(copy_A, copy_B, SIZE);

    // 11번 문제
    int salary_A[]={1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    int bonus_B[]={4, 5, 6, 0, 0, 0, 0, 0, 0, 0};
    int total_C[SIZE];

    array_add(salary_A, bonus_B, total_C, SIZE);

    // 12번 문제
    int total=array_sum(salary_A, SIZE);

    printf("total: %d\n", total);

    // 13번 문제
    int salary_arr[]={0, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    int search_value=200;
    int result=search(salary_arr, SIZE, search_value);

    printf("index: %d\n", result);

    // 14번 문제
    int x=100, y=200;
    int *p_sum, *p_diff;

    get_sum_diff(x, y, p_sum, p_diff);

    // 15번 문제(scanf() 사용하는 문제임)

    return 0;
}

void get_frac(double f, int *pi, double *pd){
    *pi = (int)f;
    *pd = f - *pi;

    printf("get_frac(%f) function is calling\n", f);
    printf("integer part: %d\n", *pi);
    printf("fractional part: %f\n", *pd);
}

// void get_int(int a[], int size){
//     for (int i = 0; i < size; i++){
//         scanf("%d", &a[i]);
//     }

//     printf("===\n");
//     printf("adress\t\tvalue\n");
//     printf("===\n");

//     for (int i = 0; i < size; i++){
//         printf("%08X\t%02d\n", &a[i], a[i]);
//     }
// }

void array_fill(int A[], int size){
    for (int i = 0; i < size; i++){
        A[i] = rand();

        printf("%d ", A[i]);
    }
    printf("\n");
}

void my_strlen(char *p){
    int count=0;
    for (int i = 0; p[i] != 0; i++){
        count++;
    }

    printf("count: %d\n", count);
}

void pointer_type(char str[]){
    char *pc=str;
    int *pi=(int *)(str+1);
    float *pf=(float *)(str+5);

    *pc = 'a';
    *pi = 100;
    *pf = 3.14;

    printf("%c\t%d\t%f\n", *pc, *pi, *pf);
}

void array_print(int *b, int size){
    printf("b[] = { ");

    for (int i = 0; i < size; i++){
        printf("%d, ", b[i]);
    }

    printf("}\n");
}

void reverse_array(int *p, int size){
    int *start=p;

    p = p + size - 1;

    printf("c[] = ");

    for (; p >= start; p--){
        printf("%d ", *p);
    }

    printf("\n");
}

double *get_max(double A[], int D_size){
    double *p_max=&A[0];

    for (int i = 0; i < D_size; i++){
        if (*p_max < A[i]) p_max = &A[i];
    }

    return p_max;
}

void convert(double grades[], double scores[], int size){
    for (int i = 0; i < size; i++){
        scores[i] = (double)(100 * grades[i]) / 4.3;
    }

    for (int i = 0; i < size; i++){
        printf("%.2f ", grades[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%.2f ", scores[i]);
    }
    printf("\n");
}

void array_copy(int copy_A[], int copy_B[], int size){
    for (int i = 0; i < size; i++){
        copy_B[i] = copy_A[i];
    }
    
    for (int i = 0; i < size; i++){
        printf("%d ", copy_A[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", copy_B[i]);
    }
    printf("\n\n");
}

void array_add(int salary_A[], int bonus_B[], int total_C[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", salary_A[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%d ", bonus_B[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++){
        total_C[i] = salary_A[i] + bonus_B[i];

        printf("%d ", total_C[i]);
    }
    printf("\n");
}

int array_sum(int salary_A[], int size){
    int sum=0;

    for (int i = 0; i < size; i++){
        sum += salary_A[i];
    }

    return sum;
}

int search(int salary_arr[], int size, int search_value){
    int result;
    for (int i = 0; i < size; i++){
        if (salary_arr[i] == search_value){
            result = i;
        }
    }
    return result;
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff){
    *p_sum = x + y;
    *p_diff = x - y;

    printf("sum: %d\n", *p_sum);
    printf("diff: %d\n", *p_diff);
}