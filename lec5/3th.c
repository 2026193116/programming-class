#include <stdio.h>

int main() {
    int value = 50;
    int* p = &value;

    printf("p : %p\n", p);
    printf("&p : %p\n", &p);

    printf("value : %d\n", value);
    printf("*p : %d\n", *p); 
    printf("*&value : %d\n", *&value);
    printf("*&p : %d\n", *&p);
    printf("&*&p : %d\n", &*&p);
}  //*은 값을 출력, &은 주소 출력
//왜 주소값으로 저장하면 오류가 안 뜨고, 변수로 저장하면 오류가 뜨는지