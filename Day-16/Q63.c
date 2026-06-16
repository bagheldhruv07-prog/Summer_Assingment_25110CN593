#include <stdio.h>

int main()
{
    int a[100], n, i, j, sum, found = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the sum: ");
    scanf("%d", &sum);

    printf("Pairs with given sum are:\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == sum)
            {
                printf("(%d, %d)\n", a[i], a[j]);
                found = 1;
            }
        }
    }

    if (found == 0)
    {
        printf("No pair found");
    }

    return 0;
}
