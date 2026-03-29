#include <stdio.h>

/*
 * SINAV UYARISI: Bu kodu bilgisayarda çalıştırmadan önce
 * elinize bir kağıt alın ve dizi elemanlarının nasıl değiştiğini
 * adım adım yazarak (Trace ederek) tahmin etmeye çalışın.
 */
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // p, arr[0] (yani 10) adresini gösteriyor

    printf("Baslangic: p'nin gosterdigi deger = %d\n", *p);

    /* * DURUM 1: (*p)++
     * Parantez içindeki *p önce çalışır. İşaretçinin gösterdiği değere ulaşır (10).
     * Sonra o değeri 1 artırır. Adres YERİNDE SABİTTİR. arr[0] artık 11 olur.
     */
    (*p)++;
    printf("Islem 1 '(*p)++'  -> arr[0] = %d, p'nin degeri = %d\n", arr[0], *p);

    /* * DURUM 2: *(++p)
     * Önce parantez içindeki ++p çalışır. İşaretçinin ADRESİ bir sonraki hücreye (arr[1]) kayar.
     * Sonra * ile o adresteki değere ulaşır ve o değere 100 ekler.
     */
    *(++p) += 100;
    printf("Islem 2 '*(++p)'  -> arr[1] = %d, p'nin yeni degeri = %d\n", arr[1], *p);

    /* * DURUM 3: *p++
     * Burada parantez yok. Sağdan sola kuralı işler ancak Post-Increment (++) işlemi
     * bulunduğu satır bittikten sonra adresi artırır.
     * Yani: Önce p'nin GÜNCEL adresindeki (arr[1]) değere 5 ekle, İŞLEM BİTİNCE adresi arr[2]'ye kaydır.
     */
    *p++ += 5;
    printf("Islem 3 '*p++'    -> arr[1] = %d, p'nin su anki degeri (kaydi) = %d\n", arr[1], *p);

    printf("\nSon Dizi Durumu: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    // Beklenen Çıktı: 11 125 30 40 50
    printf("\n");

    return 0;
}
