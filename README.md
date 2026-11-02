# Programming Fundamentals (C Language)

Kumpulan kode sumber, modul praktikum, tugas terstruktur, dan materi evaluasi untuk pembelajaran **Dasar Pemrograman** (*Programming Fundamentals*) menggunakan bahasa pemrograman **C**.

---

## 📌 Deskripsi Repositori

Repositori ini memuat implementasi konsep-konsep inti pemrograman imperatif dan prosedural. Materi disusun secara bertahap mulai dari pemahaman sintaks dasar, logika komputasi, struktur data primitif, hingga penerapan algoritma pencarian dan pengurutan data.

---

## 📚 Topik & Silabus Pembelajaran

1. **Konsep Dasar & Alur Program**
   - Sintaks dasar, tipe data primitif, dan operator aritmatika/logika
   - Standar input/output (`scanf`, `printf`) serta format specifiers

2. **Struktur Kontrol**
   - Percabangan: `if-else`, *nested conditionals*, dan `switch-case`
   - Perulangan: `for`, `while`, `do-while`, dan *nested loops*

3. **Modularitas & Fungsi**
   - Desain fungsi modular (*user-defined functions*)
   - Mekanisme parameter (*pass-by-value* dan *pass-by-reference*)
   - Konsep fungsi rekursif (*recursion*)

4. **Struktur Data Terstruktur**
   - Array satu dimensi (1D) dan dua dimensi (2D / matriks)
   - Manipulasi string dan pemrosesan karakter (`string.h`)
   - Tipe data bentukan (*struct*)

5. **Pointer & Manajemen Memori**
   - Dasar konsep pointer, alamat memori, dan dereferensi
   - Pointer aritmatika dan integrasi pointer dengan array/fungsi

6. **Algoritma Dasar**
   - Algoritma Pencarian: *Linear Search* & *Binary Search*
   - Algoritma Pengurutan: *Bubble Sort*, *Selection Sort*, & *Insertion Sort*

7. **Pemrosesan File (*File I/O*)**
   - Pembacaan dan penulisan berkas (`fopen`, `fscanf`, `fprintf`, `fclose`)

---

## 📂 Struktur Direktori

```text
ProgrammingFundamentals/
├── Assignment/         # Latihan soal tematik (Tugas 1-8) & tugas mingguan (S_1 - S_7)
├── tutorials/          # Modul bimbingan dan hands-on praktikum (Tutorial 1-5)
├── tests/              # Evaluasi berkala, ETS, dan EAS (Remidial ETS 1, EAS, EAS Practice)
└── Quiz/               # Kuis praktikum dan latihan kuis algoritma
```

---

## 🛠️ Kompilasi dan Menjalankan Program

Program dalam repositori ini dapat dikompilasi menggunakan compiler **GCC** (GNU Compiler Collection).

### 1. Kompilasi
Buka terminal pada direktori file `.c` yang ingin dijalankan:
```bash
gcc nama_program.c -o nama_program -lm
```
> *Catatan: Tambahkan flag `-lm` apabila program memanfaatkan fungsi matematika dari pustaka `<math.h>`.*

### 2. Eksekusi
- **Windows (PowerShell / CMD):**
  ```powershell
  .\nama_program.exe
  ```
- **Linux / macOS:**
  ```bash
  ./nama_program
  ```
