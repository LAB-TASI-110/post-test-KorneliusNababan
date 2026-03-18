#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur data pesanan
struct Pesanan {
    char namaPelanggan[50];
    char namaMenu[50];
    double hargaTotal;
};

int main() {
    int jumlahPesanan;

    printf("=== Operasional Kafetaria IT Del ===\n");
    printf("Masukkan jumlah pesanan hari ini: ");
    scanf("%d", &jumlahPesanan);
    
    // Membersihkan buffer setelah scanf
    getchar(); 

    struct Pesanan daftarPesanan[jumlahPesanan];

    // Proses Input Data
    for (int i = 0; i < jumlahPesanan; i++) {
        printf("\nData Pesanan ke-%d\n", i + 1);
        
        printf("Nama Pelanggan: ");
        fgets(daftarPesanan[i].namaPelanggan, sizeof(daftarPesanan[i].namaPelanggan), stdin);
        daftarPesanan[i].namaPelanggan[strcspn(daftarPesanan[i].namaPelanggan, "\n")] = 0; // Menghapus newline

        printf("Nama Menu     : ");
        fgets(daftarPesanan[i].namaMenu, sizeof(daftarPesanan[i].namaMenu), stdin);
        daftarPesanan[i].namaMenu[strcspn(daftarPesanan[i].namaMenu, "\n")] = 0;

        printf("Total Harga   : ");
        scanf("%lf", &daftarPesanan[i].hargaTotal);
        getchar(); // Membersihkan buffer
    }

    // Menampilkan Laporan Singkat
    printf("\n\n=== Ringkasan Operasional Kafetaria ===\n");
    printf("%-20s | %-20s | %-10s\n", "Nama Pelanggan", "Menu", "Harga");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlahPesanan; i++) {
        printf("%-20s | %-20s | Rp %.2f\n", 
               daftarPesanan[i].namaPelanggan, 
               daftarPesanan[i].namaMenu, 
               daftarPesanan[i].hargaTotal);
    }

    return 0;
}