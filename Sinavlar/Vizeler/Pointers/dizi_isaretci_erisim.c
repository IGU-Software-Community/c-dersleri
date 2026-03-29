/* * Kaynak: pointers.pdf - Sayfa 49
 * Konu: Karakter Dizileri (Strings) ve İşaretçi Aritmetiği
 */
#include <stdio.h>

int main() {
    char stringim[] = "ruyasamli";
    char *ptr;
    ptr = stringim; // Dizinin adı, aslında ilk elemanın (&stringim[0]) adresidir

    printf("1. karakter: %c\n", *ptr);        // r
    printf("2. karakter: %c\n", *(ptr + 1));  // u (adresi 1 birim kaydır)
    printf("5. karakter: %c\n", *(ptr + 4));  // s (adresi 4 birim kaydır)

    return 0;
}
