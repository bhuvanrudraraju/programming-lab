#include <stdio.h>

int main() {
    int x;

    printf("Enter a positive integer: ");
    scanf("%d", &x);

    if (x > 0 && (x & (x - 1)) == 0)
        printf("Power of two\n");
    else
        printf("Not a power of two\n");

    return 0;
}
