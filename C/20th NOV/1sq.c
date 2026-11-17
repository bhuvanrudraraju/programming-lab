/*Student Academic Performance System: A department maintains academic 
records of 10 students. Each student has Register Number, Name, Department 
and marks in five subjects. Develop a C program using an array of structures to read and 
display student details, calculate the total and average marks using user-defined 
functions, and identify the student who obtained the highest total marks. Use a 
recursive function to calculate the total marks obtained by all students.
*/

#include <stdio.h>
#define N 10

typedef struct {
    char reg[20], name[50], department[50];
    int marks[5];
} Student;

int total(Student s) {
    int result = 0;
    for (int j = 0; j < 5; j++)
        result += s.marks[j];
    return result;
}

float average(Student s) {
    return total(s) / 5.0f;
}

int highest(Student a[], int n) {
    int best = 0;
    for (int i = 1; i < n; i++)
        if (total(a[i]) > total(a[best]))
            best = i;
    return best;
}

int allMarks(Student a[], int n) {
    if (n == 0) return 0;
    return total(a[n - 1]) + allMarks(a, n - 1);
}

int main(void) {
    Student a[N];

    for (int i = 0; i < N; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Register number: ");
        scanf(" %19[^\n]", a[i].reg);
        printf("Name: ");
        scanf(" %49[^\n]", a[i].name);
        printf("Department: ");
        scanf(" %49[^\n]", a[i].department);
        printf("Marks in five subjects: ");
        for (int j = 0; j < 5; j++)
            scanf("%d", &a[i].marks[j]);
    }

    printf("\nRegister | Name | Department | Marks | Total | Average\n");
    for (int i = 0; i < N; i++) {
        printf("%s | %s | %s | ",
               a[i].reg, a[i].name, a[i].department);
        for (int j = 0; j < 5; j++)
            printf("%d ", a[i].marks[j]);
        printf("| %d | %.2f\n", total(a[i]), average(a[i]));
    }

    int best = highest(a, N);
    printf("\nHighest total: %s (%s), %d\n",
           a[best].name, a[best].reg, total(a[best]));
    printf("Total marks of all students: %d\n", allMarks(a, N));

    return 0;
}
