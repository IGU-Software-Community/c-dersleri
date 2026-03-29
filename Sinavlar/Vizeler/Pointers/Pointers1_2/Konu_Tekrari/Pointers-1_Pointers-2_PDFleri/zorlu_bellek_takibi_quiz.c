#include <stdio.h>

// İki işaretçi alan ve değerleri değiştiren fonksiyon
void gizemliFonksiyon(int *p1, int *p2) {
    *p1 = *p1 + *p2;    // p1'in gösterdiği yerdeki değer, ikisinin toplamı olur
    *p2 = *p1 - *p2;    // p2'nin gösterdiği yerdeki değer değişir
    *p1 = *p1 - *p2;    // p1'in gösterdiği yer tekrar güncellenir
    // İpucu: Bu klasik bir "3. değişken kullanmadan Swap (takas)" algoritmasıdır.
}

int main() {
    int x = 10, y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;

    printf("Islem oncesi -> x: %d, y: %d\n", x, y);

    // ptr1 ve ptr2 zaten birer adres olduğu için & kullanmadan gönderiyoruz
    gizemliFonksiyon(ptr1, ptr2);

    printf("Islem sonrasi -> x: %d, y: %d\n", x, y);

    // Şimdi işleri biraz karıştıralım
    int z = 50;
    ptr1 = &z;          // ptr1 artık z'yi gösteriyor
    (*ptr2)++;          // ptr2 hala y'yi gösteriyordu, y'nin değeri 1 arttı

    gizemliFonksiyon(ptr1, ptr2); // z ve y takas edilir

    printf("Son durum -> x: %d, y: %d, z: %d\n", x, y, z);
    // x: 20 (ilk swap'tan kaldı)
    // y: 50 (ikinci swap sonrası z'nin değerini aldı)
    // z: 11 (ilk swap'ta y 10 olmuştu, ++ ile 11 oldu, swap ile z'ye geçti)

    return 0;
}
