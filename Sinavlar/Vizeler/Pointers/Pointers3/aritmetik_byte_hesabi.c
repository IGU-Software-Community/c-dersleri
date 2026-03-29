// Kaynak: Pointers3.pdf - Sayfa 2-3
// Amacı: Farklı türlerdeki işaretçilerin bellekte kaçar bayt atladığını ispatlamak.
#include <stdio.h>

int main() {
    char k = 'a', *pk = &k;
    int t = 22, *pt = &t;
    double g = 5.5, *pg = &g;

    printf("Onceki adresler: pk= %p pt= %p pg= %p \n", pk, pt, pg);

    pk++;           // char olduğu için adresi sadece 1 bayt ileri taşır
    pt--;          // int olduğu için adresi 4 bayt geri taşır
    pg = pg + 10; // double olduğu için adresi 80 bayt (10 * 8) ileri taşır

    printf("Sonraki adresler: pk= %p pt= %p pg= %p \n", pk, pt, pg);
    return 0;
}
