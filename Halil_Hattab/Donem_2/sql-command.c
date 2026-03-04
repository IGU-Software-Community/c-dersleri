#include <stdio.h>
#include <string.h>

void test(char* text, int flag);

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

    char cumle[1000], kelime[99];
    int uzunluk, i, j=0;

    // ^\n: alt satira gecene kadar her seyi oku/al
    // []: karakter kumesi, yani scanf'e hangi kurallar altinda okuyacagini soyleriz

    printf("lutfen cumle yaziniz: "); scanf("%[^\n]", cumle);
    uzunluk = strlen(cumle); // strlen: icindeki kelime uzunlugunu soyler

    printf("\ncumleniz:\n\t%s", cumle);
    printf("\ncumlenizin uzunlugu: %d\n", uzunluk);
    // cumle=cumle+k; error: lvalue expected
    for (i = 0; i <= uzunluk; i++)
    {
        if (cumle[i]==' '){
            // printf("\t%s\n", kelime);
            printf("SPACE ");
            test(kelime, 1);
            j=0;
            kelime[j]='\0';
        } else {
            printf("%c\n", cumle[i]);
            kelime[j]=cumle[i]; // NOT: onceki hata += operatoru, bu ustune ekler yanina degil... bir diger hata: her kelimede kelime index'ini sifirlamam gerekiyor.
            j++;
            // if (cumle[uzunluk]=='\n') {printf("SONA GELDIK\n"); } else {test(kelime, 0); }
            test(kelime, 0);
        }
    }

    printf("\nson karakter: %d: %c", uzunluk, strlen(cumle));

    printf("\n");

    return 0;
}


void test(char* text, int flag){
    if(flag==1){
        printf("[%s | FLAG=%d]\n\n", text, flag);
    } else if (flag==0){
        // printf("[FLAG=%d]\n", flag);
    }
}
