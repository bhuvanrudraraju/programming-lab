#include <stdio.h>

int main() {
    int x;

    printf("Enter washing machine mode: ");
    scanf("%d", &x);

    switch (x) {
        case 1:
            printf("Quick Wash\n");
            printf("Water required\n");
            break;

        case 2:
            printf("Normal Wash\n");
            printf("Water required\n");
            break;

        case 3:
            printf("Heavy Wash\n");
            printf("Water required\n");
            break;

        case 4:
            printf("Delicate Wash\n");
            break;

        case 5:
            printf("Spin Only\n");
            break;

        default:
            printf("Invalid mode\n");
    }

    return 0;
}
