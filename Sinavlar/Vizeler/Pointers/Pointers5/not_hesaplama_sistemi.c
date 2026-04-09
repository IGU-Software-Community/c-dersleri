// Kaynak: Pointers5.pdf - Sayfa 30-38
// Amaci: Tum dinamik bellek kavramlarini birlestiren kapsamli uygulama.
//        malloc ile baslangic tahsisi, realloc ile guvenli genisletme,
//        while(1) sonsuz dongusu, scanf dogrulama, tampon temizleme,
//        pointer aritmetigi ve free ile bellek iadesi.
// Ornek Cikti:
//   Notlar: 6, 4, 8, 3 -> Toplam: 21.00, Ortalama: 5.25
//   Ilk giriste -1 -> "Hic not girilmedigi icin hesaplama yapilamadi."
//   Gecersiz giris (harf) -> "Lutfen sadece tam sayi giriniz!"
//   Aralik disi (-5 veya 101) -> "Gecersiz not! (0-100 arasinda olmalidir)."
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *notlar = NULL;    // Bu bir sayi degil, bir bellek adresidir!
    int *temp = NULL;      // realloc icin gecici pointer (veri kaybi onlemi)
    int i = 0, girilen_not;
    double toplam = 0.0;
    double ort = 0.0;

    // 1. Baslangic Bellek Tahsisi
    // Sadece 1 elemanlik yer aciyoruz, ileride realloc ile buyutecegiz
    notlar = (int *) malloc(sizeof(int));
    if (notlar == NULL) {
        printf("Kritik Hata: Baslangic bellegi ayrilamadi!\n");
        return 1;
    }

    printf("--- Not Hesaplama Sistemi ---\n");
    printf("Notlari giriniz (Bitirmek icin -1 yazin):\n");

    // 2. Dinamik Veri Giris Dongusu
    while (1) {
        printf("%d. Not: ", i + 1);

        // Giris Kontrolu (Sayi mi girildi?)
        // scanf basarili okuma yaparsa 1 dondurur
        // Harf girilirse 0 dondurur
        if (scanf("%d", &girilen_not) != 1) {
            printf("Hata: Lutfen sadece tam sayi giriniz!\n");
            // Yanlis girisi temizlemek icin tamponu bosaltiyoruz
            // getchar() tampondaki karakterleri tek tek okuyup atiyor
            while (getchar() != '\n');
            continue;  // Dongunun basina don, i artmaz
        }

        // Cikis Kontrolu
        if (girilen_not == -1) break;

        // Negatif sayi (durma sinyali haric) veya 100'den buyuk sayi kontrolu
        if (girilen_not < 0 || girilen_not > 100) {
            printf("Hata: Gecersiz not! (Notlar 0-100 arasinda olmalidir).\n");
            continue;  // Bu turu atla, toplama ekleme, bellegi buyutme
        }

        // Gecerli notu isle
        toplam += girilen_not;
        *(notlar + i) = girilen_not;  // Pointer aritmetigi kullanimi
        i++;

        // 3. GUVENLI BELLEK GENISLETME (realloc + temp)
        // i+1 tane yer ayiriyoruz ki bir sonraki dongude yer kalsin
        //
        // NEDEN temp kullaniyoruz?
        // Eger realloc basarisiz olursa NULL dondurur.
        // Dogrudan notlar = realloc(notlar, ...) yazsaydik,
        // notlar'in eski adresi kaybolur ve veriler erisilemez olurdu.
        // temp ile eski veriyi koruyoruz.
        temp = (int *) realloc(notlar, (i + 1) * sizeof(int));

        if (temp == NULL) {
            printf("\nUyari: Bellek doldu! Girilen %d not ile isleme devam ediliyor.\n", i);
            break;
        }
        notlar = temp;  // Basariyla genisletildiyse adresi guncelle
    }

    // 4. Hesaplama ve Sonuc Ekrani
    printf("\n------------------------------\n");
    if (i > 0) {
        ort = toplam / i;  // toplam double oldugu icin hassas bolme yapar
        printf("Girilen Not Sayisi : %d\n", i);
        printf("Notlarin Toplami   : %.2f\n", toplam);
        printf("Sinif Ortalamasi   : %.2f\n", ort);
    } else {
        printf("Hic not girilmedigi icin hesaplama yapilamadi.\n");
    }
    printf("------------------------------\n");

    // 5. Bellek Temizligi
    free(notlar);
    notlar = NULL;  // Dangling pointer onlemi

    return 0;
}
