#include <stdio.h>
#include <string.h>

int main()
{
    char str[200];
    int freq[256] = {0};
    int i, found = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] > 1)
        {
            printf("First repeating character is: %c\n", str[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No repeating character found.\n");
    }

    return 0;
}
