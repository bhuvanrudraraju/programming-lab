/*Online Shopping Order Management System: 
An online shopping platform maintains details of 10 customer orders. 
Each order contains Order ID, Customer Name, Number of Products and 
Order Value. Develop a C program using structures and arrays to read 
and display order information, identify orders whose value exceeds
₹5,000 using a user-defined function, and calculate the total value
of all customer orders using recursion.

*/
#include <stdio.h>

struct Order {
    char id[20], name[50];
    int products;
    double value;
};

void showLargeOrders(struct Order o[], int n) {
    printf("\nOrders exceeding Rs. 5000:\n");
    for (int i = 0; i < n; i++) {
        if (o[i].value > 5000)
            printf("%s | %s | %.2f\n",
                   o[i].id, o[i].name, o[i].value);
    }
}

double totalValue(struct Order o[], int n) {
    if (n == 0)
        return 0;
    return o[n - 1].value + totalValue(o, n - 1);
}

int main() {
    struct Order o[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nOrder %d\n", i + 1);
        printf("Order ID: ");
        scanf(" %19[^\n]", o[i].id);
        printf("Customer name: ");
        scanf(" %49[^\n]", o[i].name);
        printf("Number of products: ");
        scanf("%d", &o[i].products);
        printf("Order value: ");
        scanf("%lf", &o[i].value);
    }

    printf("\nOrder ID | Customer | Number of Products | Order Value\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %.2f\n",
               o[i].id, o[i].name, o[i].products, o[i].value);

    showLargeOrders(o, 10);
    printf("Total order value: %.2f\n", totalValue(o, 10));

    return 0;
}
