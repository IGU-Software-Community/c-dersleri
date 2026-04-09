// Kaynak: Pointers5.pdf - Sayfa 4-18
// Amaci: malloc ve calloc arasindaki temel farki gostermek.
//        malloc: bellek ayirir ama icerik cop veri olarak kalir, kendin sifirlamalisin.
//        calloc: bellek ayirir VE tum elemanlari otomatik 0 yapar.
// Ornek Cikti: Her iki yontemde de 15 elemanin hepsi 0 olarak yazdirilir.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p_malloc, *p_calloc;
    int i;

    // ============================================================
    // YONTEM 1: malloc ile bellek ayirma (elle sifirlama gerekir)
    // ============================================================
    printf("--- malloc ile 15 elemanlik dizi ---\n");

    // malloc: tek parametre alir (toplam byte miktari)
    p_malloc = (int *) malloc(sizeof(int) * 15);

    if (p_malloc == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }

    // malloc cop veri birakir, kendimiz sifirlamamiz lazim
    for (i = 0; i < 15; i++) {
        p_malloc[i] = 0;  // Bu satir olmadan elemanlar rastgele degerler icerir
        printf("Ayrilan Bolgenin %d. Elemani ---> %d\n", i + 1, p_malloc[i]);
    }

    // Isimiz bittikten sonra mutlaka ozgur birakiyoruz
    free(p_malloc);
    p_malloc = NULL;  // Dangling pointer'i onlemek icin iyi bir aliskanlik

    // ============================================================
    // YONTEM 2: calloc ile bellek ayirma (otomatik sifirlama)
    // ============================================================
    printf("\n--- calloc ile 15 elemanlik dizi ---\n");

    // calloc: iki parametre alir (eleman sayisi, her elemanin boyutu)
    // calloc arka planda malloc'u kullanir, ardindan ayrilan bolgeyi sifirlar
    p_calloc = (int *) calloc(15, sizeof(int));

    if (p_calloc == NULL) {
        printf("Hata: Bellek yetersiz!\n");
        return 1;
    }

    // calloc sayesinde p[i] zaten 0 oldugu icin direkt yazdirabiliriz
    for (i = 0; i < 15; i++) {
        // Dikkat: burada p_calloc[i] = 0; yazmaya GEREK YOK
        printf("Ayrilan Bolgenin %d. Elemani ---> %d\n", i + 1, p_calloc[i]);
    }

    // Bellegi serbest birakma
    free(p_calloc);
    p_calloc = NULL;

    // ============================================================
    // OZET:
    // malloc(n * sizeof(int))    -> n elemanlik yer ayir, cop veri kalir
    // calloc(n, sizeof(int))     -> n elemanlik yer ayir, hepsi 0 olur
    //
    // Ne zaman hangisi?
    // - Elemanlari hemen kendin dolduracaksan -> malloc yeterli
    // - Elemanlarin 0 ile baslamasi gerekiyorsa -> calloc daha guvenli
    // ============================================================

    printf("\nProgram bitti.\n");
    return 0;
}
