#include <stdio.h>

int main() {
    int a = 65;
    printf("a %%d : %d\n", a);
    printf("a %%i : %i\n", a);
    printf("a %%c : %c\n", a);
    printf("a %%f : %f\n", (float)a);

    char b = 'A';
    printf("b %%d : %d\n", b);
    printf("b %%i : %i\n", b);
    printf("b %%c : %c\n", b+32);
    printf("b %%f : %f\n", (float)b);

    int c = -3;
    printf("c %%d : %d\n", c);
    printf("c %%i : %i\n", c);
    printf("c %%c : %c\n", c);
    printf("c %%f : %f\n", (float)c);
    printf("c %%u : %u\n", c);

    int d = 128;
    printf("d %%d : %d\n", d);
    printf("d %%i : %i\n", d);
    printf("d %%c : %c\n", d);
    printf("d %%f : %f\n", (float)d);
    printf("d %%e : %e\n", d);

    unsigned char ch=  254;
    printf("ch %%d : %d\n", ch);
    printf("ch %%i : %i\n", ch);
    printf("ch %%c : %c\n", ch);
    printf("ch %%f : %f\n", ch);

    char strc[5] = "abcd";
    printf("strc %%c : %c\n", strc);
    printf("strc %%d : %d\n", strc);
    printf("strc %%s : %s\n", strc);
    
    return 0; 
}
