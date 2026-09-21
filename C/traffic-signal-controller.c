#include <stdio.h>

int main() {
    int x;

    printf("Enter traffic signal number: ");
    scanf("%d", &x);

    switch (x) {
        case 1:
            printf("Red\n");
            break;

        case 2:
            printf("Yellow\n");
            break;

        case 3:
            printf("Green\n");
            break;

        default:
            printf("Invalid Number\n");
    }

    return 0;
}
