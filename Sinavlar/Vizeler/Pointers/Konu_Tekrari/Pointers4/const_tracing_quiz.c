#include <stdio.h>

/*
 * SINAV UYARISI: Bu kodu bilgisayarda çalıştırmadan önce
 * elinize bir kağıt alın ve her satırın derlenip derlenmeyeceğini,
 * derleniyorsa x ve y'nin son değerlerini yazın.
 *
 * SORU: Aşağıdaki kodda hangi satırlar derleme hatası verir?
 *       Hata vermeyen satırlar çalıştığında x ve y'nin son değerleri nedir?
 */
int main() {
    int x = 10, y = 20;

    // --- Bölüm A: int *const (Sabit Gösterici) ---
    int *const p1 = &x;
    *p1 = 55;           // Satir A1
    // p1 = &y;         // Satir A2 (yorum kaldırılırsa ne olur?)

    printf("Bolum A -> x: %d, y: %d\n", x, y);

    // --- Bölüm B: const int * (Sabit Veriye Gösterici) ---
    const int *p2 = &x;
    p2 = &y;            // Satir B1
    // *p2 = 99;        // Satir B2 (yorum kaldırılırsa ne olur?)

    printf("Bolum B -> *p2: %d\n", *p2);

    // --- Bölüm C: Fonksiyon parametresi karışımı ---
    // Aşağıdaki fonksiyonu kafadan takip edin:
    //   void f(const int *a, int *const b) {
    //       *b = *a + 5;      // Satir C1: Geçerli mi?
    //       a = b;            // Satir C2: Geçerli mi?
    //       // b = a;         // Satir C3: Geçerli mi?
    //       // *a = 100;      // Satir C4: Geçerli mi?
    //   }

    // --- Bölüm D: const int *const (Tam Kilit) ---
    const int *const p3 = &x;
    printf("Bolum D -> *p3: %d\n", *p3);
    // p3 = &y;         // Satir D1 (yorum kaldırılırsa ne olur?)
    // *p3 = 77;        // Satir D2 (yorum kaldırılırsa ne olur?)

    // SORU: x'in son değeri nedir?
    // İpucu: Bölüm A'da *p1 = 55 yapıldı. p1 x'i gösteriyordu.

    printf("\nSon durum -> x: %d, y: %d\n", x, y);

    return 0;
}

/*
 * CEVAPLAR (önce kendin çöz!):
 *
 * Satir A1: GECERLI. int *const -> deger degisebilir. x = 55 olur.
 * Satir A2: HATA. int *const -> adres degistirilemez.
 *           "error: assignment of read-only variable 'p1'"
 *
 * Bolum A ciktisi: x: 55, y: 20
 *
 * Satir B1: GECERLI. const int * -> adres degisebilir. p2 artik y'yi gosteriyor.
 * Satir B2: HATA. const int * -> deger degistirilemez (salt okunur).
 *           "error: assignment of read-only location '*p2'"
 *
 * Bolum B ciktisi: *p2: 20 (cunku p2 artik y'yi gosteriyor, y hala 20)
 *
 * Satir C1: GECERLI. b int *const -> *b degistirilebilir.
 * Satir C2: GECERLI. a const int * -> adres degistirilebilir.
 * Satir C3: HATA. b int *const -> adres degistirilemez.
 * Satir C4: HATA. a const int * -> deger degistirilemez.
 *
 * Bolum D ciktisi: *p3: 55 (x Bolum A'da 55 olmustu)
 * Satir D1: HATA. const int *const -> adres degistirilemez.
 * Satir D2: HATA. const int *const -> deger degistirilemez.
 *
 * Son durum: x: 55, y: 20
 */
