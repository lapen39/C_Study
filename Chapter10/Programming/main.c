#define _USE_MATH_DEFINES

#define SIZE 6
#define AREA 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void print_days(int days[], int size);

void rand_a1(int a1[], int size);
int find_min(int a1[], int size);
int find_max(int a1[], int size);

int array_equal(int a[], int b[], int size);

void array_copy(int a2[], int b2[], int size);

void rand_arr(int freq[], int size);
int find_many(int freq[], int n);

void rand_lotto(void);

void sum_arr(int arr[][5], int row, int col);

void made_arr(int cude_arr[][2]);
void find_cude_root(int cude_arr[][2], int cude);

double get_avg(double f_arr[], int size);
double get_std(double f_arr[], int size, double m);

void rand_score(int scores[][3]);
void get_min_max(int scores[][3], int row, int col);

void vector_add(double x[], double y[], double z[], int size);
void vector_dot_product(double x[], double y[], double z[], int size);

void scalar_mult(int matrix[][3], int mult_matrix[][3], int scalar);
void transpose(int matrix[][3], int transpose_matrix[][3]);

int get_max_area(int area[][6], int x, int y);

void rand_area(int area[][6], int size);

int main(void){
    // 1번 문제
    int days[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int size_days=sizeof(days)/sizeof(days[0]);

    print_days(days, size_days);

    // 2번 문제
    int a1[10]={0};

    rand_a1(a1, 10);

    int min=find_min(a1, 10);
    int max=find_max(a1, 10);

    printf("max: %d\n", max);
    printf("min: %d\n", min);

    // 3번 문제
    int a[]={1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    int b[]={0};
    int size_equal=sizeof(a)/sizeof(a[0]);

    int result_equal=array_equal(a, b, size_equal);

    if (result_equal == 1) printf("equal\n");
    else                   printf("different\n");

    // 4번 문제
    int a2[]={1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    int b2[]={0};
    int size_copy=sizeof(a2)/sizeof(a2[0]);

    for (int i = 0; i < size_copy; i++){
        printf("%d ", a2[i]);
    }
    printf("\n");

    array_copy(a2, b2, size_copy);

    for (int i = 0; i < size_copy; i++){
        printf("%d ", b2[i]);
    }
    printf("\n");

    // 5번 문제
    int freq[100]={0};

    rand_arr(freq, 100);

    int many=find_many(freq, 10);

    printf("max num: %d\n", many);

    // 6번 문제
    rand_lotto();

    // 7번 문제
    int arr[][5]={12, 56, 32, 16, 98, 99, 56, 34, 41, 3, 65, 3, 87, 78, 21};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    sum_arr(arr, row, col);

    // 8번 문제
    int cude_arr[10][2]={0};

    made_arr(cude_arr);

    int cude = 27;

    find_cude_root(cude_arr, cude);

    // 9번 문제
    double f_arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    double m = get_avg(f_arr, 10);
    double std = get_std(f_arr, 10, m);

    printf("mean = %f\n", m);
    printf("standard deviation = %f\n", std);

    // 10번 문제
    int scores[5][3];

    rand_score(scores);

    get_min_max(scores, 5, 3);

    // 11번 문제 - a
    double x[3] = {1.0, 2.0, 3.0};
    double y[3] = {1.0, 2.0, 3.0};
    double z_add[3];

    vector_add(x, y, z_add, 3);

    // 11번 문제 - b
    double z_dot_product[3];

    vector_dot_product(x, y, z_dot_product, 3);

    // 12번 문제 (scanf() 사용)

    // 13번 문제 - a
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int mult_matrix[3][3];

    scalar_mult(matrix, mult_matrix, 3);

    // 13번 문제 -b
    
    int transpose_matrix[3][3];

    transpose(matrix, transpose_matrix);

    // 14번 문제
    int area[6][6];
    // int area[6][6] = {1, 2, 3, 3, 5, 2, 1, 2, 3, 3, 5, 2, 1, 2, 3, 3, 5, 2, 1, 2, 3, 0, 0, 0, 1, 2, 3, 0, 0, 0, 1, 2, 3, 0, 0, 0,};
    int max_reserve = -1;

    rand_area(area, 6);
    for (int i = 0; i <= SIZE - AREA; i++){
        for (int j = 0; j <= SIZE - AREA; j++){
            int sum = get_max_area(area, i, j);

            if (sum > max_reserve){
                max_reserve = sum;
            }
        }
    }

    printf("max reseve : %d\n", max_reserve);

    // 15번 문제(안 해도 될 듯. 나오면 틀린다는 마인드)

    return 0;
}

void print_days(int days[], int size){
    for (int i = 0; i < size; i++){
        printf("%dm to %dd\n", i + 1, days[i]);
    }
}

void rand_a1(int a1[], int size){
    for (int i = 0; i < size; i++){
        a1[i] = rand();
    }
}
int find_min(int a1[], int size){
    int min=a1[0];

    for (int i = 0; i < size; i++){
        if (a1[i] < min) min = a1[i];
    }

    return min;
}
int find_max(int a1[], int size){
    int max=a1[0];

    for (int i = 0; i < size; i++){
        if (a1[i] > max) max = a1[i];
    }

    return max;
}

int array_equal(int a[], int b[], int size){
    for (int i = 0; i < size; i++){
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void array_copy(int a2[], int b2[], int size){
    for (int i = 0; i < size; i++){
        b2[i] = a2[i];
    }
}

void rand_arr(int freq[], int size){
    for (int i = 0; i < size; i++){
        ++freq[rand() % 10];
    }
}
int find_many(int freq[], int n){
    int count=freq[0];

    for (int i = 0; i < n; i++){
        if (freq[i] > count) count = i;
    }

    return count;
}

void rand_lotto(void){
    int check[45]={0}; // 0으로 채워진 크기가 45인 배열
    int i=0, lotto;
    
    srand((unsigned int)time(NULL));

    while (i < 6){ // for문은 중복이 발생하면 continue가 실행되면 증감식을 무조건 실행하기 때문에 for문 사용 불가
        lotto = rand() % 45 + 1;

        if (check[lotto] == 1) continue;

        printf("%d ", lotto);

        check[lotto] = 1; // 배열에서 1~45 범위 내의 난수로 생성된 lotto 인덱스를 1로 설정 (ex. lotto=4 -> check[4]=1)

        i++;
    }
    printf("\n");
}

void sum_arr(int arr[][5], int row, int col){
    int sum_row = 0, sum_col = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            sum_row += arr[i][j];
        }
        printf("sum of %drow: %d\n", i, sum_row);

        sum_row = 0;
    }

    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            sum_col += arr[j][i];
        }
        printf("sum of %dcol: %d\n", i, sum_col);

        sum_col = 0;
    }
}

void made_arr(int cude_arr[][2]){
    for (int i = 0; i < 10; i++){
        int n = i + 1;

        cude_arr[i][0] = n;
        cude_arr[i][1] = n * n * n;
    }

    // for (int i = 0; i < 10; i++){
    //     for (int j = 0; j < 2; j++){
    //         printf("%d ", cude[i][j]);
    //     }
    //     printf("\n");
    // }
}
void find_cude_root(int cude_arr[][2], int cude){
    int result = 1;
    for (int i = 0; i < 10; i++){
        if (cude_arr[i][1] == cude){
            result = 0;

            printf("cude root %d : %d\n", cude, cude_arr[i][0]);
        }
    }
    if (result == 1) printf("No cude root\n");
}

double get_avg(double f_arr[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += f_arr[i];
    }

    return sum / size;
}
double get_std(double f_arr[], int size, double m){
    double sum = 0;

    for (int i = 0; i < size; i++){
        sum += pow(f_arr[i] - m, 2);
    }

    return sqrt(sum / size);
}

void rand_score(int scores[][3]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            scores[i][j] = rand() % 101;
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
}
void get_min_max(int scores[][3], int row, int col){
    int min = scores[0][0], max = scores[0][0];

    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            if (scores[j][i] < min) min = scores[j][i];

            if (scores[j][i] > max) max = scores[j][i];
        }
        printf("test %d max : %d\n", i + 1, max);
        printf("test %d min : %d\n", i + 1, min);

        min = scores[0][i];
        max = scores[0][i];
    }
}

void vector_add(double x[], double y[], double z[], int size){
    for (int i = 0; i < size; i++){
        z[i] = x[i] + y[i];
    }

    for (int i = 0; i < size; i++){
        printf("%.2f ", x[i]);
    }
    printf("+ ");
    for (int i = 0; i < size; i++){
        printf("%.2f ", y[i]);
    }
    printf("= ");
    for (int i = 0; i < size; i++){
        printf("%.2f ", z[i]);
    }
    printf("\n");
}
void vector_dot_product(double x[], double y[], double z[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += x[i] * y[i];
    }
    
    for (int i = 0; i < size; i++){
        printf("%.2f ", x[i]);
    }
    printf("* ");
    for (int i = 0; i < size; i++){
        printf("%.2f ", y[i]);
    }
    printf("= ");
    printf("%.2f\n", sum);
}

void scalar_mult(int matrix[][3], int mult_matrix[][3], int scalar){
    for (int i = 0; i < scalar; i++){
        for (int j = 0; j < scalar; j++){
            mult_matrix[i][j] = 2 * matrix[i][j];
        }
    }

    for (int i = 0; i < scalar; i++){
        for (int j = 0; j < scalar; j++){
            printf("%d ", mult_matrix[i][j]);
        }
        printf("\n");
    }
}
void transpose(int matrix[][3], int transpose_matrix[][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            transpose_matrix[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }
}

void rand_area(int area[][6], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            area[i][j] = rand() % 201;
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d ", area[i][j]);
        }
        printf("\n");
    }
}
int get_max_area(int area[][6], int x, int y){
    int sum = 0;

    for (int i = x; i < x + AREA; i++){
        for (int j = y; j < y + AREA; j++){
            sum += area[i][j];
        }
    }

    return sum;
}