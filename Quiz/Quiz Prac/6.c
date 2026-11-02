#include <stdio.h>
#include <string.h>

struct item
{
    char nama[51];
    int harga;
    int stok;
}

int main () {
    int n;
    scanf("%d", &n);
    struct item currentitem;
    struct item cheapitem;

    scanf("%s %d %d", currentitem.nama, &currentitem.harga, &currentitem.stok);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", currentitem.nama, &currentitem.harga, &currentitem.stok);
    
        if (currentitem.harga < cheapitem.harga)
        {
            cheapitem = currentitem.harga
            
            strcpy(cheapitem.nama, currentitem.nama);
            cheapitem.harga = currentitem.harga;
            cheapitem.stok = currentitem.stok;
            
        }
    
        printf("%s %d %d\n", currentitem.nama, currentitem.harga, currentitem.stok);
    
    }


    
}