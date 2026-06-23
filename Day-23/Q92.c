#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], maxChar;
    int freq[256] = {0};
    int i, max = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (str[0] == '\0')
    {
        printf("String is empty.\n");
        return 0;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    maxChar = str[0];

    for (i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] > max)
        {
            max = freq[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    printf("Maximum occurring character is: %c\n", maxChar);
    printf("It occurs %d times.\n", max);

    return 0;
}
