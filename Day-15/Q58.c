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

    printf("Enter number of positions to rotate left: ");
    scanf("%d", &rotate);

    rotate = rotate % n;

    while (rotate > 0)
    {
        temp = a[0];

        for (i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[n - 1] = temp;
        rotate--;
    }

    printf("Array after left rotation: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
