/*College Event Registration System: 
A college organizes five technical events. 
Each event has Event ID, Event Name and Number of Registered Students.
Develop a C program using an array of structures to read and display 
event details, identify the event with maximum registrations using a
user-defined function, and calculate the total number of registrations 
across all events using a recursive function.

*/
#include <stdio.h>

struct Event {
    char id[20], name[50];
    int registrations;
};

int maximum(struct Event e[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (e[i].registrations > e[max].registrations)
            max = i;
    }
    return max;
}

int totalRegistrations(struct Event e[], int n) {
    if (n == 0)
        return 0;
    return e[n - 1].registrations + totalRegistrations(e, n - 1);
}

int main() {
    struct Event e[5];
    int i, max;

    for (i = 0; i < 5; i++) {
        printf("\nEvent %d\n", i + 1);
        printf("Event ID: ");
        scanf(" %19[^\n]", e[i].id);
        printf("Event name: ");
        scanf(" %49[^\n]", e[i].name);
        printf("Number of registered students: ");
        scanf("%d", &e[i].registrations);
    }

    printf("\nEvent ID | Event Name | Registrations\n");
    for (i = 0; i < 5; i++)
        printf("%s | %s | %d\n",
               e[i].id, e[i].name, e[i].registrations);

    max = maximum(e, 5);
    printf("\nMaximum registrations: %s (%s), %d\n",
           e[max].name, e[max].id, e[max].registrations);
    printf("Total registrations: %d\n", totalRegistrations(e, 5));

    return 0;
}
