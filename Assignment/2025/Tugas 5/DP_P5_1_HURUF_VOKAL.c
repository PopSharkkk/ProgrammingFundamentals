#include <stdio.h>
#include <string.h>

int main()
{
    char string[101];
    int vokal = 0;
    int i;  
    fgets(string, sizeof(string), stdin);
    for (i = 0; i < strlen(string); i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            if (string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U')
            {
                vokal++;
            }
        }
    }
    printf("%d\n", vokal);
    return 0;
}
