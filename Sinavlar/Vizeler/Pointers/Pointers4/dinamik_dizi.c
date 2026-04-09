// Kaynak: Pointers4.pdf - Sayfa 36-38
// Amaci: Kullanicidan boyut alarak dinamik dizi olusturma.
//        malloc ile yer ayirma, diziyi doldurma, yazdirma ve free ile iade.
//        Pointer gosterimi ile dizi erisimi de gosterilir.
// Ornek Cikti: 4 eleman girilir -> 3 7 2 9 yazdirilir -> Bellek bosaltilir
#include <stdio.h>
#include <stdlib.h>  // malloc ve free icin sart!

int main()
{
    int n, i;
    int *dizi;  // 1. Bir isaretci tanimliyoruz (Henuz veri yok)

    printf("Kac adet sayi girmek istiyorsunuz? ");
    scanf("%d", &n);

    // 2. RAM'den (Heap bolgesi) yer istiyoruz
    // (int*) ile gelen adresi tam sayi adresine donusturuyoruz
    dizi = (int *) malloc(n * sizeof(int));

    // 3. Guvenlik Kontrolu (Hafiza dolmus olabilir mi?)
    if (dizi == NULL) {
        printf("Hata: Bilgisayarda yeterli bellek yok!\n");
        return 1;
    }

    printf("Dizi adresi (malloc sonrasi): %p\n", (void *)dizi);

    // 4. Diziyi normal bir dizimis gibi kullaniyoruz
    // dizi[i] ile erisim, arka planda *(dizi+i) olarak calisir
    for (i = 0; i < n; i++) {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &dizi[i]);  // Isaretci aritmetigi arka planda calisir
    }

    // 5. Girilenleri yazdiralim
    printf("\n--- Girdiginiz Sayilar ---\n");
    for (i = 0; i < n; i++) {
        // Farklilik olsun diye pointer gosterimi kullaniyoruz
        // *(dizi + i) ile dizi[i] tamamen ayni sonucu verir
        printf("%d ", *(dizi + i));
    }

    // 6. EN KRITIK ADIM: Bellegi iade ediyoruz
    free(dizi);
    dizi = NULL;  // Guvenlik icin isaretciyi bosa cikariyoruz

    printf("\nDizi adresi (free sonrasi): %p\n", (void *)dizi);  // 0x0 (NULL) olmali
    printf("\nBellek basariyla bosaltildi.\n");

    return 0;
}
