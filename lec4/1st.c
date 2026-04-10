#include <stdio.h>

double get_average(double a, double b) {
    return (a + b) / 2.0;
}

int main() {
    double avg_result = get_average(17.0, 20.0);
    printf("The average of a and b is %f\n", avg_result);

    int a= 3;
    int b = 8;

    printf("a+b - %d\n", a+b);
    
    return 0;
}