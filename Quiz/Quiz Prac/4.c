#include <stdio.h>
#include <string.h>

void reverse (char s[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse (s, left = 1, right - 1);
}

int main ()
{
    char s[201];
    fgets(s, sizeof(s), stdin);

    int length = strlen(s);

    if (length > 0 && s[length-1] == '\n') {
        s[length-1] = '\0';
        length--;
    }
    reverse(s, 0, length - 1);
    printf("%s\n", s);

    return 0;
}