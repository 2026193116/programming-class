#include <stdio.h>

int main() {
    int var_score = 85;

    switch (var_score /10) {
        case 9 :
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
