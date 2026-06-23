#include <stdio.h>
#include <string.h>

int main()
{
    char str1[200], str2[200];
    int freq[256] = {0};
    int i, isAnagram = 1;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (strlen(str1) != strlen(str2))
    {
        isAnagram = 0;
    }
    else
    {
        for (i = 0; str1[i] != '\0'; i++)
        {
            freq[(unsigned char)str1[i]]++;
            freq[(unsigned char)str2[i]]--;
        }

        for (i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
            {
                isAnagram = 0;
                break;
            }
        }
    }

    if (isAnagram)
    {
        printf("Strings are anagrams.\n");
    }
    else
    {
        printf("Strings are not anagrams.\n");
    }

    return 0;
}
