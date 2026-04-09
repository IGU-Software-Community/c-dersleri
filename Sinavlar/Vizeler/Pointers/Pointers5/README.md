# 🧠 Pointers 5 - calloc, realloc ve İleri Dinamik Bellek

Bu klasör, `calloc` ile sıfırlanmış bellek ayırma, `realloc` ile mevcut belleği yeniden boyutlandırma, dinamik dizide sıralama algoritması ve tüm kavramları birleştiren kapsamlı bir uygulama (Not Hesaplama Sistemi) içerir.

## 📝 Çalışma Notu
* **[Pointers5.md](./Pointers5.md)**: calloc/realloc detaylı anlatımı, malloc-calloc karşılaştırma tablosu, güvenli realloc kalıbı, dangling pointer açıklaması ve terimler sözlüğü.

## 💻 Uygulama Kodları

1. **[dinamik_dizi_siralama.c](./dinamik_dizi_siralama.c)**: `malloc` ile dinamik dizi oluşturup **Selection Sort** algoritması ile küçükten büyüğe sıralama. Pointer aritmetiği `*(a+i)` ile eleman erişimi gösterilir.
2. **[malloc_vs_calloc.c](./malloc_vs_calloc.c)**: `malloc` ile elle sıfırlama (`p[i] = 0`) vs `calloc` ile otomatik sıfırlama — iki yöntemin aynı sonucu ürettiğini gösteren karşılaştırma. Her birinin ne zaman tercih edileceği yorum satırlarıyla açıklanmıştır.
3. **[calloc_kullanici_boyut.c](./calloc_kullanici_boyut.c)**: Kullanıcıdan eleman sayısı alarak `calloc` ile dinamik dizi oluşturma. `scanf` doğrulama (negatif sayı kontrolü) dahildir.
4. **[dangling_pointer_demo.c](./dangling_pointer_demo.c)**: `free` sonrası `p = NULL` yapılmazsa ne olduğu (dangling pointer tehlikesi) ve yapılırsa nasıl korunduğunun gösterimi. Otel benzetmesi ve Access Violation açıklaması yorum satırlarında.
5. **[not_hesaplama_sistemi.c](./not_hesaplama_sistemi.c)**: **Bölümün en kapsamlı uygulaması.** `malloc` + `realloc` birlikte kullanımı, `while(1)` sonsuz döngüsü ile süresiz veri girişi, `scanf` doğrulama ve tampon temizleme (`getchar`), 0-100 aralık kontrolü, pointer aritmetiği ile veri yazma, güvenli `realloc` (temp pointer) ve `free` ile bellek iadesi.
