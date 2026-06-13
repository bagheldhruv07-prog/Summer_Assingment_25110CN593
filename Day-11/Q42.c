#include <stdio.h>

int maximum(int a, int b)
{
    if (a > b) {
        return a;
    }

    return b;
}

int main(void)
{
    int num1, num2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    max = maximum(num1, num2);

    printf("Maximum number is: %d\n", max);

    return 0;
}
