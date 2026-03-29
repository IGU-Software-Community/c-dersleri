// Kaynak: Pointers3.pdf - Sayfa 6-7
// Amacı: Dizilerin fonksiyonlara nasıl adres (pointer) olarak gönderildiğini göstermek.
#include <stdio.h>

double ortalama(double dizi[], int n) {
    double *p, t = 0.0;
    p = dizi; // Dizinin başlangıç adresi pointer'a atandı

    for(int i = 0; i < n; i++) {
        t += *(p + i); // dizi[i] yazmak yerine *(p+i) ile erişiyoruz
    }
    return (t / n);
}

int main() {
    double a[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double o = ortalama(a, 5); // a dizisinin başlangıç adresi yollanıyor
    printf("Dizinin ortalamasi = %lf\n", o);
    return 0;
}
