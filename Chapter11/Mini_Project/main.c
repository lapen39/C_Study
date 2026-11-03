#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void get_sensor_data(double *p);

int main(void){
    // 자율 주행 자동차
    double sensor_data[3];

    get_sensor_data(sensor_data);

    printf("distance to left sensor: %f\n", sensor_data[0]);
    printf("distance to middle sensor: %f\n", sensor_data[1]);
    printf("distance to right sensor: %f\n", sensor_data[2]);

    return 0;
}

void get_sensor_data(double *p){
    for (int i = 0; i < 3; i++){
        p[i] = rand()%100;
    }
}