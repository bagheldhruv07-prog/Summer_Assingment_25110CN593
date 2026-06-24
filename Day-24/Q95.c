#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50], longest[50];
    int i = 0, j = 0, maxLength = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            word[j] = str[i];
            j++;
        }
        else
        {
            if (j > 0)
            {
                word[j] = '\0';

                if (j > maxLength)
                {
                    maxLength = j;
                    strcpy(longest, word);
                }

                j = 0;
            }
        }

        i++;
    }

    if (j > 0)
    {
        word[j] = '\0';

        if (j > maxLength)
        {
            maxLength = j;
            strcpy(longest, word);
        }
    }

    if (maxLength > 0)
    {
        printf("Longest word: %s\n", longest);
        printf("Length: %d\n", maxLength);
    }
    else
    {
        printf("No word found.\n");
    }

    return 0;
}
