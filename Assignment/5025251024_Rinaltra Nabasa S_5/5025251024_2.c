#include <stdio.h>
#include <math.h>

// Deklarasi fungsi dengan pointer untuk parameter output
int get_problem();
void get_rate_drop_factor(double *rate, int *drop_factor);
void get_kg_rate_conc(double *rate, double *weight, double *conc);
void get_units_conc(double *rate, double *conc);
int fig_drops_min(double rate, int drop_factor);
int fig_ml_hr(double hours);
int by_weight(double rate, double weight, double conc);
int by_units(double rate, double conc);

int main()
{
    int pilihan;
    // Variabel yang akan dimanipulasi nilainya oleh pointer
    double rate, hours, weight, conc;
    int drop_factor;

    pilihan = get_problem();

    while (pilihan != 5)
    {
        switch (pilihan)
        {
        case 1:
            // Mengirimkan alamat memori (&) ke fungsi
            get_rate_drop_factor(&rate, &drop_factor);
            printf("Laju tetesan per menit: %d\n\n", fig_drops_min(rate, drop_factor));
            break;
        case 2:
            printf("Masukkan jumlah jam: ");
            scanf("%lf", &hours);
            printf("Laju dalam ml/jam: %d\n\n", fig_ml_hr(hours));
            break;
        case 3:
            get_kg_rate_conc(&rate, &weight, &conc);
            printf("Laju dalam ml/jam: %d\n\n", by_weight(rate, weight, conc));
            break;
        case 4:
            get_units_conc(&rate, &conc);
            printf("Laju dalam ml/jam: %d\n\n", by_units(rate, conc));
            break;
        default:
            printf("Pilihan tidak valid.\n\n");
        }
        pilihan = get_problem();
    }
    return 0;
}

int get_problem()
{
    int pil;
    printf("ASISTEN LAJU INFUS\n");
    printf("(1) ml/jam & faktor tetesan\n(2) 1 L untuk n jam\n(3) mg/kg/jam & konsentrasi\n(4) unit/jam & konsentrasi\n(5) KELUAR\nPilihan=> ");
    scanf("%d", &pil);
    return pil;
}

// Implementasi fungsi yang memanfaatkan pointer untuk mengubah nilai asli
void get_rate_drop_factor(double *rate, int *drop_factor)
{
    printf("Masukkan laju (ml/jam)=> ");
    scanf("%lf", rate);
    printf("Masukkan faktor tetesan (tetesan/ml)=> ");
    scanf("%d", drop_factor);
}

void get_kg_rate_conc(double *rate, double *weight, double *conc)
{
    printf("Masukkan laju (mg/kg/jam)=> ");
    scanf("%lf", rate);
    printf("Masukkan berat pasien (kg)=> ");
    scanf("%lf", weight);
    printf("Masukkan konsentrasi (mg/ml)=> ");
    scanf("%lf", conc);
}

void get_units_conc(double *rate, double *conc)
{
    printf("Masukkan laju (unit/jam)=> ");
    scanf("%lf", rate);
    printf("Masukkan konsentrasi (unit/ml)=> ");
    scanf("%lf", conc);
}

int fig_drops_min(double rate, int drop_factor)
{
    return (int)round((rate * drop_factor) / 60.0);
}
int fig_ml_hr(double hours) { return (int)round(1000.0 / hours); }
int by_weight(double rate, double weight, double conc) { return (int)round((rate * weight) / conc); }
int by_units(double rate, double conc) { return (int)round(rate / conc); }