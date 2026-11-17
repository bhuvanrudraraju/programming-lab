/*College Attendance Monitoring System: A college maintains
attendance details of 10 students. Each student has Register Number, 
Name, Total Classes Conducted and Classes Attended. Develop a C program 
using structures and arrays to read and display student details, 
calculate the attendance percentage using user-defined functions, and 
identify students whose attendance is below 75%. Use a recursive function
to count the total number of students having attendance below 75%.
*/


#include <stdio.h>

struct Student {
    char reg[20], name[50];
    int conducted, attended;
};

float percentage(struct Student s) {
    if (s.conducted == 0)
        return 0;
    return s.attended * 100.0 / s.conducted;
}

int countBelow75(struct Student s[], int n) {
    if (n == 0)
        return 0;

    if (percentage(s[n - 1]) < 75)
        return 1 + countBelow75(s, n - 1);

    return countBelow75(s, n - 1);
}

int main() {
    struct Student s[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Register number: ");
        scanf(" %19[^\n]", s[i].reg);
        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);
        printf("Total classes conducted: ");
        scanf("%d", &s[i].conducted);
        printf("Classes attended: ");
        scanf("%d", &s[i].attended);
    }

    printf("\nRegister | Name | Conducted | Attended | Attendance\n");
    for (i = 0; i < 10; i++)
        printf("%s | %s | %d | %d | %.2f%%\n",
               s[i].reg, s[i].name, s[i].conducted,
               s[i].attended, percentage(s[i]));

    printf("\nStudents below 75%%:\n");
    for (i = 0; i < 10; i++) {
        if (percentage(s[i]) < 75)
            printf("%s (%s): %.2f%%\n",
                   s[i].name, s[i].reg, percentage(s[i]));
    }

    printf("Number of students below 75%%: %d\n",
           countBelow75(s, 10));

    return 0;
}
