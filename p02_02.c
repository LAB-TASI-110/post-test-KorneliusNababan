#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Mendefinisikan struktur data untuk stok barang (S1, S2, ... SN)
struct Barang {
    char nama[50];
    int stok;
};

int main() {
    // Menentukan jumlah total data (N = 4 lembar data)
    int N = 4;
    
    // 2. Inisialisasi deret stok berdasarkan studi kasus
    struct Barang daftarStok[] = {
        {"MINYAK", 120},
        {"ROK PRAMUKA", 5},
        {"GULA", 85},
        {"DASI SD", 22}
    };

    char kategoriDicari[20];
    int totalStokKategori = 0;

    // Menampilkan daftar barang yang tersedia di gudang
    printf("=== DATA STOK GUDANG ===\n");
    for(int i = 0; i < N; i++) {
        printf("%d. %s (%d PCS)\n", i+1, daftarStok[i].nama, daftarStok[i].stok);
    }

    // 3. Input kode kategori barang yang diminta
    printf("\nMasukkan kategori barang yang ingin dihitung (misal: SD, PRAMUKA): ");
    scanf("%s", kategoriDicari);

    // Proses pencarian dan penjumlahan stok berdasarkan kategori
    for(int i = 0; i < N; i++) {
        // Menggunakan strstr untuk mengecek apakah kategori ada di dalam nama barang
        // Contoh: Jika input "SD", maka "DASI SD" akan terhitung
        if (strstr(daftarStok[i].nama, kategoriDicari) != NULL) {
            totalStokKategori += daftarStok[i].stok;
        }
    }

    // Output hasil akhir ke terminal/CLI
    printf("------------------------------------\n");
    printf("Total stok untuk kategori '%s' adalah: %d PCS\n", kategoriDicari, totalStokKategori);
    printf("------------------------------------\n");

    return 0;
}