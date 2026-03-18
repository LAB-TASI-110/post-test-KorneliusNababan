#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi variabel untuk data paket
    char kode[5];
    float berat_butet = 1.0; // Berat paket Butet (1kg)
    float berat_ucok = 1.5;  // Berat paket Ucok (3/2 kg)
    float total_berat, total_ongkir, diskon, harga_per_kg;
    char *nama_kota, *keterangan;

    // Menampilkan header program
    printf("=== Program Input Pengiriman Del Express ===\n");
    printf("Masukkan Kode Kota (MDN/BLG/JKT/SBY) dan Jumlah Paket.\n");
    printf("Ketik 'END' untuk mengakhiri input.\n\n");

    while (1) {
        printf("Masukkan Kode Kota: ");
        scanf("%s", kode);

        // Berhenti jika user memasukkan END
        if (strcmp(kode, "END") == 0) {
            break;
        }

        int jumlah_paket;
        printf("Masukkan Jumlah Paket: ");
        scanf("%d", &jumlah_paket);

        // Logika penentuan harga dan kota berdasarkan kode
        if (strcmp(kode, "MDN") == 0) {
            nama_kota = "Medan";
            harga_per_kg = 8000;
            keterangan = "Dalam Pulau";
        } else if (strcmp(kode, "BLG") == 0) {
            nama_kota = "Balige";
            harga_per_kg = 5000;
            keterangan = "Dalam Pulau";
        } else if (strcmp(kode, "JKT") == 0) {
            nama_kota = "Jakarta";
            harga_per_kg = 12000;
            keterangan = "Luar Pulau";
        } else if (strcmp(kode, "SBY") == 0) {
            nama_kota = "Surabaya";
            harga_per_kg = 13000;
            keterangan = "Luar Pulau";
        } else {
            printf("Kode kota tidak valid!\n\n");
            continue;
        }

        // Kalkulasi berat per transaksi (Butet + Ucok) * Jumlah Paket
        total_berat = (berat_butet + berat_ucok) * jumlah_paket;
        
        // Kalkulasi ongkir dasar
        total_ongkir = total_berat * harga_per_kg;

        // Cek promo: Diskon 10% jika berat > 10kg
        diskon = 0;
        if (total_berat > 10) {
            diskon = total_ongkir * 0.10;
            total_ongkir -= diskon;
        }

        // Output Struk Pembayaran
        printf("\n================ STRUK PEMBAYARAN ================\n");
        printf("Kota Tujuan          : %s (%s)\n", nama_kota, kode);
        printf("Berat Paket Butet    : %.1f kg\n", berat_butet * jumlah_paket);
        printf("Berat Paket Ucok     : %.1f kg\n", berat_ucok * jumlah_paket);
        printf("Total Berat          : %.1f kg\n", total_berat);
        
        // Cek promo: Asuransi gratis untuk Luar Pulau
        if (strcmp(keterangan, "Luar Pulau") == 0) {
            printf("Info Tambahan        : Gratis Asuransi (Luar Pulau)\n");
        }

        if (diskon > 0) {
            printf("Diskon (Promo >10kg) : Rp %.0f\n", diskon);
        }

        printf("Total Ongkos Kirim   : Rp %.0f\n", total_ongkir);
        printf("==================================================\n\n");
    }

    printf("Program Selesai. Terima kasih.\n");
    return 0;
}