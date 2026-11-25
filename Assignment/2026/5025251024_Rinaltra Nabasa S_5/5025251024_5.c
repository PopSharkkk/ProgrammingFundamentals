#include <stdio.h>

// Fungsi tunggal yang mengembalikan 3 nilai sekaligus menggunakan pointer
void proses_bilangan(int *angka, int *hasil_balik, int *is_prima, int *is_palindrom)
{
    int n = *angka;
    int balik = 0;

    // Proses pembalikan angka
    int temp = n;
    while (temp > 0)
    {
        balik = balik * 10 + (temp % 10);
        temp /= 10;
    }
    *hasil_balik = balik;

    // Pengecekan Palindrom
    *is_palindrom = (*angka == *hasil_balik) ? 1 : 0;

    // Pengecekan Prima
    *is_prima = 1;
    if (*angka <= 1)
        *is_prima = 0;
    for (int i = 2; i * i <= *angka; i++)
    {
        if (*angka % i == 0)
        {
            *is_prima = 0;
            break;
        }
    }
}

int main()
{
    int jumlah_data;

    printf("Masukkan jumlah bilangan yang ingin dicek: ");
    scanf("%d", &jumlah_data);

    if (jumlah_data <= 0)
    {
        printf("Jumlah data tidak valid.\n");
        return 1;
    }

    int data[jumlah_data];
    int *ptr_data = data; // Pointer menunjuk ke elemen pertama array

    printf("\nMasukkan %d bilangan bulat positif:\n", jumlah_data);
    for (int i = 0; i < jumlah_data; i++)
    {
        printf("Bilangan ke-%d: ", i + 1);
        // Menggunakan pointer arithmetic untuk mengisi nilai ke dalam array
        scanf("%d", (ptr_data + i));
    }

    printf("\nAngka\tDibalik\tPrima?\tPalindrom?\n");
    printf("----------------------------------\n");

    // Iterasi menggunakan pointer arithmetic untuk memproses output
    for (int i = 0; i < jumlah_data; i++)
    {
        int dibalik, prima, palindrom;

        // Memanggil fungsi dengan mengirim alamat variabel untuk diisi hasilnya
        proses_bilangan((ptr_data + i), &dibalik, &prima, &palindrom);

        printf("%d\t%d\t%s\t%s\n",
               *(ptr_data + i),
               dibalik,
               prima ? "Ya" : "Tidak",
               palindrom ? "Ya" : "Tidak");
    }

    return 0;
}