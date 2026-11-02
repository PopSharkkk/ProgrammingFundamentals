# Programming Fundamentals (Dasar Pemrograman)

Repository ini berisi kumpulan tugas mata kuliah **Dasar Pemrograman** menggunakan bahasa **C**.

## 👤 Informasi Mahasiswa
- **Nama** : Rinaltra Nabasa Simanungkalit
- **NRP**  : 5025251024
- **Dosen Pengampu** : YP

---

## 📂 Struktur Direktori Tugas

Setiap folder tugas mingguan terorganisir dengan format:
`5025251024_Rinaltra Nabasa S_<Pekan>/`

Di dalam masing-masing folder terdapat:
- **`*.c`** : Source code implementasi program bahasa C
- **`*.exe`** : Binary executable hasil kompilasi
- **`*.png`** : Tangkapan layar (*screenshot*) terminal hasil eksekusi program
- **`*.txt`** : File input data atau output yang diproses (jika dipersyaratkan soal)

| Folder | Topik & Deskripsi Masalah | File C Utama |
| :--- | :--- | :--- |
| **`S_1`** | Pengenalan Sintaks C, Input/Output, & Operasi Dasar | `5025251024_2.c`, `5025251024_3.c`, `5025251024_7.c` |
| **`S_2`** | Ekspresi Matematika & Aproksimasi (Gosper's Formula) | `5025251024_4.c`, `5025251024_7.c`, `5025251024_12.c` |
| **`S_3`** | Struktur Kontrol Percabangan (*Selection/Conditionals*) | `5025251024_1.c`, `5025251024_6.c`, `5025251024_9.c` |
| **`S_4`** | Perulangan (*Loops*) & Tabel Perhitungan Finansial / Fisika | `5025251024_3.c` (Loan Schedule), `5025251024_5.c`, `5025251024_7_vehicle_speeds.c` |
| **`S_5`** | Fungsi Modular (*Modular Functions*) & Menu Berulang | `5025251024_2.c` (Asisten Laju Infus), `5025251024_5.c`, `5025251024_6.c` |
| **`S_6`** | Array 1D/2D, Pemrosesan File, & Analisis Data | `5025251024_2.c` (Polygon Area), `5025251024_5.c` (Barcode Validator), `5025251024_10.c` (Election Tally) |
| **`S_7`** | Array String, Algoritma Pencarian & Pengurutan (*Sorting & Search*) | `5025251024_2.c` (Resistor Color Code), `5025251024_6.c` (Parallel Array Sort), `5025251024_10.c` (ACLS Drug Assistant) |

---

## 🛠️ Kompilasi dan Menjalankan Program

Program dapat dikompilasi menggunakan **GCC (MinGW)** di sistem operasi Windows / Linux / macOS.

### 1. Kompilasi
Buka terminal / PowerShell di direktori tugas terkait, lalu jalankan perintah:
```bash
gcc 5025251024_<nomor_soal>.c -o 5025251024_<nomor_soal> -lm
```
*(Flag `-lm` ditambahkan jika program menggunakan library `<math.h>`)*

### 2. Eksekusi
```powershell
.\5025251024_<nomor_soal>
```

---

## 📝 Rincian Tugas Pekan 7 (`S_7`)

1. **Soal 2 — Resistor Color Codes Decoder (`5025251024_2.c`)**
   - Mendekode 3 pita warna resistor menjadi nilai resistansi dalam satuan **kilo-ohms**.
   - Menyediakan fungsi pembantu `search()` untuk mencocokkan nama warna ke nilai digit/multiplier dari tabel warna.
   - Dilengkapi validasi input warna serta perulangan decoding interaktif.

2. **Soal 6 — Parallel Arrays Sorter (`5025251024_6.c`)**
   - Menyimpan daftar nama (format *last name first*) dan umur ke dalam *parallel arrays*.
   - Mengurutkan daftar nama secara alfabetis (*A–Z*) dan menjaga sinkronisasi umur masing-masing individu secara presisi.

3. **Soal 10 — ACLS Drug Assistant (`5025251024_10.c`)**
   - Membaca file data `drugs.txt` yang memuat nama obat resusitasi jantung dan petunjuk dosis/administrasinya.
   - Mengubah tanda titik-koma (`;`) menjadi baris baru (`\n`) agar instruksi tersaji rapi per baris.
   - Menyediakan pencarian interaktif berbasis 3 karakter awalan nama obat atau `q` untuk keluar.
