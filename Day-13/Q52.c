#include<stdio.h>
int main()
{
   int a[100], n, i, j,even=0, odd=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    printf("The number of even elements is: %d", even);
    printf("The number of odd elements is: %d", odd);
    return 0;
}