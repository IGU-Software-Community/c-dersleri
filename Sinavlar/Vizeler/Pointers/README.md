# Vizeler

- Bu klasör vizelere hazırlık konuları için oluşturuldu.

## Vizelere Hazırlık

Sevgili arkadaşlar, vizelere en iyi çalışma uygulayarak çalışmaktır.
Özellikle pratik gerektiren yazılım alanında öğrendiklerinizde iyi olabilmeniz için **pratik yapmak zorunludur.**
Sobanın sıcak olduğu bilgisi, siz sobaya dokunmadığınız sürece soyut kalacaktır.
Önerebileceğim çalışma şekilleri:
  1. Kağıt üstünde yazmak. (bilgisayara oranla kat ve kat daha iyidir.)
  2. Bilgisayar üstünde yazmak.

---

## 📑 İçindekiler

- [1. Pointers (İşaretçiler)](#1-pointers-i̇şaretçiler)
  - [Pointers 1 ve 2 (Temel ve Orta Seviye)](#pointers-1-ve-2-temel-ve-orta-seviye)
  - [Konu Tekrarı (Sınavlık Karmaşık Sorular)](#konu-tekrarı-sınavlık-karmaşık-sorular)
  - [Pointers 3 (Mimari ve İletişim)](#pointers-3-mimari-ve-i̇letişim)
- *(İleride eklenecek diğer konular buraya gelecek...)*

---

## 1. Pointers (İşaretçiler)

Bu bölüm; bellek yönetimi, işaretçi aritmetiği ve fonksiyonlar arası referans aktarımını kapsamaktadır.

### Pointers 1 ve 2 (Temel ve Orta Seviye)
İşaretçilerin temelleri, adres operatörleri (`&`, `*`) ve dizilerin bellekteki ardışık yapısı üzerine notlar ve kodlar.

* **📝 Çalışma Notları:**
  * [Pointers.md](./Pointers1_2/Pointers.md) - Temel kavramlar ve tür uyumu.
  * [Pointers2.md](./Pointers1_2/Pointers2.md) - Bellek takibi (tracing) ve fonksiyonlara giriş.
  * [Pointers3.md](./Pointers1_2/Pointers3.md) - İleri aritmetik ve adres aktarımı.
* **💻 Temel Uygulama Kodları:**
  * [kilo_ortuk.c](./Pointers1_2/kilo_ortuk.c) / [kilo_acik.c](./Pointers1_2/kilo_acik.c)
  * [tamsayi_isaretci.c](./Pointers1_2/tamsayi_isaretci.c)
  * [10prg01.c](./Pointers1_2/10prg01.c) / [10prg02.c](./Pointers1_2/10prg02.c)
  * [dizi_isaretci_erisim.c](./Pointers1_2/dizi_isaretci_erisim.c)
* **💻 Orta Seviye ve Algoritmalar:**
  * [bellek_takibi.c](./Pointers1_2/bellek_takibi.c)
  * [dizi_adres_yazdir.c](./Pointers1_2/dizi_adres_yazdir.c)
  * [isaretci_aritmetik_test.c](./Pointers1_2/isaretci_aritmetik_test.c)
  * [fonksiyon_pointer.c](./Pointers1_2/fonksiyon_pointer.c)
  * [iki_sayi_topla.c](./Pointers1_2/iki_sayi_topla.c)
  * [buyuk_sayi_bul.c](./Pointers1_2/buyuk_sayi_bul.c)
  * [alfabe_yazici.c](./Pointers1_2/alfabe_yazici.c) / [alfabe_tek_dongu.c](./Pointers1_2/alfabe_tek_dongu.c)
* **🛠️ Scriptler:**
  * [vize_tekrar_seti.sh](./Pointers1_2/vize_tekrar_seti.sh)

### Konu Tekrarı (Sınavlık Karmaşık Sorular)
Vize sınavlarında puan belirleyici olan; fonksiyon, dizi, döngü ve işaretçilerin birbiriyle karıştırıldığı "Çıktı Ne Olur?" (Tracing) tarzı zorlu kombinasyonlar.

* **💻 İleri Seviye Kombinasyon Kodları:**
  * [pointer_ile_dizi_ters_cevir.c](./Pointers1_2/Konu_Tekrari/Pointers-1_Pointers-2_PDFleri/pointer_ile_dizi_ters_cevir.c) - *Diziyi adreslerle kendi içinde çevirme.*
  * [fonksiyon_icinde_aritmetik.c](./Pointers1_2/Konu_Tekrari/Pointers-1_Pointers-2_PDFleri/fonksiyon_icinde_aritmetik.c) - *Değer ve adres artırımı farkı.*
  * [isaretci_dizisi_ve_stringler.c](./Pointers1_2/Konu_Tekrari/Pointers-1_Pointers-2_PDFleri/isaretci_dizisi_ve_stringler.c) - *Array of pointers mantığı.*
  * [zorlu_bellek_takibi_quiz.c](./Pointers1_2/Konu_Tekrari/Pointers-1_Pointers-2_PDFleri/zorlu_bellek_takibi_quiz.c) - *Kağıt kalem gerektiren karmaşık swap ve atamalar.*

### Pointers 3 (Mimari ve İletişim)
Gösterici aritmetiğinin arka planı (bayt hesabı), dizilerin pointer denkliği ve fonksiyonlar arası kalıcı veri aktarımı.

* **💻 Pass by Reference (Adres Aktarımı) Kodları:**
  * [aritmetik_byte_hesabi.c](./Pointers3/aritmetik_byte_hesabi.c) - *Tip bazlı bellek atlama hesapları.*
  * [dizi_pointer_denklik.c](./Pointers3/dizi_pointer_denklik.c) - *Dizi adının pointer olarak fonksiyona geçişi.*
  * [deger_vs_adres_gecisi.c](./Pointers3/deger_vs_adres_gecisi.c) - *Pass by value vs. Pass by reference farkı.*
  * [gercek_swap_islemi.c](./Pointers3/gercek_swap_islemi.c) - *Adreslerle kalıcı yer değiştirme.*

---
