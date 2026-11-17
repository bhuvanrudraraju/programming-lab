/*University Examination Result System: 
A university stores examination results of 10 students. 
Each student has Register Number, Name and marks in three subjects.
Develop a C program using structures and arrays to read and display student details,
calculate the average marks using user-defined functions, identify students 
who passed all three subjects, and use recursion to calculate the total marks
obtained by all students in a particular subject.


*/

#include <stdio.h>

struct Student {
    char reg[20], name[50];
    int marks[3];
};

float average(struct Student s) {
    return (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0;
}

int passed(struct Student s) {
    /* Pass mark assumed to be 50 out of 100. */
    for (int j = 0; j < 3; j++) {
        if (s.marks[j] < 50)
            return 0;
    }
    return 1;
}

int subjectTotal(struct Student s[], int n, int subject) {
    if (n == 0)
        return 0;
    return s[n - 1].marks[subject]
           + subjectTotal(s, n - 1, subject);
}

int main() {
    struct Student s[10];
    int i, j, subject;

    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Register number: ");
        scanf(" %19[^\n]", s[i].reg);
        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);
        printf("Marks in three subjects: ");
        for (j = 0; j < 3; j++)
            scanf("%d", &s[i].marks[j]);
    }

    printf("\nRegister | Name | Mark 1 | Mark 2 | Mark 3 | Average\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %d | %d | %.2f\n",
               s[i].reg, s[i].name, s[i].marks[0],
               s[i].marks[1], s[i].marks[2], average(s[i]));

    printf("\nStudents who passed all subjects:\n");
    for (i = 0; i < 10; i++) {
        if (passed(s[i]) == 1)
            printf("%s (%s)\n", s[i].name, s[i].reg);
    }

    printf("\nEnter subject number (1-3): ");
    scanf("%d", &subject);

    if (subject < 1 || subject > 3) {
        printf("Invalid subject number.\n");
        return 1;
    }

    printf("Total marks in subject %d: %d\n",
           subject, subjectTotal(s, 10, subject - 1));

    return 0;
}
