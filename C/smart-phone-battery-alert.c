#include<stdio.h>
int main()
{
    int x;
    printf("Enter Battery Percentage ");
    scanf("%d",&x);
    if(x<0 || x>100)
        printf("Invalid Battery Percentage");
    else if( x>=0 && x<=10)
        printf("Critical");
    else if(x>=11 && x<=30)
        printf("Low");
    else if(x>=31 && x<=80)
        printf("Normal");
    else if(x>=81 && x<=100)
        printf("Fully Charged");
    return 0;
}
