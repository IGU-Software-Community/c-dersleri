#include <stdio.h>
#include <stdlib.h>

/*
 * SINAV UYARISI: Siralama algoritmasini kağıt üzerinde
 * adım adım takip edin. Her karşılaştırmadan sonra
 * dizinin güncel durumunu yazın.
 *
 * SORU: Aşağıdaki 4 elemanlı dizi Selection Sort ile
 *       sıralandığında, kaç kez swap yapılır?
 *       Her swap sonrası dizinin durumu nedir?
 */

int main() {
    int a[] = {7, 2, 9, 1};
    int n = 4;
    int i, j, tmp;

    printf("Baslangic: ");
    for (i = 0; i < n; i++) printf("%d ", *(a + i));
    printf("\n\n");

    for (i = 0; i < (n - 1); i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    printf("Sonuc: ");
    for (i = 0; i < n; i++) printf("%d ", *(a + i));
    printf("\n");

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * Baslangic: 7 2 9 1
 *
 * === Dis Dongu i=0 ===
 *   j=1: *(a+0)=7 > *(a+1)=2 ? EVET -> swap -> [2, 7, 9, 1]
 *   j=2: *(a+0)=2 > *(a+2)=9 ? HAYIR
 *   j=3: *(a+0)=2 > *(a+3)=1 ? EVET -> swap -> [1, 7, 9, 2]
 *
 * === Dis Dongu i=1 ===
 *   j=2: *(a+1)=7 > *(a+2)=9 ? HAYIR
 *   j=3: *(a+1)=7 > *(a+3)=2 ? EVET -> swap -> [1, 2, 9, 7]
 *
 * === Dis Dongu i=2 ===
 *   j=3: *(a+2)=9 > *(a+3)=7 ? EVET -> swap -> [1, 2, 7, 9]
 *
 * Toplam swap sayisi: 4
 *
 * Sonuc: 1 2 7 9
 *
 * SINAV NOTU:
 * *(a + i) ile a[i] AYNI SEYDIR.
 * scanf("%d", a + i) ile scanf("%d", &a[i]) AYNI SEYDIR.
 * a + i zaten bir adres oldugu icin & gerekmez.
 */
