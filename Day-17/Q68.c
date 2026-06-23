#include <stdio.h>

int main(
{
    int a[100],b[100],c[100],i,j,n,m;
    printf("enter the size of first matrix: ");
    scanf("%d", &n);
    printf("enter the size of second matrix: ");
    scanf("%d", &m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        printf("enter the elements of first matrix: ");
        scanf("%d", &a[i]);
    }
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("enter the elements of second matrix: ");
        scanf("%d", &b[i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        C[i][j]=a[i][j];