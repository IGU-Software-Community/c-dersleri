#include <stdio.h>

int main() {
    // 1. Değişkenlerin ve İşaretçilerin Tanımlanması
    int a, b;
    int *p = &a, *q = &b;

    // 2. Kullanıcıdan Veri Girişi
    printf("2 sayi gir: ");
    scanf("%d %d", p, q);

    // 3. İşlem ve Çıktı
    printf("Toplam: %d\n", *p + *q);

    return 0;
}
