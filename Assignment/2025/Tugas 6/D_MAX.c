#include <stdio.h>

int max_rec(const int A[], int N, int i)
{
    if (i == N - 1)
    {
        return A[i];
    }
    return (A[i] > max_rec(A, N, i + 1)) ? A[i] : max_rec(A, N, i + 1);
}

void read_array(int A[], int N, int i)
{
    if (i == N)
    {
        return;
    }
    scanf("%d", &A[i]);
    read_array(A, N, i + 1);
}

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    read_array(A, N, 0);

    printf("%d\n", max_rec(A, N, 0));

    return 0;
}
