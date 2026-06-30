#include <stdio.h>

int main()
{
    char str[100], rev[100];
    int i = 0, j, length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Find length
    while (str[length] != '\0')
    {
        if (str[length] == '\n')
        {
            break;
        }
        length++;
    }

    // Reverse the string
    j = 0;
    for (i = length - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }

    rev[j] = '\0';

    printf("Reversed string: %s", rev);

    return 0;
}
