/* * Kaynak: pointers.pdf - Sayfa 33
 * Konu: Adres Operatörü (&) ve İşaretçi Karşılaştırması
 */
#include <stdio.h>

int main() {
    int *ptam, tam = 33;
    ptam = &tam; // ptam artık tam'ın adresini biliyor

    printf("tam icerik = %d\n", tam);
    printf("tam adres (&tam) = %p\n", &tam);
    printf("tam adres (ptam) = %p\n", ptam);

    return 0;
}
