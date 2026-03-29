# 🏗️ Pointers 3 - Mimari ve İletişim

Bu klasör, işaretçilerin arka planda donanımla nasıl konuştuğunu ve fonksiyonlar arasında verilerin adreslerle (referans) nasıl aktarıldığını detaylandırır. Vizelerdeki en yüksek puanlı sorular genellikle bu klasördeki mantıktan çıkar.

## 📝 Çalışma Notu
* **[Pointers3.md](./Pointers3.md)**: Pointer aritmetiğinde bayt hesaplamaları, dizi-pointer denkliği ve "Pass by Reference" (Adresle Aktarım) / "Pass by Value" (Değerle Aktarım) kavramlarının sınav odaklı özeti.

## 💻 Uygulama Kodları

Bu dizindeki kodlar, işaretçilerin sadece veri tutmadığını, bellekte matematiksel olarak nasıl ilerlediğini kanıtlayan örneklerdir:

1. **[aritmetik_byte_hesabi.c](./aritmetik_byte_hesabi.c)**: `char`, `int`, ve `double` türlerindeki işaretçilerin arttırıldığında bellekte rastgele değil, türün boyutu (`sizeof`) kadar bayt atladığının ispatı.
2. **[dizi_pointer_denklik.c](./dizi_pointer_denklik.c)**: Bir dizinin fonksiyona gönderildiğinde aslında tüm dizinin kopyalanmadığını, sadece "ilk elemanın adresinin" gizlice gönderildiğini gösteren kod.
3. **[deger_vs_adres_gecisi.c](./deger_vs_adres_gecisi.c)**: Vize kağıtlarının klasik sorusu; verinin kopyasını (Pass by Value) göndermek ile referansını (Pass by Reference) göndermek arasındaki kalıcılık farkı.
4. **[gercek_swap_islemi.c](./gercek_swap_islemi.c)**: İki değişkenin değerini bellek adresleri üzerinden geçici bir değişken yardımıyla kalıcı olarak yer değiştiren klasik "Swap" algoritması.
