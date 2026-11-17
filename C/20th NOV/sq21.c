/*Mobile Recharge Management System:
A mobile service provider maintains recharge details of 10 customers.
Each record contains Mobile Number, Customer Name, Recharge Plan and 
Recharge Amount. Develop a C program using structures and arrays to 
read and display recharge details, identify customers who selected 
recharge plans above ₹500 using a user-defined function, and calculate 
the total recharge amount collected from all customers using recursion.
*/
#include <stdio.h>

struct Recharge {
    char mobile[20], name[50], plan[50];
    double amount;
};

void showAbove500(struct Recharge r[], int n) {
    printf("\nCustomers with recharge plans above Rs. 500:\n");
    for (int i = 0; i < n; i++) {
        if (r[i].amount > 500)
            printf("%s | %s | %s | %.2f\n",
                   r[i].mobile, r[i].name, r[i].plan, r[i].amount);
    }
}

double totalRecharge(struct Recharge r[], int n) {
    if (n == 0)
        return 0;
    return r[n - 1].amount + totalRecharge(r, n - 1);
}

int main() {
    struct Recharge r[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nCustomer %d\n", i + 1);
        printf("Mobile number: ");
        scanf(" %19[^\n]", r[i].mobile);
        printf("Customer name: ");
        scanf(" %49[^\n]", r[i].name);
        printf("Recharge plan: ");
        scanf(" %49[^\n]", r[i].plan);
        printf("Recharge amount: ");
        scanf("%lf", &r[i].amount);
    }

    printf("\nMobile Number | Customer | Recharge Plan | Amount\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %s | %.2f\n",
               r[i].mobile, r[i].name, r[i].plan, r[i].amount);

    showAbove500(r, 10);
    printf("Total recharge amount: %.2f\n", totalRecharge(r, 10));

    return 0;
}
