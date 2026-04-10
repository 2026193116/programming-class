#include <stdio.h>
int main() {
    int a =50;
    int b = 30;

    printf("a : %d\n", a);
    printf("b : %d\n", b);

    printf("a adress : %p\n", &a);
    printf("b adress : %p\n", &b);

    int c_to_a = a;
    printf("c_to_a : %d\n", c_to_a);

    int *c_to_address_a = &a; //&a = 주소, 따라서 int에 자료값이 받지 않음 & *로 자료형 표시
    int* c_toaddress_b = &b;
    printf("c_to_addressz_a : %p\n", c_to_address_a);
    printf("c_to_address_b : %p\n", c_toaddress_b);

    printf("c_to_adress_a_adress : %p\n", &c_to_address_a);
    printf("c_to_address_b_adress : %p\n", &c_toaddress_b);
}