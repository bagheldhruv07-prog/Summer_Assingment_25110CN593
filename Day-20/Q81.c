#include <stdio.h>

int main()
{
    int a[10][10], rows, cols, i, j, sum;

    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Column-wise sum:\n");
    for (j = 0; j < cols; j++)
    {
        sum = 0;
        for (i = 0; i < rows; i++)
        {
            sum = sum + a[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum);
    }

    return 0;
}
