#include<stdio.h>
int main()
{
    int x;
    printf("Enter withdrawal amount: ");
    scanf("%d",&x);
    if(x<=0)
        printf("Invalid Amount");
    else if(x%100!=0)
        printf("Amount must be in multiples of 100");
    else if(x>20000)
        printf("Daily limit exceeeded");
    else
        printf("Withdrawal Permitted");
    return 0;
}
