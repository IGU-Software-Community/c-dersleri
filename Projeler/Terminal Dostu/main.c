// gerekli kutuphaneleri indiriyor
#include <stdio.h>

// ana fonksiyonun basi
int main()
{
    // degiskenler olusturuldu
    int secim, sayi1, sayi2, sonuc;

    // menu ekrana gosterildi
    printf("MENU\n");
    printf("====\n");
    printf("1) +\n");
    printf("2) -\n");
    printf("3) *\n");
    printf("4) /\n");

    // kullanicidan menu numarasini istiyor ve aliyor
    printf("Secim: ");
    scanf("%d", &secim);

    // kullanicidan sayi 1 degeri istiyor ve aliyor
    printf("\nsayi 1: ");
    scanf("%d", &sayi1);

    // kullanicidan sayi 2 degeri istiyor ve aliyor
    printf("\nsayi 2: ");
    scanf("%d", &sayi2);

    // secilen menu numarasina gore kontrol yapiyor
    if (secim==1) {
        // kullanicidan alinan 2 sayiyi topluyor ve degiskene atiyor
        sonuc=sayi1+sayi2;
        // sonucu ekrana gosteriyor
        printf("\n+ islemin sonucu: %d + %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==2) {
        // kullanicidan alinan 2 sayiyi topluyor ve degiskene atiyor
        sonuc=sayi1-sayi2;
        // sonucu ekrana gosteriyor
        printf("\n- islemin sonucu: %d - %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==3) {
        // kullanicidan alinan 2 sayiyi topluyor ve degiskene atiyor
        sonuc=sayi1*sayi2;
        // sonucu ekrana gosteriyor
        printf("\n* islemin sonucu: %d * %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==4) {
        // kullanicidan alinan 2 sayiyi topluyor ve degiskene atiyor
        sonuc=sayi1/sayi2;
        // sonucu ekrana gosteriyor
        printf("\n/ islemin sonucu: %d / %d = %d\n\n", sayi1, sayi2, sonuc);
    } else {
        // hata mesajini ekrana gosteriyor
        printf("\t\nBir sorun olustu\n\n");
    }

    // programi sonlandiriyor
    return 0;
}
