/*Public Transport Bus Pass Management System: 
A transport department maintains bus pass details of 
10 students. Each record contains Pass Number, Student Name, 
Route Number and Pass Fee. Develop a C program using 
structures and arrays to read and display bus pass records, 
count the number of students travelling on a particular route using 
a user-defined function, and calculate the total bus pass fee collected using recursion.
*/
#include <stdio.h>
#include <string.h>

struct BusPass {
    char number[20], name[50], route[20];
    double fee;
};

int countRoute(struct BusPass b[], int n, char route[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(b[i].route, route) == 0)
            count++;
    }
    return count;
}

double totalFees(struct BusPass b[], int n) {
    if (n == 0)
        return 0;
    return b[n - 1].fee + totalFees(b, n - 1);
}

int main() {
    struct BusPass b[10];
    char route[20];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Pass number: ");
        scanf(" %19[^\n]", b[i].number);
        printf("Student name: ");
        scanf(" %49[^\n]", b[i].name);
        printf("Route number: ");
        scanf(" %19[^\n]", b[i].route);
        printf("Pass fee: ");
        scanf("%lf", &b[i].fee);
    }

    printf("\nPass Number | Student | Route | Fee\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %s | %.2f\n",
               b[i].number, b[i].name, b[i].route, b[i].fee);

    printf("\nEnter route number to count: ");
    scanf(" %19[^\n]", route);

    printf("Students on route %s: %d\n",
           route, countRoute(b, 10, route));
    printf("Total bus pass fees: %.2f\n", totalFees(b, 10));

    return 0;
}
