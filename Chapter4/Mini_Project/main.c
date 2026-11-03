#include <stdio.h>

double compute_time(double light_speed, double distance);
double second_to_minute(double time, double minute);

int main(void){
    double light_speed=300000, distance=149600000, minute=60;
    double time=compute_time(light_speed, distance);
    double second2minute=second_to_minute(time, minute);

    printf("time(minute): %lf", second2minute);

    return 0;
}

double compute_time(double light_speed, double distance){
    return distance / light_speed;
}
double second_to_minute(double time, double minute){
    return time / minute;
}