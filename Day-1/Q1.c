#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("enter the number of terms to added: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
    }
    printf("Sum of first %d natural numbers is %d",n,sum);
    return 0;
}
