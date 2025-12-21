#include <stdio.h>

int main(){
    /*Kullanıcıdan bir sayı (örneğin 7) istenecek. 
    Program o sayının 1'den 10'a kadar olan çarpım 
    tablosunu alt alta yazdıracak.*/

    int sayi;
    printf("Bir sayi giriniz: ");
    scanf("%d", &sayi);

    printf("%d sayisinin carpim tablosu:\n", sayi);
    for(int i=1; i<=10; i++){
        printf("%d x %d = %d\n", sayi, i , sayi*i);
    }
    return 0;
}