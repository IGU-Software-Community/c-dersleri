#include <stdio.h>

int main(){
    /*Markete giden bir müşteri 5 farklı ürün alıyor. 
    Kasiyer ürünlerin fiyatlarını tek tek giriyor ve 
    en sonunda toplam tutarı ekrana yazıyor.*/

    float fiyat;
    float toplam = 0;

    for(int i=1; i<=6; i++){
        printf("%d. urunun fiyatini giriniz: ", i);
        scanf("%f", &fiyat);
        toplam= toplam + fiyat;
        
    }

    printf("Toplam tutar: %.2f\n", toplam);
    return 0;


}