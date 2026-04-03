#include <stdio.h>

#define MAX_SIZE 100 //입력가능한 숫자 개수
#define RANGE 100 //숫자 범위(0~99)

int main() {
    int n, i, number;
    int frequency[RANGE] = {0}; // 빈도수 저장
    //int arr [MAX_SIZE]; // 사용자 입력값 저장

    printf("Enter the number of elements :");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Input %d number :", i+1);
        scanf("%d", &number);
        //arr [i] = number;
        if(number >=0 && number < RANGE){
            frequency[number]++; 
        }
    }

        printf("Number frequency\n");
        for(i=0;i<RANGE;i++){
            printf("%d : %d\n", i, frequency[i]);
        }
    
    return 0;
}