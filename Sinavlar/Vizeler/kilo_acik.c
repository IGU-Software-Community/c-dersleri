/* * Kaynak: pointers.pdf - Sayfa 22
 * Konu: Açık (Explicit) Adresleme ve İşaretçiler
 */
#include <stdio.h>

int main() {
    float kilo;
    float *kilo_adresi; // float türünde bir adresi tutacak işaretçi

    kilo_adresi = &kilo; // & operatörü ile kilo'nun adresini alıp aktarıyoruz

    printf("Kac kilosunuz?...\n");
    scanf("%f", &kilo);

    // %p bellek adresini, %f ise adresteki değeri gösterir
    printf("kilo adresi: %p\n", &kilo);
    printf("isaretcinin tuttugu adres: %p\n", kilo_adresi);
    printf("isaretcinin gosterdigi adresteki deger: %f\n", *kilo_adresi);

    return 0;
}
