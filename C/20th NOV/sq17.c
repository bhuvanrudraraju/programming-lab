/*Restaurant Order Management System: 
A restaurant maintains order details of 10 customers. 
Each order contains Order ID, Customer Name, Number of Items 
and Total Bill Amount. Develop a C program using structures 
and arrays to read and display customer orders, identify the 
customer with the highest bill amount using a user-defined function,
and calculate the total revenue generated from all orders using recursion.

*/
#include <stdio.h>

struct Order {
    char id[20], name[50];
    int items;
    double bill;
};

int highest(struct Order o[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (o[i].bill > o[max].bill)
            max = i;
    }
    return max;
}

double totalRevenue(struct Order o[], int n) {
    if (n == 0)
        return 0;
    return o[n - 1].bill + totalRevenue(o, n - 1);
}

int main() {
    struct Order o[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nOrder %d\n", i + 1);
        printf("Order ID: ");
        scanf(" %19[^\n]", o[i].id);
        printf("Customer name: ");
        scanf(" %49[^\n]", o[i].name);
        printf("Number of items: ");
        scanf("%d", &o[i].items);
        printf("Total bill amount: ");
        scanf("%lf", &o[i].bill);
    }

    printf("\nOrder ID | Customer | Number of Items | Bill\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %.2f\n",
               o[i].id, o[i].name, o[i].items, o[i].bill);

    max = highest(o, 10);
    printf("\nHighest bill: %s (%s), %.2f\n",
           o[max].name, o[max].id, o[max].bill);
    printf("Total revenue: %.2f\n", totalRevenue(o, 10));

    return 0;
}
