#include<stdio.h>'
int palindrome(int n)
{
    int original = n, reversed = 0, remainder;

    while (n > 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return original == reversed;
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (palindrome(n)) {
        printf("%d is a palindrome number.", n);
    } else {
        printf("%d is not a palindrome number.", n);
    }
    return 0;
}
