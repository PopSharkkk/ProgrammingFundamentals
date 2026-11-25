#include <stdio.h>
#include <string.h>

int main()
{
    char string[101];
    int i;
    fgets(string, sizeof(string), stdin);
    for (i = strlen(string) - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");
    return 0;
}