#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//bu projede lokantada siparis icin adımları anlatır 
int main()
 {
 	int sec,tane;
 	float toplam=0;
 	char cevap[10];
 	printf("Lokanta menusu\n");
 	printf("1.pizza(400TL)\n");
 	printf("2.hamburger(300TL)\n");
 	printf("3.icecek(30TL)\n");
 	printf("4.sam tatlisi(70TL)\n");
 	printf("____________________\n");
 	printf("lutfen secim yapiniz  *^____^*\n");
 	scanf("%d",&sec);
 	printf("kac adet istiyorsunuz\n");
 	scanf("%d",&tane);
 	printf("hafta sonu mi(evet,hayir)");
 	scanf("%s",cevap);
 	
 	
 	switch(sec)
 	{
 		case 1:
 			toplam=400*tane;
 			printf("pizza sectiniz\n");
 			break;
 		case 2:
 			toplam=300*tane;
 			printf("hamburger sectiniz\n");
 			break;
 		case 3:
 			toplam=30*tane;
 			printf("icecek sectiniz\n");
 			break;
 		case 4:
 			toplam=70*tane;
 			printf("sam tatlisi sectiniz\n");
 			break;
 		default:
 		    printf("secim yapmadiniz\n");
 		    return 0;
	 }
 	 
 	 if(strcmp(cevap,"evet")==0)
 	toplam*=0.8;
 	printf("Toplam: %.2f TL\n", toplam);
    printf("tebrikler indirim kazandiniz^_^\n");
    printf("Afiyet olsun\n");
	
	return 0;
}