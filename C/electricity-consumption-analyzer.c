#include<stdio.h>
int main()
{
    int x;
    printf("Enter Monthly Electricity Consumption in units.  ");
    scanf("%d",&x);
    if(x<0)
        printf("Invalid ");
    else if( x>=0 && x<=100)
        printf("Low Consumption");
    else if(x>=101 && x<=300)
        printf("Moderate");
    else if(x>=301 && x<=500)
        printf("High");
    else if (x>500)
    {
        printf("Very High\n");
        printf("Reduce Consumption");
    }
    return 0;
}
