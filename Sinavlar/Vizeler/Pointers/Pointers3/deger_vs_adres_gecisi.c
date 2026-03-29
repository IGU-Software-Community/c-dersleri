// Kaynak: Pointers3.pdf - Sayfa 12-14
// Amacı: Pass by Value ve Pass by Reference arasındaki kalıcılık farkını kanıtlamak.
#include <stdio.h>

// Değer geçerek aktarım (Kopya gelir, aslı değişmez)
void f1(int n) {
    n = 66;
}

// Adres geçerek aktarım (Gerçek adres gelir, aslı değişir)
void f2(int *n) {
    *n = 77;
}

int main() {
    int x = 55;

    f1(x);
    printf("f1(x) cagirildiktan sonra x: %d\n", x); // x hala 55 kalır

    f2(&x);
    printf("f2(&x) cagirildiktan sonra x: %d\n", x); // x kalıcı olarak 77 oldu

    return 0;
}
