#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], result[100];
    int visited[256] = {0};
    int i, j = 0;
    unsigned char ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if (visited[ch] == 0)
        {
            result[j] = str[i];
            j++;
            visited[ch] = 1;
        }
    }

    result[j] = '\0';

    printf("String after removing duplicate characters: %s\n", result);

    return 0;
}
