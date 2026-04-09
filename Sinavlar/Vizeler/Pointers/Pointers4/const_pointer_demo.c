// Kaynak: Pointers4.pdf - Sayfa 14-18
// Amaci: const belirtecinin pointer'larla 3 farkli kombinasyonunu gostermek.
//        Her kombinasyonda neyin degisip neyin degiemeyecegi gosterilir.
//
// Ozet Tablo:
// +---------------------+-------------------+--------------------+
// | Tanim               | Adres Degisir mi? | Deger Degisir mi?  |
// |                     | (ptr = &y)        | (*ptr = 5)         |
// +---------------------+-------------------+--------------------+
// | int *const          | HAYIR             | EVET               |
// | const int *         | EVET              | HAYIR              |
// | const int *const    | HAYIR             | HAYIR              |
// +---------------------+-------------------+--------------------+
#include <stdio.h>

int main()
{
    int x = 10, y = 20;

    // ============================================================
    // 1) Sabit Gosterici (Constant Pointer): int *const
    //    Pointer'in kendisi sabittir, baska adrese yonlendirilemez.
    //    Ama gosterdigi adresteki deger degistirilebilir.
    // ============================================================
    int *const ptr1 = &x;
    printf("--- int *const ptr1 = &x ---\n");
    printf("Baslangic: *ptr1 = %d\n", *ptr1);

    *ptr1 = 77;  // GECERLI: Adresteki degeri degistirmek serbest
    printf("*ptr1 = 77 sonrasi: x = %d\n", x);  // x artik 77

    // ptr1 = &y;  // HATA! Sabit pointer baska adrese yonlendirilemez.
    //             // Derleyici hatasi: "assignment of read-only variable 'ptr1'"

    x = 10; // x'i sifirla

    // ============================================================
    // 2) Sabit Veriye Gosterici (Pointer to Constant): const int *
    //    Adresteki deger bu pointer uzerinden degistirilemez (salt okunur).
    //    Ama pointer baska bir adrese yonlendirilebilir.
    // ============================================================
    const int *ptr2 = &x;
    printf("\n--- const int *ptr2 = &x ---\n");
    printf("Baslangic: *ptr2 = %d\n", *ptr2);

    ptr2 = &y;  // GECERLI: Pointer'i baska adrese yonlendirmek serbest
    printf("ptr2 = &y sonrasi: *ptr2 = %d\n", *ptr2);  // Artik y'yi gosteriyor

    // *ptr2 = 99;  // HATA! Sabit veriye yazma girisimi.
    //              // Derleyici hatasi: "assignment of read-only location '*ptr2'"

    // ============================================================
    // 3) Sabit Veriye Sabit Gosterici: const int *const
    //    Hem adres hem deger sabittir. Hicbir sey degistirilemez.
    // ============================================================
    const int *const ptr3 = &x;
    printf("\n--- const int *const ptr3 = &x ---\n");
    printf("*ptr3 = %d (sadece okunabilir)\n", *ptr3);

    // ptr3 = &y;   // HATA! Adres degistirilemez.
    // *ptr3 = 50;  // HATA! Deger degistirilemez.

    // ============================================================
    // Fonksiyon Parametrelerinde const (kavramsal not):
    // void f(int *p)        -> Her seyi yapabilir
    // void f(const int *p)  -> Sadece okuyabilir, degeri degistiremez
    // void f(int *const p)  -> Degeri degistirebilir ama ptr'yi yonlendiremez
    // ============================================================

    printf("\n--- Ozet ---\n");
    printf("int *const     : Adres SABIT, Deger DEGISIR\n");
    printf("const int *    : Adres DEGISIR, Deger SABIT\n");
    printf("const int *const: Adres SABIT, Deger SABIT\n");

    return 0;
}
