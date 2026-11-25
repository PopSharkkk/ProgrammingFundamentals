#include <stdio.h>
#include <string.h>

int main()
{
    char n_str[10];
    scanf("%s", n_str);

    int len = strlen(n_str);
    int is_palindrome = 1;

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (n_str[i] != n_str[j])
        {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
    {
        printf("YA\n");
    }
    else
    {
        printf("TIDAK\n");
    }

    return 0;
}