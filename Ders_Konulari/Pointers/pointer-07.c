#include <stdio.h>

int main() {
    // 1. DEĞER (x)
    int x = 13;
    printf("x (deger): %d\n", x);

    // 2. ADRES (&x)
    printf("&x (adres): %p\n", &x);

    // 3. POINTER (adres tutar)
    int *p = &x;
    printf("p (adres tutar): %p\n", p);

    // 4. ADRESTEKİ DEĞER (*p)
    printf("*p (adresteki deger): %d\n", *p);

    // 5. DEĞERİ DEĞİŞTİRME
    *p = 42;  // x'in olduğu adrese 42 yaz

    printf("\nx yeni deger: %d\n", x);
    printf("*p ile okunan: %d\n", *p);

    return 0;
}
