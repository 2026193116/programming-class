#include <stdio.h>

int main() {
    int a = 10;
    float b = 3.14;
    char c = 'D';

    if('a' < 'b') {
        printf("b(%c-%d) is greater than a(%c-%d)\n", 'b', 'b', 'a', 'a');
    }
    printf("before c : %c\n", c);
    if('A' <= c && c <= 'Z') {
        c = c + 'a' - 'A';
        //대문자로 전환 : 소문자 범위 & -'a' + 'A' 
    }
    printf("after c : %c\n", c);
    return 0;
}