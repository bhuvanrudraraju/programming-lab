/*Monthly Salary Processing System: 
A company maintains salary details of 10 employees. 
Each employee has Employee ID, Name, Basic Salary, HRA and DA.
Develop a C program using structures and arrays to read 
and display employee details, calculate gross salary using u
ser-defined functions, identify the employee receiving the 
highest gross salary, and calculate the total salary 
expenditure of the company using recursion.
*/

#include <stdio.h>

struct Employee {
    char id[20], name[50];
    double basic, hra, da;
};

double gross(struct Employee e) {
    return e.basic + e.hra + e.da;
}

int highest(struct Employee e[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (gross(e[i]) > gross(e[max]))
            max = i;
    }
    return max;
}

double totalSalary(struct Employee e[], int n) {
    if (n == 0)
        return 0;
    return gross(e[n - 1]) + totalSalary(e, n - 1);
}

int main() {
    struct Employee e[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: ");
        scanf(" %19[^\n]", e[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", e[i].name);
        printf("Basic salary: ");
        scanf("%lf", &e[i].basic);
        printf("HRA amount: ");
        scanf("%lf", &e[i].hra);
        printf("DA amount: ");
        scanf("%lf", &e[i].da);
    }

    printf("\nID | Name | Basic Salary | HRA | DA | Gross Salary\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %.2f | %.2f | %.2f | %.2f\n",
               e[i].id, e[i].name, e[i].basic,
               e[i].hra, e[i].da, gross(e[i]));

    max = highest(e, 10);
    printf("\nHighest gross salary: %s (%s), %.2f\n",
           e[max].name, e[max].id, gross(e[max]));
    printf("Total salary expenditure: %.2f\n", totalSalary(e, 10));

    return 0;
}
