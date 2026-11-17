/*⁠E-Waste Collection Management System: 
An organization collects electronic waste from f
ive collection centres. Each centre has Centre ID, 
Centre Name, Number of Computers, Number of Mobile Phones
and Number of Printers collected. Develop a C program 
using structures and arrays to read and display collection
centre details, identify the centre that collected the maximum 
number of devices using a user-defined function, and calculate 
the total number of electronic devices collected across all centres using recursion.

*/
#include <stdio.h>

struct Centre {
    char id[20], name[50];
    int computers, mobiles, printers;
};

int devices(struct Centre c) {
    return c.computers + c.mobiles + c.printers;
}

int maximum(struct Centre c[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (devices(c[i]) > devices(c[max]))
            max = i;
    }
    return max;
}

int totalDevices(struct Centre c[], int n) {
    if (n == 0)
        return 0;
    return devices(c[n - 1]) + totalDevices(c, n - 1);
}

int main() {
    struct Centre c[5];
    int i, max;

    for (i = 0; i < 5; i++) {
        printf("\nCentre %d\n", i + 1);
        printf("Centre ID: ");
        scanf(" %19[^\n]", c[i].id);
        printf("Centre name: ");
        scanf(" %49[^\n]", c[i].name);
        printf("Number of computers: ");
        scanf("%d", &c[i].computers);
        printf("Number of mobile phones: ");
        scanf("%d", &c[i].mobiles);
        printf("Number of printers: ");
        scanf("%d", &c[i].printers);
    }

    printf("\nCentre ID | Name | Computers | Mobiles | Printers | Total\n");
    for (i = 0; i < 5; i++)
        printf("%s | %s | %d | %d | %d | %d\n",
               c[i].id, c[i].name, c[i].computers,
               c[i].mobiles, c[i].printers, devices(c[i]));

    max = maximum(c, 5);
    printf("\nMaximum devices: %s (%s), %d\n",
           c[max].name, c[max].id, devices(c[max]));
    printf("Total devices collected: %d\n", totalDevices(c, 5));

    return 0;
}
