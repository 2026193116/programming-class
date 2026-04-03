#include <stdio.h>

int main(){
    int from = 8;
    int to = 16;
    int baesu = 7;

    int d;
    int result = -1;

    for (d = from; d <= to; d++) {
        if(d % baesu == 0){
            result = d;
            break;
        }
    }
    if(result == -1){
        printf("from %d to %d no %d baesu exists.", from, to ,baesu);
    }
    else {
        printf("from %d to %d, minimum %d baesu is %d.", from, to, baesu, result);
    }
    //무한루프 for(; ;)

    return 0;
}