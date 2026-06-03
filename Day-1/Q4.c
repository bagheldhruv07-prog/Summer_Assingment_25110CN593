#include<stdio.h>
int main()
{
    int n,count=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    
    while(n>0)
    {
        count++;
        
        n=n/10;
    }
    printf("no. of digits in %d is %d",n,count);
    return 0;
}