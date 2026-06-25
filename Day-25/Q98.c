#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int present1[256] = {0}, present2[256] = {0};
    int i, found = 0;
    unsigned char ch;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    for (i = 0; str1[i] != '\0'; i++)
    {
        ch = str1[i];
        present1[ch] = 1;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        ch = str2[i];
        present2[ch] = 1;
    }

    printf("Common characters: ");
    for (i = 0; i < 256; i++)
    {
        if (present1[i] == 1 && present2[i] == 1)
        {
            printf("%c ", i);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No common characters");
    }

    printf("\n");

    return 0;
}
