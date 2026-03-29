// Kaynak: Pointers3.pdf - Sayfa 17-18
// Amacı: İşaretçilerin en güçlü olduğu yer; iki değişkeni kalıcı takas etme.
#include <stdio.h>

void swap(int *px, int *py) {
    int temp = *px; // px'in gösterdiği adresteki değeri yedeğe al
    *px = *py;      // py'nin içindeki değeri px'in adresine yaz
    *py = temp;     // yedeği py'nin adresine yaz
}

int main() {
    int x = 5, y = 8;

    printf("Swap oncesi main icinde x: %d, y: %d\n", x, y);
    swap(&x, &y); // Değişkenlerin ev adreslerini (referans) yolluyoruz
    printf("Swap sonrasi main icinde x: %d, y: %d\n", x, y); // x:8, y:5 oldu

    return 0;
}
