#include <stdio.h>

int main(){
    int a = 6;
    if((-5 <= a) && (a < 4)){
        printf("Print 1 run!!\n");
    }
    //-5 <= a < 4 -> (-5<=a)<4 -> 1<4 -> true
}