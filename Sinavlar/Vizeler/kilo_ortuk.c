/* * Kaynak: pointers.pdf - Sayfa 20
 * Konu: Örtük (Implicit) Adresleme
 */
#include <stdio.h>

int main() {
    float kilo;
    kilo = 58; // Bilgisayar bu değeri arka planda bir adrese koyar

    // Değer doğrudan değişken ismiyle çağrılır
    printf("kilo degiskeninde saklanan sayi = %f\n", kilo);

    return 0;
}
