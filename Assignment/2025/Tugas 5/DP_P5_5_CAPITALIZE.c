#include <stdio.h>
#include <ctype.h>

int main() {
    char s[201];
    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i] && s[i] != '\n'; i++) {
        if (i == 0 || s[i-1] == ' ')
            putchar(toupper(s[i]));
        else
            putchar(s[i]);
    }
    return 0;
}
