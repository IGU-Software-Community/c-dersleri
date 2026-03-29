/* * Kaynak: Pointers2.pdf - Sayfa 1
 * Konu: İşaretçi Atamaları ve Karmaşık Bellek Takibi
 */
#include <stdio.h>

int main() {
    int a = 15, b = 20;
    int *p1, *p2, *p3;

    p1 = &a;
    *p1 = b + 10; // a = 30 oldu

    p3 = &b;
    p2 = p3;      // p2 ve p3 artık b'nin adresini tutuyor
    (*p2)++;      // b'nin değeri 21 oldu

    printf("\n b degeri: %d", b);

    *p3 = *p1 - 10; // b = 30 - 10 -> b tekrar 20 oldu
    printf("\nb degeri (son): %d", b);

    return 0;
}
