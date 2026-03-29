#include <stdio.h>

/*
 * Fonksiyon tipi 'int*' (integer pointer).
 * Yani bu fonksiyon işi bittiğinde geriye bir tam sayı değil,
 * o tam sayının bellekteki ev adresini döndürecek.
 */
int* degerAra(int *dizi, int boyut, int aranan) {
    for (int i = 0; i < boyut; i++) {
        if (*(dizi + i) == aranan) {
            // Eğer arananı bulursan, o elemanın ADRESİNİ döndür
            return (dizi + i);
        }
    }
    // Bulunamazsa 'Boş İşaretçi' (NULL) döndür. Sınavda NULL kontrolü puan getirir.
    return NULL;
}

int main() {
    int sayilar[] = {10, 25, 42, 56, 89, 102};
    int boyut = 6;
    int arananDeger = 56;

    // Dönen adresi tutması için bir pointer tanımlıyoruz
    int *bulunanAdres = degerAra(sayilar, boyut, arananDeger);

    if (bulunanAdres != NULL) {
        printf("Aranan %d degeri bellekte %p adresinde bulundu.\n", arananDeger, bulunanAdres);

        /* * VİZE KRİTİK NOKTASI (İşaretçi Çıkarma İşlemi)
         * İki adres birbirinden çıkarıldığında sonuç "byte" farkı değil,
         * aradaki "eleman sayısı" (indeks) olarak döner.
         * Formül: (Hedef Adres - Başlangıç Adresi)
         */
        int indeks = bulunanAdres - sayilar;
        printf("Bu deger dizinin %d. indeksinde yer aliyor.\n", indeks);
    } else {
        printf("Deger dizide bulunamadi.\n");
    }

    return 0;
}
