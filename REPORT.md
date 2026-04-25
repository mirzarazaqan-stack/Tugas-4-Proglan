# Laporan Programming Assignment 3: Simple STL

**Nama:** Nabil Mirza Razaqan  
**Jurusan:** Teknik Komputer - Institut Teknologi Sepuluh Nopember (ITS)  

---

## 1. Deskripsi Program
Program ini merupakan implementasi C++ yang memanfaatkan Standard Template Library (STL) `std::vector` dan konsep Object-Oriented Programming (OOP) untuk mengklasifikasikan jenis segitiga dalam ruang tiga dimensi (3D). Program menerima input berupa koordinat tiga titik (X, Y, Z), menyimpannya ke dalam objek, dan mengevaluasi sifat geometrisnya.

Jenis segitiga yang dapat diidentifikasi meliputi:
* **Sama Sisi (Equilateral):** Ketiga sisi memiliki panjang yang sama.
* **Siku-Siku (Right-Angled):** Memenuhi hukum Pythagoras ($a^2 + b^2 = c^2$).
* **Sama Kaki (Isosceles):** Minimal dua sisi memiliki panjang yang sama.
* **Sembarang (Scalene):** Tidak ada sisi yang sama panjang dan tidak memenuhi hukum Pythagoras.

## 2. Struktur Data dan Logika Implementasi

### A. Kelas `Point2D` (Titik 3D)
Meskipun bernama `Point2D`, kelas ini diimplementasikan untuk mendukung koordinat 3D sesuai dengan instruksi tugas (X, Y, Z). Fitur utama dalam kelas ini adalah fungsi `distanceSquared`:

```cpp
float Point2D::distanceSquared(const Point2D inp) {
    float dx = this->_x - inp.GetX();
    float dy = this->_y - inp.GetY();
    float dz = this->_z - inp.GetZ();
    return (dx * dx) + (dy * dy) + (dz * dz);
}
```
**Optimasi:** Penggunaan **kuadrat jarak** dipilih sebagai pengganti nilai jarak asli (`sqrt()`). Hal ini dilakukan untuk menjaga efisiensi komputasi (menghindari fungsi akar yang berat) serta meminimalisir galat presisi (*floating-point error*) saat dilakukan perbandingan nilai.

### B. Kelas `Triangle` (Logika Klasifikasi)
Kelas ini menyimpan tiga objek `Point2D`. Logika penentuan tipe segitiga dilakukan dengan langkah berikut:
1. Menghitung kuadrat panjang ketiga sisi.
2. Memasukkan nilai tersebut ke dalam *array* dan melakukan pengurutan (`std::sort`) agar sisi terpanjang berada di posisi terakhir.
3. Melakukan pengecekan dengan batas toleransi `epsilon` ($10^{-4}$) untuk menangani limitasi presisi perhitungan desimal pada tipe data `float`.

### C. Penggunaan STL Vector
Pada fungsi `main`, program menggunakan `std::vector<Triangle>` untuk menampung data secara dinamis. Hal ini memungkinkan program untuk memproses banyak data segitiga sekaligus dalam satu kali eksekusi (terus membaca input hingga menemukan sinyal EOF).

### D. Poin Tambahan: Custom Namespace
Program ini menggunakan *custom namespace* bernama `NabilSpace` untuk membungkus fungsi evaluator iterasi vektor. Hal ini bertujuan untuk mencegah polusi pada *global namespace* dan menunjukkan penerapan struktur kode yang lebih modular dan rapi.

## 3. Hasil Pengujian (Input & Output)

Program diuji menggunakan beberapa skenario koordinat untuk memastikan semua logika klasifikasi berjalan dengan benar. 

**Data Input (Melalui Terminal):**
```text
0 0 0 3 0 0 0 4 0
0 0 0 4 0 0 2 3 0
0 0 0 2 0 0 1 1.73205 0
0 0 0 5 0 0 1 2 3
```

**Hasil Output:**
```text
siku-siku
sama kaki
sama sisi
sembarang
```

## 4. Analisis Kasus Uji
* **Kasus 1:** Titik (0,0,0), (3,0,0), dan (0,4,0) membentuk segitiga siku-siku dengan panjang sisi 3, 4, dan 5. Sesuai dengan pembuktian $3^2 + 4^2 = 5^2$.
* **Kasus 2:** Menghasilkan dua sisi miring yang sama panjang, diklasifikasikan dengan benar sebagai sama kaki.
* **Kasus 3:** Menggunakan koordinat dengan pendekatan nilai $\sqrt{3}$ ($\approx 1.73205$) untuk membentuk segitiga yang ketiga sisinya sama panjang secara presisi.
* **Kasus 4:** Koordinat acak asimetris dalam ruang 3D yang menghasilkan panjang sisi tidak beraturan, secara otomatis diklasifikasikan sebagai sembarang.

## 5. Kesimpulan
Implementasi program telah memenuhi seluruh kriteria *assignment*. Kode terbagi dengan baik ke dalam *header* dan *source file*, menerapkan pembacaan data dinamis dengan STL `vector`, memanfaatkan optimasi matematika pada perhitungan jarak, dan menerapkan *custom namespace* dengan baik.