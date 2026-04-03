#include <stdio.h>

int main() {
    float a = 10.0;
    int b = 3;

    int c = b/a;
    printf("%d / %f = %d\n", b , a, c); // 0.3 -> 0 출력
    float d = b/a;
    printf("%d / %f = %f\n", b , a, d);
    
    int e = 10;
    float f = b / e;
    printf("%d / %d = %f\n", b, e, f); // f는 float but b,e -> int : 0으로 출력
    return 0;
}