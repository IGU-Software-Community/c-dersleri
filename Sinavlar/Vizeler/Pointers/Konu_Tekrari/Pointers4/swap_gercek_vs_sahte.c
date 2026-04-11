#include <stdio.h>

/*
 * SINAV UYARISI: Kağıt üzerinde x, y, z değerlerini
 * her if bloğundan sonra güncelleyerek takip edin.
 * Özellikle swap fonksiyonuna &x mi yoksa x mi
 * gönderildiğine dikkat edin!
 *
 * SORU: Programın çıktısı nedir?
 */

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sahteSwap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    printf("  sahteSwap icinde -> a: %d, b: %d\n", a, b);
}

int main() {
    int x = 30, y = 10, z = 20;

    printf("Baslangic: x=%d, y=%d, z=%d\n", x, y, z);

    // Adim 1: Gercek swap (adres gonderiliyor)
    if (x > y)
        swap(&x, &y);

    printf("Adim 1 sonrasi: x=%d, y=%d, z=%d\n", x, y, z);

    // Adim 2: Sahte swap (deger gonderiliyor - kopya!)
    if (y > z)
        sahteSwap(y, z);

    printf("Adim 2 sonrasi: x=%d, y=%d, z=%d\n", x, y, z);

    // Adim 3: Gercek swap
    if (y > z)
        swap(&y, &z);

    printf("Adim 3 sonrasi: x=%d, y=%d, z=%d\n", x, y, z);

    // Adim 4: Zincirleme
    if (x > y)
        swap(&x, &y);

    printf("Son durum: x=%d, y=%d, z=%d\n", x, y, z);

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * Baslangic: x=30, y=10, z=20
 *
 * Adim 1: x>y (30>10 EVET) -> swap(&x, &y) -> x=10, y=30
 *   Adim 1 sonrasi: x=10, y=30, z=20
 *
 * Adim 2: y>z (30>20 EVET) -> sahteSwap(y, z) cagrilir
 *   AMA! sahteSwap deger aliyor, adres degil.
 *   Fonksiyon icinde a=20, b=30 olur (kopyalar takas edildi).
 *   sahteSwap icinde -> a: 20, b: 30
 *   FAKAT main'deki y ve z DEGISMEZ! Hala y=30, z=20.
 *   Adim 2 sonrasi: x=10, y=30, z=20
 *
 * Adim 3: y>z (30>20 EVET) -> swap(&y, &z) -> y=20, z=30
 *   Adim 3 sonrasi: x=10, y=20, z=30
 *
 * Adim 4: x>y (10>20 HAYIR) -> swap cagrilmaz
 *   Son durum: x=10, y=20, z=30
 */
