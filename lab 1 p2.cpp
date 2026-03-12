#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100] = "", words[20][30];
    int nrWords = 0;
    scanf("%[^\n]", text);

    char* p, aux[30] = "";
    p = strtok(text, " ");

    while (p)
    {
        strcpy(words[nrWords], p);
        nrWords++;
        p = strtok(NULL, " ");
    }

    for (int i = 0; i < nrWords - 1; i++)
        for (int j = i + 1; j < nrWords; j++)
        {
            int len1 = strlen(words[i]);
            int len2 = strlen(words[j]);

            if (len2 > len1 || (len2 == len1 && strcmp(words[i], words[j]) > 0))
            {
                strcpy(aux, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], aux);
            }
        }

    for (int i = 0; i < nrWords; i++)
        printf("%s\n", words[i]);

    return 0;
}