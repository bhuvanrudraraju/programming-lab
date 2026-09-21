#include <stdio.h>

int main()
{
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);

    if (x < 0)
        printf("Negative input");
    else if (x * x > 100)
        printf("x² > 100");
    else if (x * x == 100)
        printf("x² == 100");
    else
        printf("x² < 100");

    return 0;
}
