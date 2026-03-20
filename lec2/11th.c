#include <stdio.h>

int main(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 5; j++){
            if (j == i){
                //break;
                continue;
            }
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}