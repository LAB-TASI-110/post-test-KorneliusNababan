#include <stdio.h>
#include <string.h>

/**
 * Program: Del-Express Shipping System
 * Author: Pakar Pemrograman C
 */

void cetakStruk(char kota[], float bButet) {
    float bUcok = bButet * 1.5; // Berat Ucok 3/2 dari Butet
    float totalBerat = bButet + bUcok;
    int hargaPerKg = 0;
    char namaKota[20];
    char promo[50] = "Tidak ada promo";

    // Menentukan Harga Berdasarkan Kode Kota
    if (strcmp(kota, "MDN") == 0) {
        hargaPerKg = 15000;
        strcpy(namaKota, "MEDAN");
    } else if (strcmp(kota, "JKT") == 0) {
        hargaPerKg = 25000;
        strcpy(namaKota, "JAKARTA");
    } else if (strcmp(kota, "BLG") == 0) {
        hargaPerKg = 10000;
        strcpy(namaKota, "BALIGE");
    } else if (strcmp(kota, "SBY") == 0) {
        hargaPerKg = 30000;
        strcpy(namaKota, "SURABAYA");
    } else {
        printf("Kode Kota %s Tidak Dikenal!\n", kota);
        return;
    }

    float totalOngkos = totalBerat * hargaPerKg;

    // Logika Promo Berdasarkan Total Berat
    if (totalBerat > 10) {
        totalOngkos *= 0.9;
        strcpy(promo, "Diskon 10% (Berat > 10kg)");
    } else if (totalBerat > 5) {
        totalOngkos *= 0.95;
        strcpy(promo, "Diskon 5% (Berat > 5kg)");
    }

    // Output Struk Pembayaran
    printf("\n========= STRUK PEMBAYARAN DEL-EXPRESS =========\n");
    printf("Kota Tujuan             : %s\n", namaKota);
    printf("Berat Paket Butet       : %.2f kg\n", bButet);
    printf("Berat Paket Ucok (3/2)  : %.2f kg\n", bUcok);
    printf("Total Berat             : %.2f kg\n", totalBerat);
    printf("Total Ongkos Kirim      : Rp %.2f\n", totalOngkos);
    printf("Informasi Promo         : %s\n", promo);
    printf("================================================\n");
}

int main() {
    char inputKota[10];
    float beratIn;

    while (1) {
        // Input Kode Kota
        scanf("%s", inputKota);
        
        // Cek penghenti program
        if (strcmp(inputKota, "END") == 0) break;

        // Input Berat Paket Butet
        scanf("%f", &beratIn);

        // Proses dan Cetak
        cetakStruk(inputKota, beratIn);
    }

    return 0;
}