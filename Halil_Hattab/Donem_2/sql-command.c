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


    // NOT: onceki commit'te hata * isaretini yazmis olmamdi.

    char cumle[500], kelime[50];
    int uzunluk, i;

    // ^\n: alt satira gecene kadar her seyi oku/al
    // []: karakter kumesi, yani scanf'e hangi kurallar altinda okuyacagini soyleriz

    printf("lutfen cumle yaziniz: "); scanf("%[^\n]", cumle);
    uzunluk = strlen(cumle); // strlen: icindeki kelime uzunlugunu soyler

    printf("\ncumleniz:\n\t%s", cumle);
    printf("\ncumlenizin uzunlugu: %d\n", uzunluk);

    for (i = 0; i < uzunluk; i++)
    {
        if (cumle[i]==' '){
            printf("\t%s\n", kelime);
            printf("SPACE\n");
            kelime[0]='\0';
        } else {
            printf("%c\n", cumle[i]);
            kelime[i]+= cumle[i];
        }
    }

    printf("\n");

    return 0;
}
