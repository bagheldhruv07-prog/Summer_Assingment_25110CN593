#include <stdio.h>

int main()
{
    int a[100], b[100], unionArray[200];
    int n1, n2, i, j, k = 0, found;

    printf("Enter the size of first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements: ", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements: ", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n1; i++)
    {
        found = 0;
        for (j = 0; j < k; j++)
        {
            if (a[i] == unionArray[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            unionArray[k] = a[i];
            k++;
        }
    }

    for (i = 0; i < n2; i++)
    {
        found = 0;
        for (j = 0; j < k; j++)
        {
            if (b[i] == unionArray[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            unionArray[k] = b[i];
            k++;
        }
    }

    printf("Union of arrays: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", unionArray[i]);
    }

    return 0;
}
