/* * Kaynak: Pointers2.pdf - Sayfa 17
 * Konu: İşaretçi Notasyonu *(ptr + i) Kullanımı
 */
#include <stdio.h>

int main() {
    char alfabe[27], *ptr = alfabe;
    int i;

    for (i = 0; i < 26; i++) {
        // ptr'den i kadar uzağa git ve harfi oraya yaz
        *(ptr + i) = 'A' + i;
        printf("%c ", *(ptr + i));
    }

    return 0;
}
