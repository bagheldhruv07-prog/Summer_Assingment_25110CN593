#include<stdio.h>
int main()
{
    int a[100], n, i, j,max =0,min =0 ;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    for(i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
        if(a[i] < min) {
            min = a[i];
        }
    }
    printf("The maximum element is: %d", max);
    printf("The minimum element is: %d", min);
    return 0;
}