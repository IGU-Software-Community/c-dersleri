/* * Kaynak: Pointers2.pdf - Sayfa 7
 * Konu: İşaretçi Aritmetiği ve İçerik Manipülasyonu
 */
#include <stdio.h>

int main() {
    int x[5] = {1, 2, 3, 4, 5};
    int* ptr;

    ptr = &x[2]; // ptr, 3 rakamının olduğu adresi gösteriyor

    printf("*ptr = %d \n", *ptr);         // 3
    printf("*ptr + 1 = %d \n", *ptr + 1); // 3 + 1 = 4 (adresteki değere 1 ekler)
    printf("*ptr - 1 = %d", *ptr - 1);    // 3 - 1 = 2 (adresteki değerden 1 çıkarır)

    return 0;
}
