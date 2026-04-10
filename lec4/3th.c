#include <stdio.h>

/**
* @brief Checks if 'a' is greater than 'b'.
*
* @param a the first value to compare.
* @param b the second value to compare.
* @return int - 1 if 'a' is greater than 'b', 0 otherwise.
*/

int isGreaterThan(int a, int b);

int main() {
    int a = 3;
    int b = 5;

    if (isGreaterThan(a, b)) {
        printf("%d is greater than %d\n", a, b);
    } else {
        printf("%d is not greater than %d\n", a, b);
    }

    return 0;
}

int isGreaterThan(int a, int b) {
    return a > b;
}

