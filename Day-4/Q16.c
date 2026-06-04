#include <stdio.h>
#include <math.h>

int main() {
    int start, end, num, temp, remainder, n = 0;
    int result;

    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    for(num = start; num <= end; num++) {
        temp = num;
        n = 0;

        // Count number of digits
        while(temp != 0) {
            temp /= 10;
            n++;
        }

        temp = num;
        result = 0;

        // Calculate sum of digits raised to power n
        while(temp != 0) {
            remainder = temp % 10;
            result += pow(remainder, n);
            temp /= 10;
        }

        // Check Armstrong condition
        if(result == num) {
            printf("%d ", num);
        }
    }

    return 0;
}