/*Warehouse Stock Management System: 
A warehouse maintains stock information of 10 products. 
Each product has Product Code, Product Name, Opening Stock, 
Received Stock and Sold Stock. Develop a C program using structures
and arrays to read and display product details, calculate the 
closing stock using a user-defined function, identify products 
whose closing stock is below 20 units, and calculate the total
closing stock of all products using recursion.
*/
#include <stdio.h>

struct Product {
    char code[20], name[50];
    int opening, received, sold;
};

int closing(struct Product p) {
    return p.opening + p.received - p.sold;
}

int totalStock(struct Product p[], int n) {
    if (n == 0)
        return 0;
    return closing(p[n - 1]) + totalStock(p, n - 1);
}

int main() {
    struct Product p[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nProduct %d\n", i + 1);
        printf("Product code: ");
        scanf(" %19[^\n]", p[i].code);
        printf("Product name: ");
        scanf(" %49[^\n]", p[i].name);
        printf("Opening stock: ");
        scanf("%d", &p[i].opening);
        printf("Received stock: ");
        scanf("%d", &p[i].received);
        printf("Sold stock: ");
        scanf("%d", &p[i].sold);
    }

    printf("\nCode | Name | Opening | Received | Sold | Closing\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %d | %d | %d\n",
               p[i].code, p[i].name, p[i].opening,
               p[i].received, p[i].sold, closing(p[i]));

    printf("\nProducts with closing stock below 20:\n");
    for (i = 0; i < 10; i++) {
        if (closing(p[i]) < 20)
            printf("%s | %s | %d\n",
                   p[i].code, p[i].name, closing(p[i]));
    }

    printf("Total closing stock: %d\n", totalStock(p, 10));

    return 0;
}
