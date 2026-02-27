#include <stdio.h>

int main(){

	// scanf: kullanıcıdan değer almasını sağlar.

	char ad[20], soyad[30]; // ad ve soyad degerlerini degisken icinde aldik
	printf("Ad gir: "); scanf("%s", &ad); // ad girilmesini istedik sonra aldik
	printf("Soyad gir: "); scanf("%s", &soyad); // soyad girilmesini istedik sonra aldik
	
	printf("\nAd: %s ", ad); printf("Soyad: %s", soyad); // ad ve soyad degerlerini yazdirdik.

	return 0;
}