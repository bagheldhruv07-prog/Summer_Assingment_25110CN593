#include <stdio.h>

int main()
{
    int a[100], n, i, j, count, maxCount = 0, maxElement;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            maxElement = a[i];
        }
    }

    printf("Maximum frequency element is: %d", maxElement);
    printf("\nFrequency is: %d", maxCount);

    return 0;
}
