/* * Kaynak: pointers.pdf - Sayfa 35
 * Konu: İşaretçi Üzerinden Değer Değiştirme (Dolaylı Erişim)
 */
#include <stdio.h>

int main() {
    int *ptam, tam = 33;
    ptam = &tam;

    printf("Eski deger: %d\n", tam);

    *ptam = 44; // ptam'ın gösterdiği adrese git ve oraya 44 yaz

    printf("Yeni deger: %d\n", tam); // Değişken otomatik olarak 44 oldu
    return 0;
}
