#include <stdio.h>

int main(){

	float sinav1=42.13, sinav2=90, sinav3=50, sinav4=62, sonuc;

	printf("\n\n\tSinif gecme programina hos geldiniz!\n");
	printf("\n\tbu programla, daha onceden degiskenlerle degerleri atanmis sinav sonuclarini hesaplayarak sinifi gecip gecmedigini kullaniciya bildirecek.\n\n");

	sonuc=(sinav1+sinav2+sinav3+sinav4)/4;

	if (sonuc>=50)
	{
		printf("\n\tsinifi %f puan ortalamasiyla gecti =)\n\n", sonuc);
	} else if (sonuc<=49){
		printf("\n\tsinifi %f puan ortalamasiyla kaldi =(\n\n");
	} else {
		printf("\n\nprogram if-else kod blogunda hata verdi.\n\n");
	}

	return 0;
}