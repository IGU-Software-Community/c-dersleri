#include <stdio.h>

int main(){
    /*Öğretmen, sınıftaki 5 öğrencinin notunu giriyor. 
    Program, girilen notlar arasından en yüksek olanı bulup 
    ekrana yazdırıyor.*/

    float not;
    float enYuksekNot = 0;

    for(int i=1; i<=7; i++){
        printf("%d. ogrencinin notunu girirniz: ",i);
        scanf("%f", &not);

        if(not> enYuksekNot){
            enYuksekNot = not;
    }
    }

    printf("En yuksek not: %.2f\n", enYuksekNot);
    return 0;
}