#include <stdio.h>

int main()
{
    int i, n;
    int productId[100], quantity[100];
    float price[100];
    char productName[100][50];

    printf("Enter number of products: ");
    scanf("%d", &n);

    // Input product details
    for(i = 0; i < n; i++)
    {
        printf("\nProduct %d\n", i + 1);

        printf("Enter Product ID: ");
        scanf("%d", &productId[i]);

        printf("Enter Product Name: ");
        scanf("%s", productName[i]);

        printf("Enter Quantity: ");
        scanf("%d", &quantity[i]);

        printf("Enter Price: ");
        scanf("%f", &price[i]);
    }

    // Display inventory
    printf("\n===== Inventory Records =====\n");
    printf("ID\tProduct\t\tQuantity\tPrice\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
               productId[i], productName[i], quantity[i], price[i]);
    }

    return 0;
}