/*Department Placement Management System: 
A department maintains placement information of 10 students.
Each student record contains Register Number, Name, Company Name 
and Annual Salary Package. Develop a C program using structures 
and arrays to read and display placement details, identify the student
who received the highest salary package using a user-defined function, 
and calculate the total salary package offered to all students using recursion.
*/

#include <stdio.h>

struct Student {
    char reg[20], name[50], company[50];
    double package;
};

int highest(struct Student s[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].package > s[max].package)
            max = i;
    }
    return max;
}

double totalPackages(struct Student s[], int n) {
    if (n == 0)
        return 0;
    return s[n - 1].package + totalPackages(s, n - 1);
}

int main() {
    struct Student s[10];
    int i, max;

    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Register number: ");
        scanf(" %19[^\n]", s[i].reg);
        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);
        printf("Company name: ");
        scanf(" %49[^\n]", s[i].company);
        printf("Annual salary package: ");
        scanf("%lf", &s[i].package);
    }

    printf("\nRegister | Name | Company | Annual Package\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %s | %.2f\n",
               s[i].reg, s[i].name, s[i].company, s[i].package);

    max = highest(s, 10);
    printf("\nHighest package: %s (%s), %.2f\n",
           s[max].name, s[max].reg, s[max].package);
    printf("Total salary packages: %.2f\n", totalPackages(s, 10));

    return 0;
}
