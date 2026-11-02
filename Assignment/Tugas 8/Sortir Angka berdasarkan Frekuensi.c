#include <stdio.h>

typedef struct
{
    int nilai;
    int frekuensi;
} Elemen;

void swap(Elemen *a, Elemen *b)
{
    Elemen temp = *a;
    *a = *b;
    *b = temp;
}

int sort(Elemen elemen[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (elemen[j].frekuensi < elemen[j + 1].frekuensi)
                swap(&elemen[j], &elemen[j + 1]);
            else if (elemen[j].frekuensi == elemen[j + 1].frekuensi)
            {
                if (elemen[j].nilai > elemen[j + 1].nilai)
                    swap(&elemen[j], &elemen[j + 1]);
            }
        }
    }
}

int sortint(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 5];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortint(arr, n);
    Elemen elemen[n + 5];
    int uniqe = 0;
    int current = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == current)
            count++;
        else
        {
            elemen[uniqe].nilai = current;
            elemen[uniqe].frekuensi = count;
            uniqe++;
            current = arr[i];
            count = 1;
        }
    }
    elemen[uniqe].nilai = current;
    elemen[uniqe].frekuensi = count;
    uniqe++;
    sort(elemen, uniqe);
    for (int i = 0; i < uniqe; i++)
    {
        for (int j = 0; j < elemen[i].frekuensi; j++)
        {
            printf("%d", elemen[i].nilai);
            if (!(i == uniqe - 1 && j == elemen[i].frekuensi - 1))
            {
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}