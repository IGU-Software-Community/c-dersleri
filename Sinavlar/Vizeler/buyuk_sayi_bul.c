/* * Kaynak: Pointers2.pdf - Sayfa 13
 * Konu: İşaretçilerle Karşılaştırma (If-Else)
 */
#include <stdio.h>

int main() {
    int n1, n2, *p1 = &n1, *p2 = &n2;

    printf("Iki sayi girin: ");
    // scanf içinde & kullanmaya gerek yok çünkü p1 zaten bir adres
    scanf("%d %d", p1, p2);

    if (*p1 > *p2)
        printf("Buyuk olan: %d\n", *p1);
    else
        printf("Buyuk olan: %d\n", *p2);

    return 0;
}
