#include <stdio.h>
#include <string.h>

int main (){ 
    char string[101];
    int i;
    fgets(string, sizeof(string), stdin);
    for(i = 0; string[i] != '\0' && string[i] != '\n'; i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + ('a' - 'A');
        }
    }
    printf("%s", string);
}