#include <stdio.h>
#include <stdlib.h>

/*
 * SINAV UYARISI: realloc sorularında dikkat edilecek noktalar:
 * 1) Eski veriler korunur mu?
 * 2) Yeni eklenen alanın ilk değeri nedir?
 * 3) temp pointer neden kullanılır?
 * 4) realloc başarısız olursa ne olur?
 *
 * SORU: Programın çıktısı nedir?
 */

int main() {
    int i;

    // Adim 1: calloc ile 3 elemanlik dizi (hepsi 0)
    int *dizi = (int *) calloc(3, sizeof(int));
    if (dizi == NULL) return 1;

    dizi[0] = 10;
    dizi[1] = 20;
    dizi[2] = 30;

    printf("--- Baslangic (3 eleman) ---\n");
    for (i = 0; i < 3; i++)
        printf("dizi[%d] = %d\n", i, dizi[i]);

    // Adim 2: realloc ile 5 elemana genislet
    int *temp = (int *) realloc(dizi, 5 * sizeof(int));
    if (temp == NULL) {
        printf("realloc basarisiz!\n");
        free(dizi);
        return 1;
    }
    dizi = temp;

    // Soru A: dizi[0], dizi[1], dizi[2] degisti mi?
    // Soru B: dizi[3] ve dizi[4] ne icerir?

    // Yeni elemanlara deger atayalim
    dizi[3] = 40;
    dizi[4] = 50;

    printf("\n--- Genisletme sonrasi (5 eleman) ---\n");
    for (i = 0; i < 5; i++)
        printf("dizi[%d] = %d\n", i, dizi[i]);

    // Adim 3: realloc ile 2 elemana kucult
    temp = (int *) realloc(dizi, 2 * sizeof(int));
    if (temp == NULL) {
        free(dizi);
        return 1;
    }
    dizi = temp;

    // Soru C: dizi[0] ve dizi[1] ne olur?
    // Soru D: dizi[2], dizi[3], dizi[4]'e erisebilir miyiz?

    printf("\n--- Kucultme sonrasi (2 eleman) ---\n");
    for (i = 0; i < 2; i++)
        printf("dizi[%d] = %d\n", i, dizi[i]);

    // Toplam hesapla
    int toplam = 0;
    for (i = 0; i < 2; i++)
        toplam += *(dizi + i);
    printf("Toplam: %d\n", toplam);

    free(dizi);
    dizi = NULL;

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * --- Baslangic (3 eleman) ---
 * dizi[0] = 10
 * dizi[1] = 20
 * dizi[2] = 30
 *
 * Soru A: HAYIR, degismedi. realloc eski verileri korur.
 *         dizi[0]=10, dizi[1]=20, dizi[2]=30 aynen kalir.
 *
 * Soru B: dizi[3] ve dizi[4] COP VERI icerir!
 *         realloc (malloc gibi) yeni alana ilk deger atamaz.
 *         Biz elle 40 ve 50 atadik.
 *
 * --- Genisletme sonrasi (5 eleman) ---
 * dizi[0] = 10
 * dizi[1] = 20
 * dizi[2] = 30
 * dizi[3] = 40
 * dizi[4] = 50
 *
 * Soru C: dizi[0]=10 ve dizi[1]=20 aynen korunur.
 *         Kucultmede ilk n eleman korunur, gerisine erisilemez.
 *
 * Soru D: HAYIR! dizi[2], [3], [4] artik dizinin disinda.
 *         Erismek tanimlanmamis davranistir (undefined behavior).
 *
 * --- Kucultme sonrasi (2 eleman) ---
 * dizi[0] = 10
 * dizi[1] = 20
 * Toplam: 30
 *
 * SINAV NOTU - temp pointer neden kullanilir:
 *   YANLIS: dizi = realloc(dizi, ...);
 *     -> realloc basarisiz olursa NULL doner
 *     -> dizi'nin eski adresi kaybolur -> veri kaybi!
 *
 *   DOGRU: temp = realloc(dizi, ...);
 *     -> Basarisiz olsa bile dizi hala eski veriyi tutar
 *     -> Basariliysa dizi = temp ile guncelle
 */
