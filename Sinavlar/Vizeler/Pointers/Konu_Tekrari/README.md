# 🧠 Konu Tekrarı ve Sınav Simülasyonu

Bu klasör, vize sınavlarında öğrencileri en çok zorlayan **"Karmaşık Bellek Takibi (Tracing)"** ve birden fazla konunun (Dizi + Döngü + Fonksiyon + Pointer) harmanlandığı soru tiplerine ayrılmıştır.

Buradaki kodları bilgisayarda çalıştırmadan önce **mutlaka kağıt üzerinde bellek tabloları çizerek** çıktılarını tahmin etmeye çalışın.

## 📂 İçerik

### [Pointers 1-2 Tekrarları](./Pointers_1-2/)
Bu dizinde, temel ve orta seviye işaretçi bilgilerinin zorlayıcı kombinasyonları bulunur:
* **[pointer_ile_dizi_ters_cevir.c](./Pointers_1-2/pointer_ile_dizi_ters_cevir.c)** - İki uçtan işaretçilerle diziyi kendi içinde tersine çevirme.
* **[fonksiyon_icinde_aritmetik.c](./Pointers_1-2/fonksiyon_icinde_aritmetik.c)** - Adresi arttırmak (`ptr++`) ile adresteki değeri arttırmak (`(*ptr)++`) arasındaki sınavlık farklar.
* **[isaretci_dizisi_ve_stringler.c](./Pointers_1-2/isaretci_dizisi_ve_stringler.c)** - Karakter işaretçisi dizileri (Array of Pointers) mantığı.
* **[zorlu_bellek_takibi_quiz.c](./Pointers_1-2/zorlu_bellek_takibi_quiz.c)** - Kağıt kalem kullanmadan çözülmesi neredeyse imkansız olan, 3. değişken olmadan yapılan takas (swap) ve adres sekme işlemleri.

### [Pointers 3 Tekrarları](./Pointers3/)
Bu dizinde, fonksiyonlardan adres döndürme ve çoklu referans aktarımı (Pass by Reference) üzerine ileri seviye sınav soruları bulunur:
* **[adres_donduren_arama.c](./Pointers3/adres_donduren_arama.c)** - Fonksiyondan işaretçi döndürmek ve adresler arası çıkarma işlemi (`p - &dizi[0]`) yaparak dizideki konumu (indeksi) bulma.
* **[coklu_deger_dondurme.c](./Pointers3/coklu_deger_dondurme.c)** - C dilindeki `return` kısıtlamasını aşarak, fonksiyona adres yollayıp birden fazla değeri (en küçük, en büyük, ortalama) aynı anda elde etme.
* **[karma_isaretci_aritmetigi.c](./Pointers3/karma_isaretci_aritmetigi.c)** - `*p++`, `*(++p)` ve `(*p)++` işlemlerinin dizi üzerinde peş peşe kullanıldığında belleği nasıl manipüle ettiğini gösteren klasik tracing sorusu.
