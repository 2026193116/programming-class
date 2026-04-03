#include <stdio.h>

float average(float input[], int input_num){
    float sum = 0.0;
    int num = input_num;
    for(int i = 0; i < 5; i++){
        sum += input[i];
    }
    float average = sum / num;
    return average;
}

int main() {
    float a[5] = {100.0, 95.0, 93.0, 90.0, 85.0};
    float b[5] = {60.0, 65.0, 70.0, 75.0, 80.0};
    float c[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int size_a = sizeof(a) / sizeof(a[0]);
    float avg = average(a, size_a);
    int size_b = sizeof(b) / sizeof(b[0]);
    float avg_b = average(b, size_b);
    int size_c = sizeof(c) / sizeof(c[0]);
    float avg_c = average(c, size_c);

    printf("Average of a is : %f\n", avg);
    printf("Average of b is : %f\n", avg_b);
    printf("Average of c is : %f\n", avg_c);
    return 0;
}