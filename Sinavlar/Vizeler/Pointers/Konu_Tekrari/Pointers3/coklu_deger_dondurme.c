#include <stdio.h>

/*
 * C'de 'return' sadece 1 şey döndürebilir.
 * Ama bizden bir dizinin hem en küçüğünü, hem en büyüğünü, hem de ortalamasını
 * tek fonksiyonda bulmamız istenirse ne yaparız?
 * Çözüm: Sonuçları yazacağımız değişkenlerin ADRESLERİNİ parametre olarak alırız.
 */
void istatistikCikar(double *dizi, int boyut, double *enK, double *enB, double *ort) {
    // Başlangıçta en küçük ve en büyük değeri dizinin ilk elemanı kabul ediyoruz
    *enK = *dizi;
    *enB = *dizi;
    double toplam = 0.0;

    for (int i = 0; i < boyut; i++) {
        double anlikDeger = *(dizi + i); // İşaretçi aritmetiği ile değere ulaş

        toplam += anlikDeger;

        // Bulunan değer, şu anki en küçükten daha mı küçük?
        if (anlikDeger < *enK) {
            *enK = anlikDeger; // Ana programdaki degiskeni GÜNCELLE
        }
        // Bulunan değer, şu anki en büyükten daha mı büyük?
        if (anlikDeger > *enB) {
            *enB = anlikDeger; // Ana programdaki degiskeni GÜNCELLE
        }
    }
    // Toplamı boyuta böl ve ana programdaki ortalama değişkeninin içine yaz
    *ort = toplam / boyut;
}

int main() {
    double sicakliklar[] = {22.5, 18.0, 30.5, 14.2, 26.8};
    double minS, maxS, ortalamaS;

    // Dizinin kendisini (adresini) ve sonuçların yazılacağı değişkenlerin ADRESLERİNİ yolluyoruz
    istatistikCikar(sicakliklar, 5, &minS, &maxS, &ortalamaS);

    // Fonksiyon 'void' olmasına rağmen, adreslere müdahale ettiği için değişkenlerimiz doldu!
    printf("En Dusuk Sicaklik  : %.2lf\n", minS);
    printf("En Yuksek Sicaklik : %.2lf\n", maxS);
    printf("Ortalama Sicaklik  : %.2lf\n", ortalamaS);

    return 0;
}
