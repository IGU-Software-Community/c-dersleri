// Kaynak: Pointers4.pdf - Sayfa 1
// Amaci: Uc sayiyi pointer ile kucukten buyuge siralama.
//        Swap fonksiyonu adres alarak orijinal degerleri kalici degistirir.
// Ornek Cikti: 8 5 2 -> Sirali: 2 5 8
#include <stdio.h>

// Fonksiyon prototipi: iki int adresini alir, iceriklerini takas eder
void degerdegistir(int *a, int *b);

int main()
{
    int x, y, z;

    printf("Lutfen X Degerini Giriniz:");
    scanf("%d", &x);
    printf("Lutfen Y Degerini Giriniz:");
    scanf("%d", &y);
    printf("Lutfen Z Degerini Giriniz:");
    scanf("%d", &z);

    printf("Sirasiz Degerler:%d %d %d\n", x, y, z);

    // Siralama mantigi: en buyugu sona at, sonra ortayi duzelt
    // 1. x ve y'yi karsilastir
    if (x > y)
        degerdegistir(&x, &y);  // &x gondererek main'deki x'i kalici degistiriyoruz

    // 2. x ve z'yi karsilastir (en kucugu x'e gelsin)
    if (x > z)
        degerdegistir(&x, &z);

    // 3. y ve z'yi karsilastir (ortancayi y'ye, en buyugu z'ye koy)
    if (y > z)
        degerdegistir(&y, &z);

    printf("Sirali Degerler:%d %d %d\n", x, y, z);

    return 0;
}

// Gecici degisken ile iki adresteki degerleri takas et
void degerdegistir(int *a, int *b)
{
    int gecici;
    gecici = *a;   // a'nin gosterdigi adresteki degeri yedegle
    *a = *b;       // b'nin degerini a'nin adresine yaz
    *b = gecici;   // yedeglenen degeri b'nin adresine yaz
}
