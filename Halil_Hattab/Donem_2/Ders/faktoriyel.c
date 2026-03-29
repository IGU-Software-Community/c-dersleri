#include <stdio.h>

void findF(int n, long long *f){
	int i;
	*f = 1;

	// negatif sayi kontrolu
	if (n < 0){
		*f = 0;
		return;
	}

	for(i = 1; i <= n; i++)
		*f = *f * i;
}

int main(){
	int n;
	long long fact;

	printf("lutfen sayi gir: ");
	scanf("%d", &n);

	if(n == 0 || n < 0){  // if kontrolu korundu, düzeltildi
		printf("\n0 ve alti olmaz!");
	} else {
		findF(n, &fact);  // void olduğu için direkt çağrıldı
		printf("\nsonuc: %lld\n", fact); // doğru değişken + doğru format
	}

	return 0;
}
