#include <stdio.h>

int main()
{
    int i, n;
    int bookId[100];
    char bookName[100][50];
    char author[100][50];

    printf("Enter number of books: ");
    scanf("%d", &n);

    // Input book details
    for(i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &bookId[i]);

        printf("Enter Book Name: ");
        scanf("%s", bookName[i]);

        printf("Enter Author Name: ");
        scanf("%s", author[i]);
    }

    // Display book details
    printf("\n===== Library Records =====\n");
    printf("\nBook ID\tBook Name\tAuthor\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%s\n", bookId[i], bookName[i], author[i]);
    }

    return 0;
}
