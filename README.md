# Programming Fundamentals (Dasar Pemrograman)

Repository ini berisi kumpulan tugas, praktikum, latihan, dan evaluasi mata kuliah **Dasar Pemrograman** (*Programming Fundamentals*) menggunakan bahasa **C**.

---

## 👤 Informasi Mahasiswa
- **Nama** : Rinaltra Nabasa Simanungkalit
- **NRP**  : 5025251024
- **Program Studi** : Teknik Informatika
- **Perguruan Tinggi** : Institut Teknologi Sepuluh Nopember (ITS)

---

## 📂 Struktur Repositori

Repositori ini terbagi menjadi dua bagian materi perkuliahan:

### 1. Tugas Rutin Praktikum Mingguan
Diorganisir per pertemuan/pekan dengan format folder `5025251024_Rinaltra Nabasa S_<Pekan>/`:

| Folder | Topik & Deskripsi Masalah | File C Utama |
| :--- | :--- | :--- |
| **`S_1`** | Pengenalan Sintaks C, Input/Output, & Operasi Dasar | `5025251024_2.c`, `5025251024_3.c`, `5025251024_7.c` |
| **`S_2`** | Ekspresi Matematika & Aproksimasi (Gosper's Formula) | `5025251024_4.c`, `5025251024_7.c`, `5025251024_12.c` |
| **`S_3`** | Struktur Kontrol Percabangan (*Selection / Conditionals*) | `5025251024_1.c`, `5025251024_6.c`, `5025251024_9.c` |
| **`S_4`** | Perulangan (*Loops*) & Tabel Perhitungan Finansial / Fisika | `5025251024_3.c`, `5025251024_5.c`, `5025251024_7_vehicle_speeds.c` |
| **`S_5`** | Fungsi Modular (*Modular Functions*) & Menu Interaktif | `5025251024_2.c` (Asisten Laju Infus), `5025251024_5.c`, `5025251024_6.c` |
| **`S_6`** | Array 1D/2D, Pemrosesan File, & Analisis Data | `5025251024_2.c` (Polygon Area), `5025251024_5.c` (Barcode Validator), `5025251024_10.c` (Election Tally) |
| **`S_7`** | Array String, Algoritma Pencarian & Pengurutan (*Sorting & Search*) | `5025251024_2.c` (Resistor Color Code), `5025251024_6.c` (Parallel Array Sort), `5025251024_10.c` (ACLS Drug Assistant) |

Setiap folder mingguan dilengkapi dengan file source code (`*.c`), file executable hasil kompilasi (`*.exe`), file data uji (`*.txt`), dan bukti tangkapan layar terminal (`*.png`).

---

### 2. Modul Tugas, Tutorial, Kuis, & Ujian
Koleksi materi praktikum intensif, kuis, persiapan evaluasi tengah & akhir semester:

| Direktori | Deskripsi & Cakupan Topik |
| :--- | :--- |
| **`Assignment/`** | Koleksi latihan pemrograman terstruktur: **Tugas 1** s/d **Tugas 8** (sintaks dasar, percabangan, perulangan, fungsi modular, manipulasi string, rekursi, hingga binary search). |
| **`Tutorial/`** | Pengenalan dasar bahasa C, struktur program, input/output (`scanf`, `printf`). |
| **`Tutorial 2/`** | Struktur kondisi dan logika (cek ganjil/genap, tahun kabisat, konversi nilai/grade, simulasi tarif BBM, kalkulator). |
| **`Tutorial 3/`** | Perulangan bersarang (*nested loops*), deret angka, dan pembentukan pola karakter. |
| **`Tutorial 4/`** | Implementasi fungsi berparameter, *pass-by-value* vs *pass-by-reference*, dan array numerik. |
| **`Tutorial 5/`** | Pemrosesan string lanjutan (deteksi panjang string, komparasi kata, konkatenasi, penghitung kata, filter karakter, dan deteksi palindrom). |
| **`Quiz/` & `Quiz Prac/`** | Latihan dan soal evaluasi kuis praktikum (algoritma pencarian biner, *insertion sort*, manipulasi pointer, dan operasi matriks 2D). |
| **`Remidial ETS 1/`** | Pembahasan dan latihan remedial Evaluasi Tengah Semester (Air Quality Index / AQI, perhitungan jarak Manhattan, pola belah ketupat/piramida terbalik, dan sensor kata). |
| **`EAS/`** | Soal dan penyelesaian Evaluasi Akhir Semester (kalkulator BMI, pola geometri, analisis statistik data, deret segitiga, manipulasi matriks, pengurutan data numerik, dekripsi pesan rahasia, dan pengurutan kata). |
| **`EAS Practice/`** | Latihan soal intensif persiapan EAS (fungsi rekursif deret bilangan, faktorial, fibonacci, pencarian nilai maksimum dan penjumlahan deret). |

---

## 🛠️ Kompilasi dan Menjalankan Program

Program dapat dikompilasi menggunakan compiler **GCC (MinGW)** di Windows, Linux, maupun macOS.

### 1. Kompilasi
Buka terminal / PowerShell di direktori file yang ingin dijalankan:
```bash
gcc nama_file.c -o nama_file -lm
```
*(Tambahkan `-lm` jika kode menggunakan library `<math.h>`)*

### 2. Eksekusi
```powershell
.\nama_file
```

---

## 📝 Highlight Tugas Pekan 7 (`S_7`)

1. **Soal 2 — Resistor Color Codes Decoder (`5025251024_2.c`)**
   - Mendekode pita warna resistor menjadi nilai resistansi dalam satuan **kilo-ohms**.
   - Menyediakan fungsi pembantu `search()` untuk mencocokkan string nama warna ke index tabel kode warna.
   - Dilengkapi validasi input warna serta perulangan decoding interaktif.

2. **Soal 6 — Parallel Arrays Sorter (`5025251024_6.c`)**
   - Menyimpan daftar nama (*last name first*) dan umur ke dalam *parallel arrays*.
   - Mengurutkan daftar nama secara alfabetis (*A–Z*) menggunakan algoritma pengurutan dan menjaga sinkronisasi umur masing-masing individu secara presisi.

3. **Soal 10 — ACLS Drug Assistant (`5025251024_10.c`)**
   - Membaca file data `drugs.txt` yang memuat nama obat resusitasi jantung (*Advanced Cardiac Life Support*) dan petunjuk dosis/administrasinya.
   - Mengubah tanda titik-koma (`;`) menjadi baris baru (`\n`) agar instruksi tersaji rapi per baris.
   - Menyediakan pencarian interaktif berbasis 3 karakter awalan nama obat atau `q` untuk keluar.
