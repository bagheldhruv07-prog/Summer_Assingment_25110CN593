#include <stdio.h>

int main()
{
    int a[100], b[100], intersection[100];
    int n1, n2, i, j, k = 0, found, alreadyAdded;

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
        for (j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                found = 1;
                break;
            }
        }

        alreadyAdded = 0;
        for (j = 0; j < k; j++)
        {
            if (a[i] == intersection[j])
            {
                alreadyAdded = 1;
                break;
            }
        }

        if (found == 1 && alreadyAdded == 0)
        {
            intersection[k] = a[i];
            k++;
        }
    }

    printf("Intersection of arrays: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", intersection[i]);
    }

    return 0;
}
