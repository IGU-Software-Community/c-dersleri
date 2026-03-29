#include <stdio.h>

// Dizinin başlangıç adresini ve boyutunu alan fonksiyon
void tersCevir(int *ptr, int boyut) {
    int *baslangic = ptr;               // Dizinin ilk elemanının adresi
    int *bitis = ptr + boyut - 1;       // Dizinin son elemanının adresi
    int gecici;

    // Başlangıç adresi, bitiş adresini geçene kadar döngü devam eder
    while (baslangic < bitis) {
        // Uçlardaki değerleri takas et (Swap)
        gecici = *baslangic;
        *baslangic = *bitis;
        *bitis = gecici;

        // İşaretçileri birbirine doğru yaklaştır
        baslangic++;
        bitis--;
    }
}

int main() {
    int sayilar[] = {10, 20, 30, 40, 50};
    int boyut = 5;

    // Dizinin adı zaten ilk elemanın adresidir, doğrudan gönderiyoruz
    tersCevir(sayilar, boyut);

    printf("Ters cevrilmis dizi: ");
    for (int i = 0; i < boyut; i++) {
        // İşaretçi aritmetiği ile yazdırma
        printf("%d ", *(sayilar + i));
    }

    return 0;
}
