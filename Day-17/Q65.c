#include <stdio.h>

int main()
{
    int a[100], b[100], merged[200];
    int n1, n2, i;

    printf("Enter the size of first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements: ", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
        merged[i] = a[i];
    }

    printf("Enter the size of second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements: ", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
        merged[n1 + i] = b[i];
    }

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}
