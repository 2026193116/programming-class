#include <stdio.h>

int main() {
    int var_score = 100;

    switch (var_score /10) {
        case 10 :
        case 9 :  //case 10 : case 9 : 가로로 붙여 쓰는 것도 가능
            printf("A grade\n");
            break;
        case 8 :
            printf("B grade\n");
            break;
        case 7 :
            printf("C grade\n");
            break;
        default :
            printf("F grade\n");
            break;
    }

    return 0;
}
