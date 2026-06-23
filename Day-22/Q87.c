#include <stdio.h>
#include <string.h>

int main()
{
    char str[200];
    int i, j, count, length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);

    printf("Character frequency:\n");
    for (i = 0; i < length; i++)
    {
        if (str[i] == '\n')
        {
            continue;
        }

        count = 1;
        for (j = i + 1; j < length; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '\0';
            }
        }

        if (str[i] != '\0')
        {
            printf("%c = %d\n", str[i], count);
        }
    }

    return 0;
}
