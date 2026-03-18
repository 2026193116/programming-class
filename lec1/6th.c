#include <stdio.h>

int main() {
    int a = 3;
    printf("a : %d\n", ++a);
    printf("a : %d\n", a++);
    printf("a : %d\n", a);
    // ++a : 코드 실행 전 a = a+1
    // a++ : 코드 실행 후 a = a+1
    return 0;
}