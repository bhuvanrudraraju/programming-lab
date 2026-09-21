#include<stdio.h>
int main()
{
    int x;
    printf("Enter Attendance Percentage ");
    scanf("%d",&x);
    if(x<0 || x>100)
        printf("Invalid Attendance Percentage");
    else if( x>=75)
        printf("Eligible for examination");
    else if(x>=65)
        printf("Conditionally Eligible");
    else 
        printf("Not Eligible");
    return 0;
}
