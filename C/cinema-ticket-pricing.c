#include<stdio.h>
int main()
{
    int x;
    printf("Enter your age.  ");
    scanf("%d",&x);
    if(x<0)
        printf("Invalid age");
    else if( x>=0 && x<=5)
        printf("Free Ticket");
    else if(x>=6 && x<=12)
        printf("Child Ticket");
    else if(x>=13 && x<=59)
        printf("Regular Ticket");
    else if (x>=60)
        printf("Senior citizen ticket");
    return 0;
}
