#include <stdio.h>

int main() {
    int var_floor = 3;
    int var_ho = 4;

    if(var_floor % 2 == 0) {
        if(var_ho % 2 == 0){
            printf("ev4\n");
        }
        else{
            printf("ev3\n");
        }
    }
    else {
        if(var_ho % 2 == 0){
            printf("ev2\n");
        }
        else {
            printf("ev1\n");
        }
    }

    return 0;
}
