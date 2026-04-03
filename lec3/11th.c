#include <stdio.h>

int main() {
    char  string[10] = "10elements";
    //printf("%s\n", string);

    for(int i = 0; i<10; i++) {
        printf("%c\n", string[i]);
    }
    printf("%s\n", string);
    return 0;
}