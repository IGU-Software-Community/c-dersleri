# 🔧 Pointers 4 - Uygulamalar, const ve Dinamik Bellek

Bu klasör, işaretçilerin pratik uygulamalarını (sıralama, string dolaşımı, faktöriyel), `const` belirtecinin pointer kombinasyonlarını ve dinamik bellek yönetiminin (`malloc`, `free`) temellerini kapsar.

## 📝 Çalışma Notu
* **[Pointers4.md](./Pointers4.md)**: Tüm konuların detaylı anlatımı, tablolar, bellek düzeni şeması ve terimler sözlüğü.

## 💻 Uygulama Kodları

Bu dizindeki kodlar, önceki bölümlerdeki temel kavramları gerçek problemlere uygulayan örneklerdir:

1. **[pointer_siralama.c](./pointer_siralama.c)**: Üç sayıyı `swap` fonksiyonu ile küçükten büyüğe sıralama. Pointers 3'teki "Pass by Reference" mantığının pratik uygulaması.
2. **[sesli_sessiz_sayici.c](./sesli_sessiz_sayici.c)**: `char *pt` ile string üzerinde karakter karakter dolaşarak sesli ve sessiz harfleri sayma. `fgets` kullanımı, `\n` temizleme yöntemleri (`strcspn` ve manuel döngü) ve çift koşullu döngü mantığı yorum satırlarıyla açıklanmıştır.
3. **[faktoriyel_hesapla.c](./faktoriyel_hesapla.c)**: Pointer parametresi ile faktöriyel hesaplama. `long long` veri tipi kullanımı ve negatif sayı kontrolü; fonksiyonun `return` yerine adres üzerinden sonuç yazma mantığı.
4. **[const_pointer_demo.c](./const_pointer_demo.c)**: `int *const`, `const int *` ve `const int *const` — üç `const` kombinasyonunun çalışan gösterimi. Hatalı kullanımlar yorum satırı olarak işaretlenmiştir.
5. **[malloc_temel.c](./malloc_temel.c)**: `malloc()` fonksiyonunun temel kullanımı; `sizeof` ile platform-bağımsız bellek ayırma, `(int*)` tür dönüşümü, `NULL` kontrolü ve `free` ile iade. Statik ve dinamik bellek karşılaştırması yorum olarak içerir.
6. **[dinamik_dizi.c](./dinamik_dizi.c)**: Kullanıcıdan boyut alarak dinamik dizi oluşturma, doldurma, pointer gösterimi ile yazdırma ve `free` ile bellek iadesi. `free` sonrası pointer'ın `NULL`'a atanması gösterilir.
7. **[bellek_adresi_izleme.c](./bellek_adresi_izleme.c)**: Stack ve Heap bellek adreslerinin farklı bölgelerde yer aldığının ispatı. RAM düzeni şemasıyla uyumlu çıktı üretir.
