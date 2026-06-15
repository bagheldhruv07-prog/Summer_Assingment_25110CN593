#include <stdio.h>

int main()
{
    int a[100], n, i, rotate, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of positions to rotate right: ");
    scanf("%d", &rotate);

    rotate = rotate % n;

    while (rotate > 0)
    {
        temp = a[n - 1];

        for (i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }

        a[0] = temp;
        rotate--;
    }

    printf("Array after right rotation: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
