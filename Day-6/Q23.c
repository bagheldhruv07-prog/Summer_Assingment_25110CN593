#include<stdio.h>
int main()
{
    int number, count = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &number);

    temp = number;

    while(temp > 0)
    {
        if(temp % 2 == 1)
            count++;

        temp = temp / 2;
    }

    printf("Set bits = %d", count);

    return 0;
}
