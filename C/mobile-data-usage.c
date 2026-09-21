#include<stdio.h>
int main()
{
    float x;
    printf("Enter data consumed in GB: ");
    scanf("%f",&x);
    if(x<0.0)
        printf("Invalid");
    else if(x>=0.0 && x<=1.0)
        printf("Very Low");
    else if(x>1.0 && x<=5.0)
        printf("Normal");
    else if(x>5.0 && x<=10.0)
        printf("High\nConsider Wi-Fi");
    else if(x>10.0)
        printf("Excessive");

    return 0;

}
