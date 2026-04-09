// Kaynak: Pointers5.pdf - Sayfa 10-14
// Amaci: Dangling pointer kavramini gostermek.
//        free() sonrasi p = NULL yapilmazsa pointer hala eski adresi gosterir.
//        p = NULL yapilirsa pointer guvenlice sifirlanir.
//
// UYARI: Bu kodda free sonrasi *p erisimi TANIMLANMAMIS DAVRANIS icerir.
//        Gercek programlarda bunu ASLA yapmayin. Burada sadece ogretim amaclidir.
//
// Otel Benzetmesi:
//   free(p)    = Anahtari resepsiyona verdim (oda bosaltildi)
//   p hala &x  = Ama oda numarasini hala biliyorum
//   *p         = Odaya girmeye calistim -> baskasinin esyalari veya guvenlik cokertir
//   p = NULL   = Oda numarasini hafizamdan sildim, artik gitmeye calismam
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ============================================================
    // SENARYO 1: free sonrasi p = NULL YAPILMADI (TEHLIKELI!)
    // ============================================================
    printf("--- Senaryo 1: p = NULL yapilmadi ---\n");

    int *p = (int *) malloc(sizeof(int));
    if (p == NULL) { printf("Bellek ayrilamadi!\n"); return 1; }

    *p = 58;
    printf("*p = %d\n", *p);
    printf("p'nin adresi = %p\n\n", (void *)p);

    free(p);  // Serbest biraktik
    printf("Bellek alani serbest birakildi!\n\n");

    // DIKKAT: p = NULL yapmadik!
    // p hala eski adresi tutuyor ama o adres artik gecersiz.
    // Asagidaki satir TANIMLANMAMIS DAVRANIS: bazen calisir, bazen cokerter.
    // printf("Hala oradayim: %d\n", *p);  // <- BU SATIRI ACMAYIN!
    // printf("p'nin adresi = %p\n\n", (void *)p);  // Adres hala ayni gorunur

    // GCC uyarisini bastir: bu kullanim kasitli ve ogretim amaclidir
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuse-after-free"
    printf("(!) p hala eski adresi tutuyor: %p\n", (void *)p);
#pragma GCC diagnostic pop
    printf("(!) Ama bu adres artik gecersiz (dangling pointer)!\n\n");

    // ============================================================
    // SENARYO 2: free sonrasi p = NULL YAPILDI (GUVENLI)
    // ============================================================
    printf("--- Senaryo 2: p = NULL yapildi ---\n");

    int *q = (int *) malloc(sizeof(int));
    if (q == NULL) { printf("Bellek ayrilamadi!\n"); return 1; }

    *q = 58;
    printf("*q = %d\n", *q);
    printf("q'nun adresi = %p\n\n", (void *)q);

    free(q);
    q = NULL;  // Pointer'i guvenlice sifirla
    printf("Bellek serbest birakildi ve q = NULL yapildi.\n");
    printf("q'nun adresi = %p (NULL = 0 adresi)\n\n", (void *)q);

    // Artik *q dersek program KESIN coker (Access Violation / Segfault)
    // Bu aslinda iyi bir sey: belirsiz bir cokme yerine kesin bir hata alirsin.
    // Hata ayiklama (debugging) cok daha kolay olur.
    //
    // NULL adresi (0), isletim sistemi tarafindan rezerve edilmis "yasakli" bir bolgedir.
    // Islemci bu adrese gitmeye calistiginda isletim sistemi programi sonlandirir.
    // Windows: 0xC0000005 (Access Violation)
    // Linux:   Segmentation Fault (SIGSEGV)

    printf("Ozet:\n");
    printf("  free(p);          -> Bellegi iade et\n");
    printf("  p = NULL;         -> Pointer'i guvenli hale getir\n");
    printf("  Bu ikisini her zaman birlikte yap!\n");

    return 0;
}
