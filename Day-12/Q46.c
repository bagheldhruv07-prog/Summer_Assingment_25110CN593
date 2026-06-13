#include<stdio.h>
int armstrong(int n)
{
    int original = n, sum = 0, remainder;

    while (n > 0) {
        remainder = n % 10;
        sum += remainder * remainder * remainder;
        n /= 10;
    }

    return original == sum;
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (armstrong(n)) {
        printf("%d is an Armstrong number.", n);
    } else {
        printf("%d is not an Armstrong number.", n);
    }
    return 0;
}