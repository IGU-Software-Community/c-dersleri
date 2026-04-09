// Kaynak: Pointers5.pdf - Sayfa 19-23
// Amaci: Kullanicidan eleman sayisi alarak calloc ile dinamik dizi olusturma.
//        scanf dogrulama (negatif sayi kontrolu) ve elemanlarinin 0 oldugunu gosterme.
// Ornek Cikti:
//   Eleman sayisi: 5 -> 5 eleman hepsi 0
//   Eleman sayisi: -4 -> "Gecersiz sayi girdiniz!"
#include <stdio.h>
#include <stdlib.h>  // malloc/calloc/free icin sart

int main(void)
{
    int *dizi;
    int eleman_sayisi;
    int i;

    printf("Eleman sayisini giriniz: ");

    // scanf dogrulama: scanf basarili okuma yaparsa 1 dondurur
    // Eger harf girilirse veya negatif sayi girilirse hata ver
    if (scanf("%d", &eleman_sayisi) != 1 || eleman_sayisi < 0) {
        printf("Gecersiz sayi girdiniz!\n");
        return 1;
    }

    // Bellek tahsisi ve tip donusumu
    // calloc(eleman_sayisi, sizeof(int)):
    //   1. parametre: kac eleman
    //   2. parametre: her elemanin boyutu
    // calloc tum elemanlari otomatik 0 yapar
    dizi = (int *) calloc(eleman_sayisi, sizeof(int));

    if (dizi == NULL) {
        printf("Hata: Yetersiz bellek!\n");
        return 1;
    }

    printf("Dizi elemanlari su sekildedir:\n");
    for (i = 0; i < eleman_sayisi; i++) {
        // calloc kullandigimiz icin hepsi otomatik 0'dir
        printf("%d. eleman: %d\n", i + 1, dizi[i]);
    }

    // Programin sonunda temizlik
    free(dizi);
    dizi = NULL;

    return 0;
}
