#include <stdio.h>

int main() {
    int n, reversed = 0, remainder,temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if(temp == reversed) {
        printf("The number is a palindrome.");
    } else {
        printf("The number is not a palindrome.");
    }
    return 0;
}