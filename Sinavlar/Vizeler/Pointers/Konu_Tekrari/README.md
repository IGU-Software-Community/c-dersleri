# 🧠 Konu Tekrarı ve Sınav Simülasyonu

Bu klasör, vize sınavlarında öğrencileri en çok zorlayan **"Karmaşık Bellek Takibi (Tracing)"** ve birden fazla konunun (Dizi + Döngü + Fonksiyon + Pointer) harmanlandığı soru tiplerine ayrılmıştır.

Buradaki kodları bilgisayarda çalıştırmadan önce **mutlaka kağıt üzerinde bellek tabloları çizerek** çıktılarını tahmin etmeye çalışın. Her dosyada cevaplar `/* CEVAPLAR */` bloğunda gizli — önce kendin çöz, sonra kontrol et.

## 📂 İçerik

### [Pointers 1-2 Tekrarları](./Pointers_1-2/)
Temel ve orta seviye işaretçi bilgilerinin zorlayıcı kombinasyonları:
* **[pointer_ile_dizi_ters_cevir.c](./Pointers_1-2/pointer_ile_dizi_ters_cevir.c)** - İki uçtan işaretçilerle diziyi kendi içinde tersine çevirme.
* **[fonksiyon_icinde_aritmetik.c](./Pointers_1-2/fonksiyon_icinde_aritmetik.c)** - Adresi arttırmak (`ptr++`) ile adresteki değeri arttırmak (`(*ptr)++`) arasındaki sınavlık farklar.
* **[isaretci_dizisi_ve_stringler.c](./Pointers_1-2/isaretci_dizisi_ve_stringler.c)** - Karakter işaretçisi dizileri (Array of Pointers) mantığı.
* **[zorlu_bellek_takibi_quiz.c](./Pointers_1-2/zorlu_bellek_takibi_quiz.c)** - Kağıt kalem kullanmadan çözülmesi neredeyse imkansız olan, 3. değişken olmadan yapılan takas (swap) ve adres sekme işlemleri.

### [Pointers 3 Tekrarları](./Pointers3/)
Fonksiyonlardan adres döndürme ve çoklu referans aktarımı (Pass by Reference) üzerine ileri seviye sınav soruları:
* **[adres_donduren_arama.c](./Pointers3/adres_donduren_arama.c)** - Fonksiyondan işaretçi döndürmek ve adresler arası çıkarma işlemi (`p - &dizi[0]`) yaparak dizideki konumu (indeksi) bulma.
* **[coklu_deger_dondurme.c](./Pointers3/coklu_deger_dondurme.c)** - C dilindeki `return` kısıtlamasını aşarak, fonksiyona adres yollayıp birden fazla değeri (en küçük, en büyük, ortalama) aynı anda elde etme.
* **[karma_isaretci_aritmetigi.c](./Pointers3/karma_isaretci_aritmetigi.c)** - `*p++`, `*(++p)` ve `(*p)++` işlemlerinin dizi üzerinde peş peşe kullanıldığında belleği nasıl manipüle ettiğini gösteren klasik tracing sorusu.

### [Pointers 4 Tekrarları](./Pointers4/)
`const` pointer kombinasyonları, gerçek/sahte swap tuzağı, string pointer dolaşımı ve `malloc` + fonksiyon birleşimi üzerine sınav soruları:
* **[const_tracing_quiz.c](./Pointers4/const_tracing_quiz.c)** - `int *const`, `const int *`, `const int *const` — hangi satır derlenir, hangi satır hata verir? Fonksiyon parametrelerinde `const` dahil.
* **[swap_gercek_vs_sahte.c](./Pointers4/swap_gercek_vs_sahte.c)** - Adres gönderen `swap(&x, &y)` ile değer gönderen `sahteSwap(x, y)` arasındaki "Pass by Value vs Pass by Reference" tuzağı.
* **[string_pointer_tracing.c](./Pointers4/string_pointer_tracing.c)** - `char *pt` ile string dolaşımı; sesli/sessiz/diğer sayaçlarını iki farklı test string'i ile takip etme.
* **[malloc_faktoriyel_tracing.c](./Pointers4/malloc_faktoriyel_tracing.c)** - `malloc` + pointer aritmetiği + fonksiyona adres gönderip faktöriyel hesaplama. `0!` edge case'i dahil.

### [Pointers 5 Tekrarları](./Pointers5/)
`calloc`/`realloc` davranışı, dangling pointer ve dinamik dizide sıralama adım adım takibi üzerine sınav soruları:
* **[calloc_dangling_tracing.c](./Pointers5/calloc_dangling_tracing.c)** - `malloc` (çöp veri) vs `calloc` (otomatik 0) ilk değer farkı ve `free` sonrası dangling pointer tehlikesi.
* **[realloc_tracing.c](./Pointers5/realloc_tracing.c)** - `realloc` ile genişletme/daraltma: eski veri korunur mu? Yeni alan ne içerir? `temp` pointer zorunluluğu.
* **[selection_sort_tracing.c](./Pointers5/selection_sort_tracing.c)** - `*(a+i)` pointer gösterimi ile Selection Sort; her swap sonrası dizi durumu ve toplam swap sayısı.
