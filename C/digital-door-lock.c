#include <stdio.h>

int main() 
{
    int x;

    printf("Enter numeric access level: ");
    scanf("%d", &x);

    switch (x) {
        case 0:
            printf("Locked\n");
            break;

        case 1:
            printf("Guest Access\n");
            break;

        case 2:
            printf("Family Access\n");
            break;

        case 3:
            printf("Admin Access\n");
            break;

        default:
            printf("Invalid access level\n");
    }

    return 0;
}
