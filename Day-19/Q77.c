#include <stdio.h>

int main()
{
    int a[10][10], n, i, j, sum = 0;

    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i][i];
        sum = sum + a[i][n - i - 1];
    }

    if (n % 2 != 0)
    {
        sum = sum - a[n / 2][n / 2];
    }

    printf("The diagonal sum of the matrix is: %d\n", sum);

    return 0;
}
