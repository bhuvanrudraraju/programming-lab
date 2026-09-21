#include <stdio.h>

int main() {
    int x;

    printf("Enter order status: ");
    scanf("%d", &x);

    switch (x) {
        case 1:
            printf("Order placed\n");
            break;

        case 2:
            printf("Restaurant preparing\n");
            break;

        case 3:
            printf("Out for delivery\n");
            break;

        case 4:
            printf("Order completed\n");
            printf("Delivered successfully\n");
            break;

        case 5:
            printf("Order completed\n");
            printf("Order was cancelled\n");
            break;

        default:
            printf("Invalid status\n");
    }

    return 0;
}
