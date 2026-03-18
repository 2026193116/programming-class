#include <stdio.h>

int main() {
    int a;
    int b;
    if (0) printf("Print 0 run!!\n");
    if (1) printf("Print 1 run!!\n");
    if (-5) printf("Print -5 run!!\n");
    if (a = 1) printf("Print 1 run!!\n");
    if (b = 0) printf("Print 0 run!!\n");
    return 0;
    //0만 아니면 출력된다! () -> 표현식, 숫자 하나만 들어가도 OK
}