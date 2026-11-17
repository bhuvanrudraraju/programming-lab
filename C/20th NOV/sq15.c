/*Electricity Bill Management System: 
An electricity board maintains records of 10 households.
Each record contains Consumer Number, Customer Name, 
Units Consumed and Bill Amount. Develop a C program using
structures and arrays to read and display consumer details, 
identify the household with the highest electricity consumption 
using a user-defined function, and calculate the total electricity 
bill collected from all households using recursion.
*/
#include <stdio.h>

struct Consumer {
    char number[20], name[50];
    double units, bill;
};

int highest(struct Consumer c[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (c[i].units > c[max].units)
            max = i;
    }
    return max;
}

double totalBills(struct Consumer c[], int n) {
    if (n == 0)
        return 0;
    return c[n - 1].bill + totalBills(c, n - 1);
}

int main() {
    struct Consumer c[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nHousehold %d\n", i + 1);
        printf("Consumer number: ");
        scanf(" %19[^\n]", c[i].number);
        printf("Customer name: ");
        scanf(" %49[^\n]", c[i].name);
        printf("Units consumed: ");
        scanf("%lf", &c[i].units);
        printf("Bill amount: ");
        scanf("%lf", &c[i].bill);
    }

    printf("\nConsumer Number | Customer | Units | Bill\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %.2f | %.2f\n",
               c[i].number, c[i].name, c[i].units, c[i].bill);

    max = highest(c, 10);
    printf("\nHighest consumption: %s (%s), %.2f units\n",
           c[max].name, c[max].number, c[max].units);
    printf("Total electricity bills: %.2f\n", totalBills(c, 10));

    return 0;
}
