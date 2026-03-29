/* * Kaynak: pointers.pdf - Sayfa 27 / 31
 * Konu: Tamsayı Değişkeni ve İşaretçi İlişkisi
 */
#include <stdio.h>

int main() {
    int a;
    int *adres;
    adres = &a; // a değişkeninin bellek adresini 'adres' içine koy

    printf("Bir tamsayi giriniz\n");
    scanf("%d", &a);

    printf("a degiskeninin adresi: %p\n", &a);
    printf("a degiskenindeki sayi: %d\n", a);
    printf("isaretci uzerinden ulasilan deger (*adres): %d\n", *adres);

    return 0;
}
