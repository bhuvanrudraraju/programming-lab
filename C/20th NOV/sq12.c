/*Blood Donation Management System: 
A blood bank maintains information about 10 donors. 
Each donor has Donor ID, Name, Blood Group and Number of Previous Donations.
Develop a C program using structures and arrays to read and display donor details, 
search for donors belonging to a particular blood group using a user-defined function,
and calculate the total number of previous donations made by all donors using recursion.
*/
#include <stdio.h>
#include <string.h>

struct Donor {
    char id[20], name[50], group[10];
    int donations;
};

void searchGroup(struct Donor d[], int n, char group[]) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(d[i].group, group) == 0) {
            printf("%s | %s | %s | %d\n",
                   d[i].id, d[i].name, d[i].group, d[i].donations);
            found = 1;
        }
    }

    if (found == 0)
        printf("No matching donors.\n");
}

int totalDonations(struct Donor d[], int n) {
    if (n == 0)
        return 0;
    return d[n - 1].donations + totalDonations(d, n - 1);
}

int main() {
    struct Donor d[10];
    char group[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nDonor %d\n", i + 1);
        printf("Donor ID: ");
        scanf(" %19[^\n]", d[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", d[i].name);
        printf("Blood group: ");
        scanf(" %9[^\n]", d[i].group);
        printf("Number of previous donations: ");
        scanf("%d", &d[i].donations);
    }

    printf("\nDonor ID | Name | Blood Group | Previous Donations\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %s | %d\n",
               d[i].id, d[i].name, d[i].group, d[i].donations);

    printf("\nEnter blood group to search: ");
    scanf(" %9[^\n]", group);
    searchGroup(d, 10, group);

    printf("Total previous donations: %d\n", totalDonations(d, 10));

    return 0;
}
