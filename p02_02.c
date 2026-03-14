#include <stdio.h>
#include <string.h>

#define MAX 100

// PILAR 3: FUNGSI MODULAR
// Fungsi untuk menghitung dan menampilkan stok berdasarkan ID kategori
void hitungStok(int n, int daftarStok[], char daftarNama[][50], int cariID) {
    // PILAR 4: VALIDASI (Error Handling)
    if (cariID < 1 || cariID > n) {
        printf("Kode %d Tidak Dikenal!\n", cariID);
    } else {
        // Pemetaan index: Manusia (1..N) -> C (0..N-1)
        int index = cariID - 1;

        // FORMAT OUTPUT: Struk Ringkas sesuai Pilar 3
        printf("\n--- STRUK GUDANG ---\n");
        printf("Kategori: %d | Nama Barang: %s | Total Stok: %d\n", 
                cariID, daftarNama[index], daftarStok[index]);
        printf("--------------------\n");
    }
}

int main() {
    int n, cariID;
    int stok[MAX];
    char nama[MAX][50];

    // Input pertama: Jumlah total data (N)
    printf("N : ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; // Berhenti jika N = 0 atau input tidak valid
    }

    // Input kedua: Pengisian data stok dan nama
    // Masukkan data secara berurutan
    for (int i = 0; i < n; i++) {
        // Format: Nama_Barang Stok (Gunakan underscore untuk nama dengan spasi)
        printf("Data %d (Nama Stok): ", i + 1);
        scanf("%s %d", nama[i], &stok[i]);
    }

    // Input ketiga: Kode kategori yang dicari
    printf("\nCari Kode Kategori: ");
    scanf("%d", &cariID);

    // Memanggil fungsi modular untuk memproses data
    hitungStok(n, stok, nama, cariID);

    return 0;
}