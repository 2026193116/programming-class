#include <stdio.h>

int globalVar = 10;

void demoFunction() {
    int localVar = 5;
    printf("지역변수 : %d\n", localVar);
    globalVar += 10;
}

int main() {
    printf("전역 변수 초기 값 : %d\n", globalVar);

    demoFunction();

    printf("함수 호출 후 전역 변수 값 : %d\n", globalVar);
    return 0;

}