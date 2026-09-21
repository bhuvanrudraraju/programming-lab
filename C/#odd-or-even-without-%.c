#include <stdio.h>

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x & 1)
        printf("Odd\n");
    else
        printf("Even\n");

    return 0;
}
