#include <stdio.h>
#include <stdlib.h>

/*
 * SINAV UYARISI: Kağıt üzerinde bellek tablosu çizin.
 * malloc ile ayrılan alanın adreslerini varsayımsal olarak
 * 1000, 1004, 1008, ... şeklinde yazın.
 * Her adımda p'nin ve dizi elemanlarının değerlerini takip edin.
 *
 * SORU: Programın çıktısı nedir?
 */

void faktoriyel(int n, long long *sonuc) {
    *sonuc = 1;
    for (int i = 1; i <= n; i++)
        *sonuc = *sonuc * i;
}

int main() {
    int *dizi = (int *) malloc(4 * sizeof(int));
    if (dizi == NULL) return 1;

    // Diziyi pointer aritmetigi ile doldur
    *(dizi + 0) = 3;
    *(dizi + 1) = 5;
    *(dizi + 2) = 0;
    *(dizi + 3) = 4;

    // Soru 1: Bu donguden sonra toplam kac olur?
    int toplam = 0;
    int *p = dizi;
    for (int i = 0; i < 4; i++) {
        toplam += *p;
        p++;
    }
    printf("Toplam: %d\n", toplam);

    // Soru 2: p simdi nereyi gosteriyor?
    // p donguden sonra dizi+4 konumunda (dizinin DISINDA!)
    // p'yi geri baslangica cekelim
    p = dizi;

    // Soru 3: Her elemanin faktoriyelini hesapla
    long long f;
    for (int i = 0; i < 4; i++) {
        faktoriyel(*(p + i), &f);
        printf("%d! = %lld\n", *(p + i), f);
    }

    // Soru 4: dizi[2] = 0 idi, 0! kac eder?
    // İpucu: for(i=1; i<=0; i++) dongusune hic girilmez, *sonuc = 1 kalir.

    free(dizi);
    dizi = NULL;

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * dizi: | 3 | 5 | 0 | 4 |
 *         ^               ^
 *        dizi          p (dongu sonrasi, DISI!)
 *
 * Soru 1 - Toplam:
 *   3 + 5 + 0 + 4 = 12
 *   Cikti: Toplam: 12
 *
 * Soru 2 - p nereyi gosteriyor?
 *   Dongu 4 kez p++ yapti -> p = dizi + 4 (dizinin disinda!)
 *   p = dizi ile baslangica cektik.
 *
 * Soru 3 - Faktoriyeller:
 *   3! = 6       (1*2*3)
 *   5! = 120     (1*2*3*4*5)
 *   0! = 1       (donguye hic girilmez, *sonuc = 1 kalir)
 *   4! = 24      (1*2*3*4)
 *
 * Cikti:
 *   Toplam: 12
 *   3! = 6
 *   5! = 120
 *   0! = 1
 *   4! = 24
 */
