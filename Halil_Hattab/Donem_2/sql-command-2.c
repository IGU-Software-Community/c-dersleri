#include <stdio.h>

int main()
{
    /* 2. dosya, genel durumu toplamak icin */

    char cumle[500], kelime[100];
    int i, j, uzunluk;
    printf("cumle gir: "); scanf("%499[^\n]", cumle);
    uzunluk=strlen(cumle);
    printf("\nuzunluk:%d\n", uzunluk);
    printf("%s\n===\n", cumle);
    // cumle => kelime
    for (i = 0; i <= uzunluk; i++)
    {
        // NOT: BUYUK HATA: if(cumle[i]==uzunluk) dizide karakteri uzunlik degerine esitlemeye calistim...
        if(cumle[i]==uzunluk)
            printf("SON");
        // // printf("uzunluk=%d\n", uzunluk);
        // printf("%c\n", cumle[i]);
        // if (cumle[i]=='%')
        // {
        //     printf("\tsona geldik\n");
        // }

        // if (cumle[i]==' ')
        // {
        //     printf("\tbosluk\n");
        // }

        if (cumle[i]==' ')
        {
            printf("\tKELIME: %s\n", kelime);
            kelime[i]='\0';
        } else if(!(cumle[i]==' ')){
            kelime[i]=cumle[i];
            printf("\t%s\n", kelime);
        }

    }

    printf("\n");

    return 0;
}
