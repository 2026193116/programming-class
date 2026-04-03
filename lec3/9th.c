#include <stdio.h>
#define N 10

int main() {
    int a[N] = {1, 2, 3,4 ,5, 6, 7, 8, 9, 10};

    printf("size of a array is %lu\n", sizeof(a)); 
    printf("size of element of a  array's first element is %lu\n", sizeof(a[0]));
    printf("size of element of int is %lu\n", sizeof(int));

    int a_size = (int) sizeof(a) / sizeof(a[0]);
    printf("length of a array is %d\n", a_size);  //배열의 크기를 구해 적용하는 함수를 만들기 위해(배열의 종류에 상관없이) 
    int a_size2 = (int) sizeof(a) / sizeof(int);
    printf("length of a array is %d\n", a_size2);

    return 0;
}