#include<stdio.h>
int main()
{
    int a[100], n, i, j,s=0, avg;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s+=a[i];
        avg=s/n;
    }
    printf("The sum of the elements is: %d", s);
    printf("The average of the elements is: %d", avg);
    return 0;
}