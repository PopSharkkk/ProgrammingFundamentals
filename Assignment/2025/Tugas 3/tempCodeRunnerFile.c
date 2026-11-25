#include <stdio.h>

int main (){
    int n;
    while (n!=0)
    {
        int total = 0;
        total += n % 10;
        n /= 10;
    }
    
    
    return 0;
}