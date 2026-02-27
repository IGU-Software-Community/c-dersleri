#include <stdio.h>

int main(){

	// birden cok satirli metin bazli degerleri ekrana bastirmak icin parantezler arasinda () 6 tane cif tirnak yazilir: printf("""degerler""");
	printf("""
	1) Toplama +
	2) Cikarma -
	3) Carpma *
	4) Bolme /
	0) Cikti""");

	while (1){

		// degerleri almak icin degiskenleri tanimlandi.
		int s1, s2, secim;
		printf("Hesap Makinesi\n");

		// sayi 1 aliniyor
		printf("\n\t1. sayiyi giriniz: ");
		scanf("%d", &s1);

		// sayi 2 aliniyor
		printf("\n\t2. sayiyi giriniz: ");
		scanf("%d", &s2);

		if(s1==NULL || s2==NULL){
			printf("sayilar bos olamaz.");
		} else{
			printf("secim giriniz (sadece 0-4 arasi): "); scanf("%d", &secim);

			if(secim==0){
				printf("cikis yapildi.");
				break;
			} else if(secim==1){
				int toplam;
				toplam=toplama(s1, s2);
				printf("\n\ttoplama sonucu: %d\n\n", toplam);
			} else if (secim==2){
				int fark;
				fark=cikarma(s1, s2);
				printf("\n\tcikarma sonucu: %d\n\n", fark);
			} else if (secim==3) {
				int carpim;
				carpim=carpma(s1, s2);
				printf("\n\tcarpma sonucu: %d\n\n");
			} else if (secim==4){
				int bolunme;
				bolunme=bolme(s1, s2);
				printf("\n\tbolme sonucu: %d\n\n");
			} else {
				printf("\n\n\t0-4 arasinda bir deger giriniz.\n");
				// break;
			}
		}
	}
	return 0;
}

int toplama(int s1, int s2){
	return s1+s2;
}

int cikarma(int s1, int s2){
	return s1-s2;
}

int carpma(int s1, int s2){
	return s1**s2;
}

int bolme(int s1, int s2){
	if (s2<=0)
	{
		printf("\n\t\n0'a bolunme hatasi!");
		return 0;
	} else {
		return s1/s2;
	}
}
