#include <stdio.h>

int main()
{
    int secim, sayi1, sayi2, sonuc;
    printf("MENU\n");
    printf("====\n");
    printf("1) +\n");
    printf("2) -\n");
    printf("3) *\n");
    printf("4) /\n");

    printf("Secim: ");
    scanf("%d", &secim);

    printf("\nsayi 1: ");
    scanf("%d", &sayi1);

    printf("\nsayi 2: ");
    scanf("%d", &sayi2);

    if (secim==1) {
        sonuc=sayi1+sayi2;
        printf("\n+ islemin sonucu: %d + %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==2) {
        sonuc=sayi1-sayi2;
        printf("\n- islemin sonucu: %d - %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==3) {
        sonuc=sayi1*sayi2;
        printf("\n* islemin sonucu: %d * %d = %d\n\n", sayi1, sayi2, sonuc);
    } else if (secim==4) {
        sonuc=sayi1/sayi2;
        printf("\n/ islemin sonucu: %d / %d = %d\n\n", sayi1, sayi2, sonuc);
    } else {
        printf("\t\nBir sorun olustu\n\n");
    }

    return 0;
}
