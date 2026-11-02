#include <stdio.h>
#include <string.h>

int main()
{
    char string[201];
    char output[201];
    char current_char;

    int j = 0;

    if (fgets(string, sizeof(string), stdin) == NULL)
    {
        return 1;
    }

    int length = strlen(string);
    if (length > 0 && string[length - 1] == '\n')
    {
        string[length - 1] = '\0';
        length--;
    }

    for (int i = 0; i < length; i++)
    {
        current_char = string[i];

        if (current_char == 'a' || current_char == 'i' || current_char == 'u' || current_char == 'e' || current_char == 'o' ||
            current_char == 'A' || current_char == 'I' || current_char == 'U' || current_char == 'E' || current_char == 'O')
        {
        }
        else
        {
            output[j] = current_char;
            j++;
        }
    }

    output[j] = '\0';

    printf("%s\n", output);

    return 0;
}