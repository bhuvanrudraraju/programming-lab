#include<stdio.h>
int main()
{
    int x;
    printf("Enter a integer: ");
    scanf("%d",&x);
    if(x==0)
        printf("Zero");
    else if(x>0 && x&1)
        printf("Positive odd");
    else if(x>0 && !(x&1))
        printf("Positive even");
    else if(x<0 && (x&1))
        printf("Negative odd ");
    else
        printf("Negative even");
    return 0;
}
