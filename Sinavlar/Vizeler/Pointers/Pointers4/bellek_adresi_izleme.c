// Kaynak: Pointers4.pdf - Sayfa 44-45
// Amaci: Stack (statik) ve Heap (dinamik) bellek adreslerinin
//        farkli bolgelerde oldugunu gostermek.
//        Stack adresi yuksek, Heap adresi dusuk bolgede yer alir.
// Ornek Cikti:
//   Stack Adresi (Yerel): 00000000061FE44  (yuksek adres)
//   Heap Adresi (Dinamik): 0000000000A21470 (dusuk adres)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int yerel_degisken = 10;         // STACK'te (Statik) yer alir
    int *dinamik_alan;               // Isaretcinin kendisi STACK'te

    dinamik_alan = (int *) malloc(sizeof(int));  // Ayrilan yer HEAP'te

    if (dinamik_alan == NULL) {
        printf("Hata: Bellek ayrilamadi!\n");
        return 1;
    }

    printf("--- Bellek Adresi Karsilastirmasi ---\n\n");
    printf("Stack Adresi (Yerel):   %p\n", (void *)&yerel_degisken);
    printf("Heap Adresi (Dinamik):  %p\n", (void *)dinamik_alan);

    // Gozlem:
    // Stack adresi genellikle cok daha yuksek bir sayidir (ust bolge).
    // Heap adresi ise dusuk bolgededir.
    // Bu, RAM duzeni semasiyla uyumludur:
    //
    //   +---------------------------+ <-- Yuksek Adresler
    //   |   STACK (Statik)          |
    //   +---------------------------+
    //   |   BOS ALAN                |
    //   +---------------------------+
    //   |   HEAP (Dinamik)          |
    //   +---------------------------+ <-- Dusuk Adresler
    //   |   DATA & CODE             |
    //   +---------------------------+

    free(dinamik_alan);
    dinamik_alan = NULL;

    return 0;
}
