#include <stdio.h>

// Fungsi membaca input menggunakan pointer.
int baca_input(const char *teks, double *nilai)
{
    char cek;
    printf("%s", teks);
    // Jika scanf gagal membaca angka (karena user input '?'), scanf mengembalikan 0
    if (scanf("%lf", nilai) != 1)
    {
        scanf(" %c", &cek); // Membaca dan membuang karakter '?'
        *nilai = -1.0;      // Tandai sebagai nilai yang dicari dengan -1
        return 0;
    }
    return 1;
}

// Fungsi-fungsi perhitungan
double cari_h(double k, double a, double t2, double t1, double x) { return (k * a * (t2 - t1)) / x; }
double cari_k(double h, double a, double t2, double t1, double x) { return (h * x) / (a * (t2 - t1)); }
double cari_a(double h, double k, double t2, double t1, double x) { return (h * x) / (k * (t2 - t1)); }
double cari_t2(double h, double k, double a, double t1, double x) { return (h * x) / (k * a) + t1; }
double cari_t1(double h, double k, double a, double t2, double x) { return t2 - (h * x) / (k * a); }
double cari_x(double h, double k, double a, double t2, double t1) { return (k * a * (t2 - t1)) / h; }

int main()
{
    // Inisialisasi awal agar jika tidak terganti tetap memiliki nilai default
    double h = -1, k = -1, a = -1, t2 = -1, t1 = -1, x = -1;

    printf("Masukkan data. Ketik '?' untuk variabel yang ingin dicari.\n");

    baca_input("Laju transfer panas (W) >> ", &h);
    baca_input("Koefisien konduktivitas (W/m-K) >> ", &k);
    baca_input("Luas penampang (m^2) >> ", &a);
    baca_input("Suhu sisi satu (K) >> ", &t2);
    baca_input("Suhu sisi lain (K) >> ", &t1);
    baca_input("Ketebalan (m) >> ", &x);

    printf("\n       kA (T2 - T1)\n");
    printf("H = -----------------\n");
    printf("            X\n\n");

    // Hitung dan simpan kembali ke variabel aslinya
    if (h < 0)
    {
        h = cari_h(k, a, t2, t1, x);
        printf("Laju transfer panas adalah %.1f W.\n", h);
    }
    else if (k < 0)
    {
        k = cari_k(h, a, t2, t1, x);
        printf("Koefisien konduktivitas termal adalah %.3f W/m-K.\n", k);
    }
    else if (a < 0)
    {
        a = cari_a(h, k, t2, t1, x);
        printf("Luas penampang adalah %.3f m^2.\n", a);
    }
    else if (t2 < 0)
    {
        t2 = cari_t2(h, k, a, t1, x);
        printf("Suhu pada sisi satu adalah %.0f K.\n", t2);
    }
    else if (t1 < 0)
    {
        t1 = cari_t1(h, k, a, t2, x);
        printf("Suhu pada sisi lain adalah %.0f K.\n", t1);
    }
    else if (x < 0)
    {
        x = cari_x(h, k, a, t2, t1);
        printf("Ketebalan konduktor adalah %.4f m.\n", x);
    }

    // Print ringkasan format modul secara absolut
    printf("H = %.1f W\t\tT2 = %.0f K\n", h, t2);
    printf("k = %.3f W/m-K\t\tT1 = %.0f K\n", k, t1);
    printf("A = %.3f m^2\t\tX = %.4f m\n", a, x);

    return 0;
}