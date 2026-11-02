#include <stdio.h>
#include <string.h>

int main()
{
    char word[205];
    scanf("%s", &word[205]);

    for(int i = 0; i < 205; i++)
    {
        if ((word == 'a' || word == 'A') || (word == 'i' || word == 'I')
        || (word == 'u' || word == 'U') || (word == 'e' || word == 'E')
        || (word == 'o' || word == 'O') )
        {
            printf("*");
        }
    }
    return 0;

}
