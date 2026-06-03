#include <stdio.h>

int main() {
    int n, product = 1, remainder;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        product = product * remainder;
        n /= 10;
    }
    printf("Product of digits = %d", product);
    return 0;
}