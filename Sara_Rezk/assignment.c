#include <stdio.h>

int main() {

/*Dışarıdan 5 öğrencinin 4 notunun 
(Vize,Final Odev,Kisasinav) ortalamalarını 
hesaplayan programı yazınız.*/

float vize, final, odev, kisasinav;
float ortalama;

for(int i=1; i<=5; i++){
    printf("%d. ogrencinin notlarini giriniz:\n", i);

    printf("Vize notu: ");
    scanf("%f", &vize);

    printf("Final notu: ");
    scanf("%f", &final);

    printf("Odev notu: ");
    scanf("%f", &odev);

    printf("Kisa sinav notu: ");
    scanf("%f", &kisasinav);

ortalama = (vize + final + odev + kisasinav) / 4;

    printf("%d. ogrencinin ortalamasi: %.2f\n\n", i, ortalama);
}
    return 0;  
}