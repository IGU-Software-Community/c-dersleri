#include <stdio.h>

int main() {
    // Karakter işaretçilerinden oluşan bir dizi (String dizisi)
    char *isimler[] = {"Ali", "Veli", "Ayse", "Fatma"};

    // Dizinin eleman sayısını hesaplama formülü
    int boyut = sizeof(isimler) / sizeof(isimler[0]);

    printf("Isimlerin ilk harfleri:\n");
    for (int i = 0; i < boyut; i++) {
        // isimler[i] -> O anki kelimenin başlangıç adresini verir
        // *isimler[i] -> O adresin içindeki İLK KARAKTERİ verir
        printf("%d. ismin ilk harfi: %c\n", i + 1, *isimler[i]);
    }

    printf("\nBellek adresleri:\n");
    for (int i = 0; i < boyut; i++) {
        // Her bir kelimenin bellekte başladığı adresi yazdırıyoruz
        printf("%s kelimesinin adresi: %p\n", isimler[i], isimler[i]);
    }

    return 0;
}
