#include <stdio.h>

int main()
{
    char sentence[200];
    int i, words = 0, inWord = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    printf("Number of words = %d\n", words);

    return 0;
}
