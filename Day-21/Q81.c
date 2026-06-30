#include <stdio.h>

int main()
{
    char str[100];
    int i = 0, length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (str[i] != '\n')   // Ignore newline added by fgets
        {
            length++;
        }
        i++;
    }

    printf("Length of the string = %d", length);

    return 0;
}