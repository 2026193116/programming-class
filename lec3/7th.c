#include <stdio.h>

#define N 3

int main(){
    int a[N];

    for(int i = 0; i < N; i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < N; i++){
        printf("Element %d = %d\n", i+1 ,a[i]);
    }
    return 0;
}