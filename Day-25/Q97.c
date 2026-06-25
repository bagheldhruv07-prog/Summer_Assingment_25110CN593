#include <stdio.h>

int main()
{
    int arr1[100], arr2[100], merged[200];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter the number of elements in first sorted array: ");
    scanf("%d", &n1);

    printf("Enter %d elements in sorted order:\n", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in second sorted array: ");
    scanf("%d", &n2);

    printf("Enter %d elements in sorted order:\n", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged sorted array:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", merged[i]);
    }

    printf("\n");

    return 0;
}
