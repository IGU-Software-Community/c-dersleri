# 🔧 Konu Tekrarı: Pointers 4 Kombinasyonları

`const` pointer kombinasyonları, swap (gerçek vs sahte), string pointer dolaşımı ve malloc + fonksiyon birleşimi üzerine sınavlık tracing soruları.

## 💻 Sınav Odaklı Kodlar
1. **[const_tracing_quiz.c](./const_tracing_quiz.c)**: `int *const`, `const int *`, `const int *const` — hangi satır derlenir hangi satır hata verir? Fonksiyon parametrelerinde `const` kombinasyonları dahil.
2. **[swap_gercek_vs_sahte.c](./swap_gercek_vs_sahte.c)**: Adres gönderen `swap(&x, &y)` ile değer gönderen `sahteSwap(x, y)` arasındaki fark. Sınavda en çok çıkan "Pass by Value vs Pass by Reference" tuzağı.
3. **[string_pointer_tracing.c](./string_pointer_tracing.c)**: `char *pt` ile string üzerinde karakter karakter dolaşarak sesli/sessiz/diğer sayma. İki farklı test string'i ile bellek tablosu çizme pratiği.
4. **[malloc_faktoriyel_tracing.c](./malloc_faktoriyel_tracing.c)**: `malloc` ile dinamik dizi, pointer aritmetiği ile doldurma, fonksiyona adres gönderip faktöriyel hesaplama. `0!` edge case'i dahil.
