/*ATM Transaction Monitoring System: 
An ATM stores transaction details of 10 customers. 
Each transaction contains Transaction ID, Account Number,
Transaction Type and Transaction Amount. Develop a C program 
using structures and arrays to read and display transaction records,
identify transactions exceeding ₹10,000 using a user-defined function,
and calculate the total withdrawal amount using a recursive function.
*/
#include <stdio.h>

struct Transaction {
    char id[20], account[20];
    int type;
    double amount;
};

void showLarge(struct Transaction t[], int n) {
    printf("\nTransactions exceeding Rs. 10000:\n");
    for (int i = 0; i < n; i++) {
        if (t[i].amount > 10000)
            printf("%s | %s | %.2f\n",
                   t[i].id, t[i].account, t[i].amount);
    }
}

double totalWithdrawals(struct Transaction t[], int n) {
    if (n == 0)
        return 0;

    if (t[n - 1].type == 1)
        return t[n - 1].amount + totalWithdrawals(t, n - 1);

    return totalWithdrawals(t, n - 1);
}

int main() {
    struct Transaction t[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nTransaction %d\n", i + 1);
        printf("Transaction ID: ");
        scanf(" %19[^\n]", t[i].id);
        printf("Account number: ");
        scanf(" %19[^\n]", t[i].account);
        printf("Type (1 = Withdrawal, 2 = Deposit): ");
        scanf("%d", &t[i].type);
        printf("Transaction amount: ");
        scanf("%lf", &t[i].amount);
    }

    printf("\nTransaction ID | Account | Type | Amount\n");
    for (i = 0; i < 10; i++) {
        printf("%s | %s | ", t[i].id, t[i].account);

        if (t[i].type == 1)
            printf("Withdrawal");
        else
            printf("Deposit");

        printf(" | %.2f\n", t[i].amount);
    }

    showLarge(t, 10);
    printf("Total withdrawal amount: %.2f\n",
           totalWithdrawals(t, 10));

    return 0;
}
