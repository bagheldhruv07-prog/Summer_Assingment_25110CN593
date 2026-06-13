#include<stdio.h>
int main()
{
    int rows=5,i,j,space;
    for(i = rows; i >= 1; i--)
    {
        for(space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }
        for(j = 1; j <=(2 * i - 1); j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}