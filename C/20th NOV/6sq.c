/*Bank Account Management System: 
A bank maintains account details of 10 customers. 
Each account contains Account Number, Customer Name,
Account Type and Available Balance. Develop a C program 
using structures and arrays to read and display customer details,
identify the customer having the highest account balance using a 
user-defined function, and calculate the total balance maintained
by all customers using recursion.
*/

#include <stdio.h>

struct Account {
    char number[20], name[50], type[50];
    double balance;
};

int highest(struct Account a[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].balance > a[max].balance)
            max = i;
    }
    return max;
}

double totalBalance(struct Account a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1].balance + totalBalance(a, n - 1);
}

int main() {
    struct Account a[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nCustomer %d\n", i + 1);
        printf("Account number: ");
        scanf(" %19[^\n]", a[i].number);
        printf("Customer name: ");
        scanf(" %49[^\n]", a[i].name);
        printf("Account type: ");
        scanf(" %49[^\n]", a[i].type);
        printf("Available balance: ");
        scanf("%lf", &a[i].balance);
    }

    printf("\nAccount Number | Customer | Account Type | Balance\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %s | %.2f\n",
               a[i].number, a[i].name, a[i].type, a[i].balance);

    max = highest(a, 10);
    printf("\nHighest balance: %s (%s), %.2f\n",
           a[max].name, a[max].number, a[max].balance);
    printf("Total balance: %.2f\n", totalBalance(a, 10));

    return 0;
}
