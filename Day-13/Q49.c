#include<stdio.h>
int main()
{
    int a[100], n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d\n ", a[i]);
    }
    return 0;
}