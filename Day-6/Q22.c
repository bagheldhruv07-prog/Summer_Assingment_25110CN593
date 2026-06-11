#include<stdio.h>
int main()
{
    long long binary;
    int decimal = 0, base = 1, digit, isValid = 1;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while(binary > 0)
    {
        digit = binary % 10;

        if(digit != 0 && digit != 1)
        {
            isValid = 0;
            break;
        }

        decimal = decimal + digit * base;
        base = base * 2;
        binary = binary / 10;
    }

    if(isValid)
        printf("Decimal number = %d", decimal);
    else
        printf("Invalid binary number");

    return 0;
}
