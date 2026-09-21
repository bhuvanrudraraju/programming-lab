#include<stdio.h>
int main()
{
    int x; float dis;
    printf("Enter purchase amount: ");
    scanf("%d",&x);
    if(x<=0)
        printf("Invalid Amount");
    else if(x<1000)
        printf("No Discount");
    else if(x>=1000 && x<5000)
    {
        dis = x-(5.0/100.0)*x;
        printf("5%% Dicount \nDiscounted Value is : %f",dis);
    }
    else if(x>=5000 && x<10000)
    {
        dis = x-(10.0/100.0)*x;
        printf("10%% Dicount \nDiscounted Value is : %f",dis);
    }
    else
    {   
        dis = x-(20.0/100.0)*x;
        printf("20%% Dicount \nDiscounted Value is : %f",dis);
    }
    
    return 0;
}
