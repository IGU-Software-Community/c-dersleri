#include <stdio.h>
#include <string.h>

/*
 * SINAV UYARISI: Kağıt üzerinde str dizisinin her hücresini çizin.
 * pt'nin her adımda hangi hücreyi gösterdiğini ve
 * sayaçların nasıl değiştiğini yazın.
 *
 * SORU: Aşağıdaki stringler girildiğinde sesli, sessiz ve diger
 *       sayaçlarının son değerleri ne olur?
 *
 *       Test 1: "C dili"
 *       Test 2: "Ab3!"
 */

int main() {
    char str[20] = "C dili";  // Sınavda fgets yerine doğrudan atama yapılır
    char *pt = str;
    int sesli = 0, sessiz = 0, diger = 0;

    while (*pt != '\0') {
        if ((*pt >= 'a' && *pt <= 'z') || (*pt >= 'A' && *pt <= 'Z')) {
            if (*pt == 'a' || *pt == 'e' || *pt == 'i' || *pt == 'o' || *pt == 'u' ||
                *pt == 'A' || *pt == 'E' || *pt == 'I' || *pt == 'O' || *pt == 'U') {
                sesli++;
            } else {
                sessiz++;
            }
        } else {
            diger++;
        }
        pt++;
    }

    printf("Sonuclar: sesli=%d, sessiz=%d, diger=%d\n", sesli, sessiz, diger);

    // --- İkinci test: pointer sıfırlama ---
    char str2[20] = "Ab3!";
    pt = str2;
    sesli = 0; sessiz = 0; diger = 0;

    while (*pt != '\0') {
        if ((*pt >= 'a' && *pt <= 'z') || (*pt >= 'A' && *pt <= 'Z')) {
            if (*pt == 'a' || *pt == 'e' || *pt == 'i' || *pt == 'o' || *pt == 'u' ||
                *pt == 'A' || *pt == 'E' || *pt == 'I' || *pt == 'O' || *pt == 'U') {
                sesli++;
            } else {
                sessiz++;
            }
        } else {
            diger++;
        }
        pt++;
    }

    printf("Sonuclar: sesli=%d, sessiz=%d, diger=%d\n", sesli, sessiz, diger);

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * TEST 1: "C dili"
 * Bellek: | 'C' | ' ' | 'd' | 'i' | 'l' | 'i' | '\0' |
 *
 * Adim 1: *pt = 'C' -> Harf EVET, sesli degil -> sessiz++ (sessiz=1)
 * Adim 2: *pt = ' ' -> Harf HAYIR -> diger++ (diger=1)
 * Adim 3: *pt = 'd' -> Harf EVET, sesli degil -> sessiz++ (sessiz=2)
 * Adim 4: *pt = 'i' -> Harf EVET, sesli EVET -> sesli++ (sesli=1)
 * Adim 5: *pt = 'l' -> Harf EVET, sesli degil -> sessiz++ (sessiz=3)
 * Adim 6: *pt = 'i' -> Harf EVET, sesli EVET -> sesli++ (sesli=2)
 * Adim 7: *pt = '\0' -> Dongu biter
 *
 * Cikti: sesli=2, sessiz=3, diger=1
 *
 * TEST 2: "Ab3!"
 * Bellek: | 'A' | 'b' | '3' | '!' | '\0' |
 *
 * Adim 1: *pt = 'A' -> Harf EVET, sesli EVET -> sesli++ (sesli=1)
 * Adim 2: *pt = 'b' -> Harf EVET, sesli degil -> sessiz++ (sessiz=1)
 * Adim 3: *pt = '3' -> Harf HAYIR -> diger++ (diger=1)
 * Adim 4: *pt = '!' -> Harf HAYIR -> diger++ (diger=2)
 * Adim 5: *pt = '\0' -> Dongu biter
 *
 * Cikti: sesli=1, sessiz=1, diger=2
 */
