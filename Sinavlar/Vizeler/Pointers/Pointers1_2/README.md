# 🧭 Pointers 1 ve 2 - Temel ve Orta Seviye

Bu klasör, C programlama dilinde işaretçiler (pointers) dünyasına giriş yaptığınız ve bellek yönetiminin temellerini attığınız yerdir. Vize sınavlarındaki temel "Çıktı Ne Olur?" soruları buradaki mantıklar üzerine kurulur.

## 📝 Çalışma Notları
Sınav öncesi teorik eksiklerinizi kapatmak ve terimleri hatırlamak için önce bu notları okuyun:
* **[Pointers.md](./Pointers.md)**: İşaretçi nedir, bellekte adresleme (`&`) nasıl çalışır, adresteki değere (`*`) nasıl ulaşılır ve tür uyumu neden önemlidir.
* **[Pointers2.md](./Pointers2.md)**: Birden fazla işaretçinin birbirine atanması, bellek üzerinde adım adım değer takibi (tracing), işaretçi aritmetiği ve fonksiyonlara temel giriş.

---

## 💻 Uygulama Kodları

Buradaki kodlar, teorik notların bilgisayar belleğindeki canlı kanıtlarıdır. İki zorluk derecesine ayrılmıştır:

### 🟢 Temel Seviye (Kavramsal İsapatlar)
İşaretçilerin ve adres operatörlerinin en yalın halleriyle kullanıldığı kodlar:
* **[kilo_ortuk.c](./kilo_ortuk.c)** & **[kilo_acik.c](./kilo_acik.c)**: Değişkenlerin sistem tarafından (örtük) ve sizin tarafınızdan (açık) nasıl adreslendiğini gösterir.
* **[tamsayi_isaretci.c](./tamsayi_isaretci.c)**: `int` türünde işaretçi tanımlama ve veri alma.
* **[10prg01.c](./10prg01.c)** & **[10prg02.c](./10prg02.c)**: Adres (`&`) ve içerik (`*`) operatörlerinin karşılaştırması ve dolaylı yoldan değer değiştirme.
* **[dizi_isaretci_erisim.c](./dizi_isaretci_erisim.c)**: String (karakter dizisi) elemanlarına indeks yerine işaretçi aritmetiği ile erişim.

### 🟡 Orta Seviye (Sınav Pratikleri)
Bellek takibi yapmanızı ve algoritmik düşünmenizi gerektiren kodlar:
* **[bellek_takibi.c](./bellek_takibi.c)**: Atamalar (`p2 = p3`) ve artırımlar (`(*p2)++`) ile değerlerin nasıl değiştiğini izleme. *(Kağıt üzerinde çizerek çalışın)*
* **[dizi_adres_yazdir.c](./dizi_adres_yazdir.c)**: Dizilerin bellekte gerçekten yan yana (ardışık) durduğunun kanıtı.
* **[isaretci_aritmetik_test.c](./isaretci_aritmetik_test.c)**: İşaretçinin tuttuğu adresi değil, adresteki değeri artırma/azaltma denemeleri.
* **[fonksiyon_pointer.c](./fonksiyon_pointer.c)**: Fonksiyona adres göndererek değeri kalıcı olarak değiştirme.
* **[iki_sayi_topla.c](./iki_sayi_topla.c)** & **[buyuk_sayi_bul.c](./buyuk_sayi_bul.c)**: İşaretçiler üzerinden veri alma, matematiksel işlem ve mantıksal karşılaştırma (if/else).
* **[alfabe_yazici.c](./alfabe_yazici.c)** & **[alfabe_tek_dongu.c](./alfabe_tek_dongu.c)**: ASCII sayı sistemini ve `ptr++` kullanarak alfabeyi belleğe sırayla dizme algoritmaları.
