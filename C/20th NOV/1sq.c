/*Student Academic Performance System: A department maintains academic 
records of 10 students. Each student has Register Number, Name, Department 
and marks in five subjects. Develop a C program using an array of structures to read and 
display student details, calculate the total and average marks using user-defined 
functions, and identify the student who obtained the highest total marks. Use a 
recursive function to calculate the total marks obtained by all students.
*/

#include <stdio.h>

struct Student {
    char reg[20], name[50], department[50];
    int marks[5];
};

int total(struct Student s) {
    int sum = 0;
    for (int j = 0; j < 5; j++)
        sum = sum + s.marks[j];
    return sum;
}

float average(struct Student s) {
    return total(s) / 5.0;
}

int highest(struct Student s[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (total(s[i]) > total(s[max]))
            max = i;
    }
    return max;
}

int allMarks(struct Student s[], int n) {
    if (n == 0)
        return 0;
    return total(s[n - 1]) + allMarks(s, n - 1);
}

int main() {
    struct Student s[10];
    int i, j, max;

    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Register number: ");
        scanf(" %19[^\n]", s[i].reg);
        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);
        printf("Department: ");
        scanf(" %49[^\n]", s[i].department);
        printf("Enter marks in five subjects: ");
        for (j = 0; j < 5; j++)
            scanf("%d", &s[i].marks[j]);
    }

    for (i = 0; i < 10; i++) {
        printf("\nRegister: %s\nName: %s\nDepartment: %s\n",
               s[i].reg, s[i].name, s[i].department);
        printf("Marks: ");
        for (j = 0; j < 5; j++)
            printf("%d ", s[i].marks[j]);
        printf("\nTotal: %d\nAverage: %.2f\n",
               total(s[i]), average(s[i]));
    }

    max = highest(s, 10);
    printf("\nHighest total: %s (%s), %d\n",
           s[max].name, s[max].reg, total(s[max]));
    printf("Total marks of all students: %d\n", allMarks(s, 10));

    return 0;
}
