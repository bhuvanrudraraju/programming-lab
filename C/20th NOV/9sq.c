/*Personal Expense Tracking System: 
A student records daily expenses for seven days. 
Each record contains Day, Expense Category and Amount.
Develop a C program using structures and arrays to 
read and display daily expenses, identify the day on 
which the student spent the maximum amount using a 
user-defined function, and calculate the total 
expenditure for seven days using recursion.
*/
#include <stdio.h>

struct Expense {
    char day[20], category[50];
    double amount;
};

int maximum(struct Expense e[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (e[i].amount > e[max].amount)
            max = i;
    }
    return max;
}

double totalExpenses(struct Expense e[], int n) {
    if (n == 0)
        return 0;
    return e[n - 1].amount + totalExpenses(e, n - 1);
}

int main() {
    struct Expense e[7];
    int i, max;

    for (i = 0; i < 7; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Day: ");
        scanf(" %19[^\n]", e[i].day);
        printf("Expense category: ");
        scanf(" %49[^\n]", e[i].category);
        printf("Amount: ");
        scanf("%lf", &e[i].amount);
    }

    printf("\nDay | Expense Category | Amount\n");
    for (i = 0; i < 7; i++)
        printf("%s | %s | %.2f\n",
               e[i].day, e[i].category, e[i].amount);

    max = maximum(e, 7);
    printf("\nMaximum spending day: %s, %.2f\n",
           e[max].day, e[max].amount);
    printf("Total expenditure: %.2f\n", totalExpenses(e, 7));

    return 0;
}
