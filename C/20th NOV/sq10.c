/*Loan Repayment Monitoring System: 
A bank maintains loan repayment records of 10 customers.
Each record contains Customer ID, Customer Name, Loan Amount
and Amount Repaid. Develop a C program using structures 
and arrays to read and display loan details, calculate 
the outstanding loan amount using a user-defined function, 
identify customers whose outstanding loan is greater than 
₹50,000, and calculate the total outstanding loan amount using recursion.
*/

#include <stdio.h>

struct Loan {
    char id[20], name[50];
    double amount, repaid;
};

double outstanding(struct Loan l) {
    return l.amount - l.repaid;
}

double totalOutstanding(struct Loan l[], int n) {
    if (n == 0)
        return 0;
    return outstanding(l[n - 1]) + totalOutstanding(l, n - 1);
}

int main() {
    struct Loan l[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nCustomer %d\n", i + 1);
        printf("Customer ID: ");
        scanf(" %19[^\n]", l[i].id);
        printf("Customer name: ");
        scanf(" %49[^\n]", l[i].name);
        printf("Loan amount: ");
        scanf("%lf", &l[i].amount);
        printf("Amount repaid: ");
        scanf("%lf", &l[i].repaid);
    }

    printf("\nID | Name | Loan Amount | Amount Repaid | Outstanding\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %.2f | %.2f | %.2f\n",
               l[i].id, l[i].name, l[i].amount,
               l[i].repaid, outstanding(l[i]));

    printf("\nCustomers with outstanding loan above Rs. 50000:\n");
    for (i = 0; i < 10; i++) {
        if (outstanding(l[i]) > 50000)
            printf("%s (%s): %.2f\n",
                   l[i].name, l[i].id, outstanding(l[i]));
    }

    printf("Total outstanding amount: %.2f\n",
           totalOutstanding(l, 10));

    return 0;
}
