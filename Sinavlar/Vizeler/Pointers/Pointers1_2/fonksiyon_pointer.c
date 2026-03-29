/* * Kaynak: Pointers2.pdf - Sayfa 9
 * Konu: Fonksiyonlara İşaretçi Gönderimi (Call by Reference)
 */
#include <stdio.h>

// Fonksiyon asıl bellek adresini kullanarak değeri değiştirir
void arttir(int* ptr) {
    (*ptr)++;
}

int main() {
    int sayi = 10;
    arttir(&sayi); // sayi'nın kopyasını değil, ev adresini gönderiyoruz

    printf("Yeni sayi degeri: %d", sayi); // Sonuç 11 olur
    return 0;
}
