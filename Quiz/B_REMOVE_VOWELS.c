#include <stdio.h>

int main ()
{
    char string[205];
    scanf("%s", string);

    for (int i = 0; i < 205; i++)
    {
        if (string[205] == 'a' || string[205] == 'A')
            printf("");
        if (string[205] == 'i' || string[205] == 'I')
            printf("");
        if (string[205] == 'u' || string[205] == 'U')
            printf("");
        if (string[205] == 'e' || string[205] == 'E')
            printf("");
        if (string[205] == 'o' || string[205] == 'O')
            printf("");
        printf("%s", string);
    }
    return 0;



}
