#include<stdio.h>
int main()
{
    int x;
    printf("Enter a parking slot number: ");
    scanf("%d",&x);
    if((x>1 && x<64) && ((x&1 )== 0) && (x&4))
        printf("Valid Slot");
        
    else
        printf("Invalid Slot");
    return 0;
}
