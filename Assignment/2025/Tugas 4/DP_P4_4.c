#include <stdio.h>

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    int arr[100];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }
    
    int T;
    if (scanf("%d", &T) != 1) {
        return 1;
    }
    
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == T) {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}