#include <stdio.h>

int insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i-1;

      while (j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j = j-1;
      }
      arr[j+1] = key;
   }
}

int main ()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[n]);
    }

    for (int i = 0; i < num[n]; i++)
    {
        printf("%d", insertionSort(num, n));
    }


    return 0;
}
