// Kaynak: Pointers4.pdf - Sayfa 10-13
// Amaci: Pointer parametresi ile faktoriyel hesaplama.
//        Fonksiyon sonucu return yerine adres uzerinden main'e yazar.
//        long long kullanimi ile buyuk sayilarin tasmasi onlenir.
// Ornek Cikti: 20! = 2432902008176640000, (-5)! = Hata mesaji
#include <stdio.h>

// long long kullanarak kapasiteyi artirdik
// int: ~2 Milyar (4 Byte)    -> 13! bile tasirir
// long long: ~9 Kentilyon (8 Byte) -> 20! rahatca saklar
void findFactorial(int n, long long *f)
{
    int i;
    *f = 1;

    // Negatif sayi kontrolu
    if (n < 0) {
        *f = 0;  // Hata gostergesi olarak 0 atanabilir
        return;
    }

    for (i = 1; i <= n; i++)
        *f = *f * i;  // Her adimda *f uzerinden main'deki fact'a yaziyoruz
}

int main()
{
    long long fact;  // Sonuc artik daha buyuk olabilir
    int num1;

    printf("\n Sayinin faktoriyelini bul :\n");
    printf(" Bir sayi giriniz : ");
    scanf("%d", &num1);

    findFactorial(num1, &fact);  // fact'in adresini gonderiyoruz

    if (fact == 0 && num1 < 0)
        printf("Hata: Negatif sayilarin faktoriyeli hesaplanamaz.\n");
    else
        printf(" %d sayisinin faktoriyeli : %lld \n", num1, fact);

    return 0;
}
