#include <stdio.h>
#include <string.h>

// Fungsi modular untuk menghitung total
int hitungTotalPesanan(int harga, int qty) {
    return harga * qty;
}

int main() {
    char daftarNama[50][100];
    int daftarHarga[50];
    int n, i;

    printf("Masukkan jumlah jenis menu: ");
    // Validasi apakah input benar-benar angka
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Masukkan jumlah menu dalam bentuk angka positif!\n");
        return 0;
    }

    if (n > 50) {
        printf("Kapasitas maksimal hanya 50 menu!\n");
        return 0;
    }

    // Input data menu
    for (i = 0; i < n; i++) {
        printf("\n--- Data Menu %d ---\n", i + 1);
        printf("Nama Menu : ");
        // " %[^\n]" berfungsi membaca kalimat sampai bertemu Enter (termasuk spasi)
        scanf(" %[^\n]", daftarNama[i]);
        
        printf("Harga     : ");
        scanf("%d", &daftarHarga[i]);
    }

    int kodePilihan, qty;
    printf("\n============================\n");
    printf("      FORM PEMESANAN       \n");
    printf("============================\n");
    printf("Pilih Kode Menu (1-%d): ", n);
    scanf("%d", &kodePilihan);
    printf("Jumlah Porsi: ");
    scanf("%d", &qty);

    // Logika pemetaan indeks (Kode 1 -> Indeks 0)
    if (kodePilihan < 1 || kodePilihan > n) {
        printf("\nMenu Tidak Tersedia!\n");
    } else {
        int indeks = kodePilihan - 1;
        int total = hitungTotalPesanan(daftarHarga[indeks], qty);

        // Output Struk
        printf("\n[Kafetaria IT Del]\n");
        printf("Menu  : %s\n", daftarNama[indeks]);
        printf("Porsi : %d\n", qty);
        printf("Total : Rp %d\n", total);
        printf("----------------------------\n");
    }

    return 0;
}