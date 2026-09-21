#include<stdio.h>
int main()
{
    int x;
    printf("Enter classroom control value: ");
    scanf("%d",&x);
    if(x&1 && x&4)
        printf("Both projector and AC are ON");
    else if(x&4)
        printf("AC is ON");
    else if(x&1)
        printf("Projector is ON");
    else
        printf("None are ON");
    return 0;
}
