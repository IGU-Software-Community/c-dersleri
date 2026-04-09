// Kaynak: Pointers5.pdf - Sayfa 1-3
// Amaci: malloc ile dinamik dizi olusturup Selection Sort ile kucukten buyuge siralama.
//        Pointer aritmetigi *(a+i) ile eleman erisimi gosterilir.
// Ornek Cikti: 4 2 -3 6 1 -> -3 1 2 4 6
#include <stdio.h>
#include <stdlib.h>  // malloc ve free icin gerekli

int main()
{
    int *a, i, j, tmp, n;

    printf("\n\n Bir arrayi pointer kullanarak sirala:\n");
    printf("------------------------------------------\n");

    printf(" Eleman sayisini giriniz : ");
    scanf("%d", &n);

    // Dinamik dizi olustur
    a = (int *) malloc(n * sizeof(int));

    if (a == NULL) {  // Bellek ayrilamazsa hata ver
        printf("Bellek yetersiz!");
        return 1;
    }

    // Diziyi kullanicidan doldur
    printf(" %d tane sayi giriniz : \n", n);
    for (i = 0; i < n; i++)
    {
        printf(" eleman - %d : ", i + 1);
        scanf("%d", a + i);  // a+i zaten bir adres, & gerekmez
    }

    // Selection Sort algoritmasi
    // Dis dongu: her pozisyon icin en kucuk elemani bul
    // i < (n-1) cunku son eleman karsilastirilacak kimse kalmaz
    for (i = 0; i < (n - 1); i++)
    {
        // Ic dongu: i'den sonraki tum elemanlarla karsilastir
        for (j = i + 1; j < n; j++)
        {
            // *(a+i) ile a[i] ayni seydir (pointer gosterimi)
            if (*(a + i) > *(a + j))
            {
                // Swap islemi: gecici degisken ile yer degistir
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    // Siralanmis diziyi yazdir
    printf("\n Siralama sonrasi elemanlar: \n");
    for (i = 0; i < n; i++)
    {
        printf(" eleman - %d : %d \n", i + 1, *(a + i));
    }

    // Bellegi iade et
    free(a);
    a = NULL;

    printf("\n");
    return 0;
}
