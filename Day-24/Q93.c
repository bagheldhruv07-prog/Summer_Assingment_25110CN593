#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[200];
    int len1, len2;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 != len2)
    {
        printf("The strings are not rotations of each other.\n");
    }
    else
    {
        strcpy(temp, str2);
        strcat(temp, str2);

        if (strstr(temp, str1) != NULL)
        {
            printf("The strings are rotations of each other.\n");
        }
        else
        {
            printf("The strings are not rotations of each other.\n");
        }
    }

    return 0;
}
