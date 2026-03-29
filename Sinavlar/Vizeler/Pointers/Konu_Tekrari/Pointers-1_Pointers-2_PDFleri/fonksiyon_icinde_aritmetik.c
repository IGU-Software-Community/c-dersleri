#include <stdio.h>

void diziyiIsle(int *ptr, int elemanSayisi) {
    for (int i = 0; i < elemanSayisi; i++) {
        if (*ptr % 2 == 0) {
            // Eğer değer çiftse, adresteki DEĞERİ 1 arttır
            (*ptr)++;
        }
        // İşlem bittikten sonra ADRESİ bir sonraki hücreye kaydır
        ptr++;
    }
}

int main() {
    int dizi[4] = {2, 5, 8, 11};

    diziyiIsle(dizi, 4);

    printf("Islem sonrasi dizi: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", dizi[i]);
    }
    // Beklenen Çıktı: 3 5 9 11 (Sadece çift sayılar tek sayı oldu)
    return 0;
}
