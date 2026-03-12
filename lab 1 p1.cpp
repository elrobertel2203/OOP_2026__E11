#include <stdio.h>

int convertToInt(char* textNumber, int length)
{
    int p = 1;
    int rez = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        rez += p * (textNumber[i] - '0');
        p *= 10;
    }

    return rez;
}

int main()
{
    int sum = 0;
    int digitCount = 0;
    char number[10];
    char character;
    FILE* file;

    if (fopen_s(&file, "ini.txt", "r") == 0)
    {
        character = fgetc(file);

        while (character != EOF)
        {
            if (character >= '0' && character <= '9')
            {
                number[digitCount] = character;
                digitCount++;
            }

            if (character == '\n')
            {
                sum += convertToInt(number, digitCount);
                digitCount = 0;
            }

            character = fgetc(file);
        }

        sum += convertToInt(number, digitCount);

        fclose(file);

        printf("%d\n", sum);

        return 0;
    }

    printf("Fisierul nu a fost gasit.\n");
    return 1;
}