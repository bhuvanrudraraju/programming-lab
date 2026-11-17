
/*⁠Smart Agriculture Crop Monitoring System: 
A farmer monitors five agricultural fields. 
Each field has Field ID, Crop Name, Area in 
Acres and Crop Yield in Kilograms. Develop a 
C program using structures and arrays to read 
and display field details, identify the field 
producing the maximum crop yield using a user-defined 
function, and calculate the total crop yield from all fields using recursion.
*/
#include <stdio.h>

struct Field {
    char id[20], crop[50];
    double area, yield;
};

int maximum(struct Field f[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (f[i].yield > f[max].yield)
            max = i;
    }
    return max;
}

double totalYield(struct Field f[], int n) {
    if (n == 0)
        return 0;
    return f[n - 1].yield + totalYield(f, n - 1);
}

int main() {
    struct Field f[5];
    int i, max;

    for (i = 0; i < 5; i++) {
        printf("\nField %d\n", i + 1);
        printf("Field ID: ");
        scanf(" %19[^\n]", f[i].id);
        printf("Crop name: ");
        scanf(" %49[^\n]", f[i].crop);
        printf("Area in acres: ");
        scanf("%lf", &f[i].area);
        printf("Crop yield in kilograms: ");
        scanf("%lf", &f[i].yield);
    }

    printf("\nField ID | Crop | Area (acres) | Yield (kg)\n");
    for (i = 0; i < 5; i++)
        printf("%s | %s | %.2f | %.2f\n",
               f[i].id, f[i].crop, f[i].area, f[i].yield);

    max = maximum(f, 5);
    printf("\nMaximum yield: Field %s, %s, %.2f kg\n",
           f[max].id, f[max].crop, f[max].yield);
    printf("Total crop yield: %.2f kg\n", totalYield(f, 5));

    return 0;
}
