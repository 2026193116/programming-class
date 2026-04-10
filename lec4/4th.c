#include <stdio.h>

int isPrime(int number);

int main() {

    int number = 29;

    if(isPrime(number)) {
        printf("%d is prime number.\n", number);
    }
    else {
        printf("%d is not prime number.\n", number);
    }

    return 0;
}

int isPrime(int n) {
    if(n <= 1) {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++) {
        if(n % i == 0) {
            return  // Not prme
        }
    }

    return 1;
}