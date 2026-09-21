#include<stdio.h>
int main()
{
    int x;

    printf("Enter status code: ");
    scanf("%d",&x);

    if(x&1 && x&2 && x&4)
        printf("Multiple warnings");
    else if(x&1 && x&2)
        printf("Multiple warnings");
    else if(x&1 && x&4)
        printf("Multiple warnings");
    else if(x&2 && x&4)
        printf("Multiple warnings");
    else if(x&1)
        printf("Temperature warning\nSingle warning");
    else if(x&2)
        printf("Pressure warning\nSingle warning");
    else if (x&4)
        printf("Humidity warning\nSingle warning");
    else
        printf("All Normal");
    return 0;
}
