#include<stdio.h>
//Q19 Write a program to Print factors of a number. TCS, Infosys, Wipro 
int main()
{
    int n,i;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Factors of %d are: ",n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}