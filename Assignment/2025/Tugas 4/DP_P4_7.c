#include <stdio.h>

int main() {
    int M, N, P;
    
    if (scanf("%d %d %d", &M, &N, &P) != 3) {
        return 1;
    }
    
    int A[20][20];
    int B[20][20];
    int C[20][20] = {0};
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                return 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                return 1;
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d", C[i][j]);
            if (j < P - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}