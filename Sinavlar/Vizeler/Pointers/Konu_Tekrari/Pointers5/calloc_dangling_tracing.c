#include <stdio.h>
#include <stdlib.h>

/*
 * SINAV UYARISI: Bu soruda malloc ve calloc'un ilk değer
 * davranışı sorulmaktadır. Kağıt üzerinde her adımda
 * dizinin elemanlarını ve pointer'ın gösterdiği adresi yazın.
 *
 * SORU: Programın çıktısı nedir?
 *       (malloc'un çöp veri değerleri sınavda genellikle 0 varsayılır
 *        veya "belirsiz" olarak kabul edilir. Biz burada elle 0 atıyoruz.)
 */

int main() {
    int i;

    // --- Bolum A: malloc ile 3 elemanlik dizi ---
    int *m = (int *) malloc(3 * sizeof(int));
    if (m == NULL) return 1;

    // malloc cop veri birakir, biz elle atama yapiyoruz
    m[0] = 10;
    m[1] = 20;
    // m[2]'ye hicbir deger ATAMADIK!
    // Sinavda bu eleman "belirsiz/cop" olarak kabul edilir.

    printf("--- malloc ---\n");
    printf("m[0]=%d, m[1]=%d\n", m[0], m[1]);
    // m[2] belirsiz oldugu icin yazdirmiyoruz

    // --- Bolum B: calloc ile 3 elemanlik dizi ---
    int *c = (int *) calloc(3, sizeof(int));
    if (c == NULL) { free(m); return 1; }

    // calloc otomatik 0 atar, hicbir sey yapmamiza gerek yok
    printf("\n--- calloc ---\n");
    for (i = 0; i < 3; i++) {
        printf("c[%d]=%d\n", i, c[i]);
    }

    // --- Bolum C: calloc dizisini degistir ve toplami bul ---
    c[0] = 5;
    c[2] = 15;
    // c[1] hala 0 (calloc'tan kaldi)

    int toplam = 0;
    int *p = c;
    for (i = 0; i < 3; i++) {
        toplam += *(p + i);
    }
    printf("\nToplam: %d\n", toplam);

    // --- Bolum D: free sonrasi ne olur? ---
    free(c);
    // c hala eski adresi tutuyor (dangling pointer!)
    // c = NULL; yapMADIK kasitli olarak.
    // Sinavda soru: "c'nin son durumu nedir?" -> Dangling pointer (tehlikeli)

    free(m);
    m = NULL;  // Dogru kullanim

    // Soru: m ve c'nin son durumu nedir?
    printf("\nm = %p (guvenli)\n", (void *)m);
    // c hala eski adresi gosteriyor ama o alan artik gecersiz

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * --- malloc ---
 * m[0]=10, m[1]=20
 * (m[2] belirsiz, cop veri)
 *
 * --- calloc ---
 * c[0]=0
 * c[1]=0
 * c[2]=0
 * (calloc hepsini otomatik 0 yapti)
 *
 * Bolum C:
 * c[0]=5, c[1]=0 (calloc'tan), c[2]=15
 * Toplam: 5 + 0 + 15 = 20
 * Cikti: Toplam: 20
 *
 * Bolum D:
 * m = (nil) veya 0x0  (NULL, guvenli)
 * c = 0x???????        (dangling pointer, TEHLIKELI!)
 *
 * SINAV NOTU: "free sonrasi p = NULL yapilmazsa ne olur?"
 * -> Pointer eski adresi tutar (dangling pointer).
 * -> O adresi kullanmaya calismak tanimlanmamis davranistir.
 * -> p = NULL yapilirsa, *p denemesi kesin hata verir (Access Violation),
 *    bu da aslinda daha iyidir cunku hatayi hemen yakalarsin.
 */
