/* * Kaynak: Pointers2.pdf - Sayfa 5
 * Konu: Dizilerin Bellekteki Ardışık Yapısı
 */
#include <stdio.h>

int main() {
    int x[4], i;
    int *p = x; // Dizi başlangıç adresi

    for (i = 0; i < 4; ++i) {
        // Her elemanın adresini yazdırıyoruz (genelde 4'er byte artar)
        printf("&x[%d] adresi = %p\n", i, &x[i]);
    }

    printf("Dizi ismi (x) adresi: %p\n", x);
    printf("Isaretci (p) degeri: %p\n", p);

    return 0;
}
