/*Pharmacy Inventory Management System:
A pharmacy maintains details of 10 medicines. 
Each medicine has Medicine ID, Medicine Name, 
Available Quantity and Price. Develop a C program 
using structures and arrays to read and display 
medicine records, identify medicines whose available 
quantity is below 10 using a user-defined function, 
and calculate the total inventory value of all medicines using recursion.

*/
#include <stdio.h>

struct Medicine {
    char id[20], name[50];
    int quantity;
    double price;
};

void showLowStock(struct Medicine m[], int n) {
    printf("\nMedicines with quantity below 10:\n");
    for (int i = 0; i < n; i++) {
        if (m[i].quantity < 10)
            printf("%s | %s | %d\n",
                   m[i].id, m[i].name, m[i].quantity);
    }
}

double inventoryValue(struct Medicine m[], int n) {
    if (n == 0)
        return 0;
    return m[n - 1].quantity * m[n - 1].price
           + inventoryValue(m, n - 1);
}

int main() {
    struct Medicine m[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nMedicine %d\n", i + 1);
        printf("Medicine ID: ");
        scanf(" %19[^\n]", m[i].id);
        printf("Medicine name: ");
        scanf(" %49[^\n]", m[i].name);
        printf("Available quantity: ");
        scanf("%d", &m[i].quantity);
        printf("Price per unit: ");
        scanf("%lf", &m[i].price);
    }

    printf("\nMedicine ID | Name | Quantity | Price\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %.2f\n",
               m[i].id, m[i].name, m[i].quantity, m[i].price);

    showLowStock(m, 10);
    printf("Total inventory value: %.2f\n", inventoryValue(m, 10));

    return 0;
}
