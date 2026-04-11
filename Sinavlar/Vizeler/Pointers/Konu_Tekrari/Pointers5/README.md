# 🧠 Konu Tekrarı: Pointers 5 Kombinasyonları

`calloc` vs `malloc` ilk değer davranışı, `realloc` genişletme/daraltma tracing'i, dangling pointer ve dinamik dizide Selection Sort adım adım takibi.

## 💻 Sınav Odaklı Kodlar
1. **[calloc_dangling_tracing.c](./calloc_dangling_tracing.c)**: `malloc` (çöp veri) vs `calloc` (otomatik 0) ilk değer davranışı. `free` sonrası `p = NULL` yapılmazsa ne olur (dangling pointer). Bellek durumu tablosu çizme pratiği.
2. **[realloc_tracing.c](./realloc_tracing.c)**: `realloc` ile genişletme (eski veri korunur mu? yeni alan ne içerir?) ve daraltma (erişilemeyen elemanlar). `temp` pointer neden zorunlu olduğunun açıklaması.
3. **[selection_sort_tracing.c](./selection_sort_tracing.c)**: 4 elemanlı diziyi `*(a+i)` pointer gösterimi ile Selection Sort uygulaması. Her swap sonrası dizinin durumu ve toplam swap sayısı. `*(a+i)` ile `a[i]` denkliği.
