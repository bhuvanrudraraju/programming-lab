#include <stdio.h>

int main() {
    int x;

    printf("Enter permission value: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("No permissions\n");
    }
    else if ((x & 1) && (x & 2)) {
        printf("Read + Write\n");
    }
    else if (x & 1) {
        printf("Read only\n");
    }
    else if (x & 2) {
        printf("Write only\n");
    }
    else if (x & 4) {
        printf("Execute enabled\n");
    }

    return 0;
}
