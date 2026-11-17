/*Hospital Patient Management System: 
A hospital maintains records of 10 patients. 
Each patient has Patient ID, Name, Age and Consultation Fee.
Develop a C program using structures and arrays to read
and display patient details, identify the oldest patient 
and the patient who paid the highest consultation fee using 
user-defined functions, and calculate the total consultation 
fees collected by the hospital using recursion.
*/
#include <stdio.h>

struct Patient {
    char id[20], name[50];
    int age;
    double fee;
};

int oldest(struct Patient p[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].age > p[max].age)
            max = i;
    }
    return max;
}

int highestFee(struct Patient p[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].fee > p[max].fee)
            max = i;
    }
    return max;
}

double totalFees(struct Patient p[], int n) {
    if (n == 0)
        return 0;
    return p[n - 1].fee + totalFees(p, n - 1);
}

int main() {
    struct Patient p[10];
    int i, old, high;

    for (i = 0; i < 10; i++) {
        printf("\nPatient %d\n", i + 1);
        printf("Patient ID: ");
        scanf(" %19[^\n]", p[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", p[i].name);
        printf("Age: ");
        scanf("%d", &p[i].age);
        printf("Consultation fee: ");
        scanf("%lf", &p[i].fee);
    }

    printf("\nPatient ID | Name | Age | Consultation Fee\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %.2f\n",
               p[i].id, p[i].name, p[i].age, p[i].fee);

    old = oldest(p, 10);
    high = highestFee(p, 10);

    printf("\nOldest patient: %s (%s), %d years\n",
           p[old].name, p[old].id, p[old].age);
    printf("Highest consultation fee: %s (%s), %.2f\n",
           p[high].name, p[high].id, p[high].fee);
    printf("Total consultation fees: %.2f\n", totalFees(p, 10));

    return 0;
}
