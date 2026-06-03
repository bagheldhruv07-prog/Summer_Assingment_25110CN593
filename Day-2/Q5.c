#include <stdio.h>

int main() {
    int d,sum=0,n;
    printf("Enter the number: ");
    scanf("%d", &n);
    while(n>0) {
        d = n%10;
        sum = sum + d;
        n = n/10;
    }
    printf("Sum of digits is %d", sum);
    return 0;
}