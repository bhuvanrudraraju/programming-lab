#include<stdio.h>
int main()
{
    int x;
    printf("Enter platform number: ");
    scanf("%d",&x);
    if(x>=1 && x<=4)
        printf("Main Building");
    else if(x>=5 && x<=8)
        printf("North Wing");
    else if(x>=9 && x<=12)
        printf("South Wing");
    else
        printf("Invalid Platform");
    return 0;
}
