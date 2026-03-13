#include <stdio.h>

int main() {
    int num1, num2;

    printf("첫 번째 정수 : ");
    scanf("%d", &num1);
    printf("두 번째 정수 : ");
    scanf("%d", &num2);

    printf("더하기 : %d\n", num1 + num2);
    printf("빼기 : %d\n", num1 - num2);
    printf("곱하기 : %d\n", num1 * num2);
    printf("나누기 : %d\n", num1 / num2);
    
    return 0;
}