// Kaynak: Pointers4.pdf - Sayfa 27-35
// Amaci: malloc() fonksiyonunun temel kullanimi.
//        sizeof ile platform-bagimsiz bellek ayirma,
//        (int*) tur donusumu ve NULL kontrolu gosterilir.
// Not: stdlib.h dahil edilmezse malloc/free kullanilamaz.
#include <stdio.h>
#include <stdlib.h>  // malloc ve free icin sart!

int main()
{
    int *p;

    // --- Temel malloc Kullanimi ---
    // malloc(boyut) -> bellekten 'boyut' byte kadar yer ayirir.
    // Basarili olursa ayrilan alanin baslangic adresini dondurur.
    // Basarisiz olursa NULL (0) dondurur.

    // YANLIS KULLANIM (platformlar arasi sorun):
    // p = malloc(5);
    // Bu 5 BYTE ayirir, 5 ELEMAN degil!
    // int 4 byte ise -> 1 eleman + 1 byte bos (anlamsiz)
    // int 2 byte ise -> 2 eleman + 1 byte bos
    // Sonuc: Sistemden sisteme farkli davranir.

    // DOGRU KULLANIM:
    // sizeof(int) ile her sistemde 5 elemanlik garanti blok ayrılır.
    // (int*) tur donusumu ile void* -> int* cevrimi yapilir.
    p = (int *) malloc(sizeof(int) * 5);

    // --- NULL Kontrolu (Zorunlu!) ---
    // Bellek her zaman ayrilabilir degil. RAM doluysa NULL doner.
    // Bu kontrol yapilmazsa, NULL pointer'a yazma girisimi
    // programi cokerterir (Segmentation Fault).
    if (p == NULL) {
        printf("Hata: Bellekten yer ayrilamadi!\n");
        return 1;  // Hata kodu ile cik
    }

    printf("Bellek basariyla ayrildi!\n");
    printf("Ayrilan alan adresi: %p\n", (void *)p);
    printf("Ayrilan alan boyutu: %d eleman x %lu byte = %lu byte\n",
           5, sizeof(int), 5 * sizeof(int));

    // Ayrilan alani kullan
    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;

    // Pointer gosterimi ile elemanlara erisim (dizi indeksi ile ayni sonuc)
    printf("\nElemanlar (pointer gosterimi):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(p+%d) = %d  (adres: %p)\n", i, *(p + i), (void *)(p + i));
    }

    // --- Bellek Iadesi ---
    // malloc ile alinan her alan free ile iade edilmelidir.
    // C'de Garbage Collector yoktur; bu senin sorumlulugun.
    free(p);
    p = NULL;  // Dangling pointer'i onle: artik eski adresi gostermesin

    printf("\nBellek basariyla iade edildi.\n");

    // --- Statik vs Dinamik Karsilastirma ---
    // Statik:  int dizi[1000000000]; -> Stack tasma, program coker
    // Dinamik: malloc(...) -> Basarisiz olursa NULL doner, programi kurtarabilirsin
    //
    // Restoran benzetmesi (PDF'ten):
    // Statik  = Onceden rezervasyon yapilmis masa; gidince oturursun ya da kapalidir.
    // Dinamik = Kapidan girip "bos masa var mi?" diye sormak.
    // NULL kontrolu yapmazsan olmayan masaya oturmaya calisip yere dusersin.

    return 0;
}
