#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int durum;
    printf("Ne Oluyor? Durumu 3 uzerinden degerlendir: \n");
    scanf("%d", &durum);
    switch(durum)
    {
        case 1:
            printf("Hallettim!\n");
            break;
        case 2:
            printf("Oluru var!, biraz zaman alir\n");
            break;
        case 3:
            printf("Bilmiyorum!! Ne oluyor??\n");
            break;
        default:
            printf("Ugrastirma insani, durumu bildir!\n");
    }
    return 0;
}
