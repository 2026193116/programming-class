#include <stdio.h>

int main() {
    // 별로 산 만들기
    for (int i = 1; i <= 7; i++) {
        // 공백 출력
        for (int j = 0; j < 7 - i; j++) {
            printf(" ");
        }
        // 별 출력
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}