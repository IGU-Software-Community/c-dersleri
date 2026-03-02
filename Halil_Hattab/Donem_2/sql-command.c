#include <stdio.h>
#include <string.h>

int main()
{
    /*
        bu dosya SQL komutlarina benzer bir derleyici mantigi islevini gorur.
        test surecinde.

        TODO:
        - coklu kelime degerlerini oku
        - kelimeleri birbirinden ayir

     */

    // cumle icinde ' ' (bolsuk) tespit edilirse kelime var demektir.

    char* cumle[500];
    char bosluk[1]=" ";

    // ^\n: alt satira gecene kadar her seyi oku/al
    // []: karakter kumesi, yani scanf'e hangi kurallar altinda okuyacagini soyleriz
    printf("lutfen cumle yaziniz: "); scanf("%[^\n]", cumle);

    printf("\ncumleniz:\n\t%s", &cumle);
    // strlen: icindeki kelime uzunlugunu soyler
    int uzunluk = strlen(cumle);
    printf("\ncumlenizin uzunlugu: %d\n", uzunluk);

    for (int i = 1; i <= uzunluk; i++)
    {
        printf("%d. : %c \n", i, cumle[i]);
        if (cumle[i]==bosluk[0])
        {
            printf("bosluk tespit edildi\n");
            // i++;
        }
        // i++;
    }
    printf("\n");

    return 0;
}
