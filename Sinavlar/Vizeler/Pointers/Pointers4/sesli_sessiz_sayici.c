// Kaynak: Pointers4.pdf - Sayfa 2-9
// Amaci: Pointer ile string uzerinde dolasarak sesli ve sessiz harfleri sayma.
//        fgets kullanimi, \n temizleme yontemleri ve harf kontrolu gosterilir.
// Ornek Cikti: "Gelisim Universitesi" -> Sesli: 9, Sessiz: 10
#include <stdio.h>
#include <ctype.h>   // isalpha() - harf kontrolu icin
#include <string.h>  // strcspn() - \n temizleme icin

int main()
{
    char str1[50];
    char *pt;
    int ctrV = 0, ctrC = 0;

    printf("\n\n Sesli ve sessiz harfleri say:\n");
    printf("-----------------------------------------------------\n");
    printf(" Bir string giriniz: ");

    // Kullanicidan metin al
    // fgets, scanf'ten farkli olarak bosluk iceren metinleri de okur.
    // sizeof(str1) ile dizi siniri asilmaz (guvenli okuma).
    fgets(str1, sizeof(str1), stdin);

    // --- \n Temizleme ---
    // fgets, Enter karakterini (\n) de diziye ekler.
    // Temizlenmezse ileride string karsilastirmalarinda sorun cikar.
    //
    // Yontem 1 (strcspn ile - tek satir):
    str1[strcspn(str1, "\n")] = '\0';
    //
    // Yontem 2 (Manuel dongu ile - alternatif):
    // char *p = str1;
    // while (*p != '\0') {
    //     if (*p == '\n') { *p = '\0'; break; }
    //     p++;
    // }

    // str1'in baslangic adresini pt'ye ata
    pt = str1;

    // Dongu kosulu: iki durum kontrol edilir
    // 1) *pt != '\0' -> Dizi tamamen dolduysa \n olmaz, sadece \0 ile biter.
    //                    Bu kontrol olmadan dongu hafizada komsu verilere dalar.
    // 2) *pt != '\n' -> fgets \n eklediyse, onu harf sanip saymasin diye.
    //                    (Eger yukarida \n temizlendiyse bu kontrol ekstra guvenlik.)
    while (*pt != '\0' && *pt != '\n')
    {
        // Once karakterin bir harf olup olmadigini kontrol edelim.
        // Boşluk, rakam, noktalama isareti gibi karakterleri atlar.
        if ((*pt >= 'a' && *pt <= 'z') || (*pt >= 'A' && *pt <= 'Z'))
        {
            // Sesli harf kontrolu (Buyuk/Kucuk duyarliligi icin)
            if (*pt == 'A' || *pt == 'E' || *pt == 'I' || *pt == 'O' || *pt == 'U' ||
                *pt == 'a' || *pt == 'e' || *pt == 'i' || *pt == 'o' || *pt == 'u')
            {
                ctrV++;
            }
            else
            {
                // Harf ama sesli degilse, o zaman sessizdir
                ctrC++;
            }
        }

        pt++; // Bir sonraki karaktere gec (pointer aritmetigi: adres 1 byte ilerler)
    }

    printf("\n Sonuclar:\n");
    printf(" Sesli harfler  : %d\n", ctrV);
    printf(" Sessiz harfler : %d\n", ctrC);

    return 0;
}
