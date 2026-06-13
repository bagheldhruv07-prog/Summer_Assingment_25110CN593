#include<stdio.h>
int main()
{
    int rows=5,i,j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%c",j+64);
        }
        printf("\n");
    }
    return 0;
}