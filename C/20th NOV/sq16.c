/*Supermarket Billing System:
A supermarket maintains details of 10 products. 
Each product has Product ID, Product Name, Quantity Sold 
and Unit Price. Develop a C program using structures and 
arrays to read and display product details, calculate the 
sales revenue of each product using a user-defined function,
identify the product generating the highest revenue, and 
calculate the total sales amount using recursion.
*/
#include <stdio.h>

struct Product {
    char id[20], name[50];
    int quantity;
    double price;
};

double revenue(struct Product p) {
    return p.quantity * p.price;
}

int highest(struct Product p[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (revenue(p[i]) > revenue(p[max]))
            max = i;
    }
    return max;
}

double totalSales(struct Product p[], int n) {
    if (n == 0)
        return 0;
    return revenue(p[n - 1]) + totalSales(p, n - 1);
}

int main() {
    struct Product p[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nProduct %d\n", i + 1);
        printf("Product ID: ");
        scanf(" %19[^\n]", p[i].id);
        printf("Product name: ");
        scanf(" %49[^\n]", p[i].name);
        printf("Quantity sold: ");
        scanf("%d", &p[i].quantity);
        printf("Unit price: ");
        scanf("%lf", &p[i].price);
    }

    printf("\nProduct ID | Name | Quantity | Unit Price | Revenue\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %.2f | %.2f\n",
               p[i].id, p[i].name, p[i].quantity,
               p[i].price, revenue(p[i]));

    max = highest(p, 10);
    printf("\nHighest revenue product: %s (%s), %.2f\n",
           p[max].name, p[max].id, revenue(p[max]));
    printf("Total sales amount: %.2f\n", totalSales(p, 10));

    return 0;
}
