#include <stdio.h>

int main()
{
    int dd, hh, mm, dp, hp, mp, totalmnts, totalmnts2, durasi, total, jam, hari, menit, disc, temp;
    char tipe, opsi;
    scanf("%d %d%*c%d", &dd, &hh, &mm);
    //*c untuk mengabaikan ":"
    // waktu parkir
    scanf("%d %d%*c%d", &dp, &hp, &mp);
    //*c untuk mengabaikan ":"
    // waktu keluar
    scanf("%*c%c\n", &tipe); // gunanya *c untuk membuang \n di buffer jika
    // tidak ada *c maka inputan selanjutnya tidak terbaca
    //%*c : membaca 1 karakter dan mengabaikannya (tidak disimpan di variabel mana pun)

    scanf(" %c", &opsi);
    totalmnts = dd * 24 * 60 + hh * 60 + mm;
    totalmnts2 = dp * 24 * 60 + hp * 60 + mp;
    if (totalmnts > totalmnts2)
    {
        printf("Tidak mungkin");
        return 0;
    }
    hari = dp - dd;
    jam = hp - hh;
    menit = mp - mm;
    durasi = totalmnts2 - totalmnts;

    if (tipe == 'M')
    {
        if (durasi <= 180)
        {
            total = 10000;
        } // tiga jam pertama
        else if (durasi < 1440)
        {                                       // lebih dari 3 jam tapi sebelum 1 hari
            total = (durasi - 180) / 60 * 2000; // mencari sisanya dari 3 jam dan yang perlu dibayar
            total += 10000;
        }

        else if (durasi >= 1440)
        {                                     // lebih dari 1 hari
            total = (durasi / 1440) * 150000; // untuk menghitung berapa hari yang harus dibayar
            temp = durasi % 1440;             // menghitung sisa berapa jam
            temp = (temp / 60) * 2000;        // menghitung sisa jam yang perlu dibayar
            total = total + temp + 10000;     //+10000 dari 3 jam pertama
        }
    }

    else if (tipe == 'S')
    {
        if (durasi < 1440)
        { // sebelum sehari
            total = 3000;
        }
        else if (durasi >= 1440)
        { // lebih dari sehari
            total = (durasi / 1440) * 50000;
        } // menghitung berapa hari ditambah 5000
    }

    if (opsi == 'a')
    {
    }
    else if (opsi == 'b')
    {
        disc = total * 20 / 100; // untuk menentukan disc
        if (disc > 10000)
        {
            total -= 10000;
        }
        else
        {
            total -= disc;
        }
    }
    else if (opsi == 'c')
    {
        disc = total * 10 / 100;
        if (disc > 20000)
        {
            total -= 20000;
        }
        else
        {
            total -= disc;
        }
    }

    printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar %d rupiah", hari, jam, menit, total);
}