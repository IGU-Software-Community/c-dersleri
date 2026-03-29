# Vizeler

Bu klasör vizelere hazırlık konuları için oluşturuldu.

## Vizelere Hazırlık

Sevgili arkadaşlar, vizelere en iyi çalışma uygulayarak çalışmaktır.
Özellikle pratik gerektiren yazılım alanında öğrendiklerinizde iyi olabilmeniz için **pratik yapmak zorunludur.**
Sobanın sıcak olduğu bilgisi, siz sobaya dokunmadığınız sürece soyut kalacaktır.
Önerebileceğim çalışma şekilleri:
  1. Kağıt üstünde yazmak. (Bilgisayara oranla kat ve kat daha iyidir.)
  2. Bilgisayar üstünde yazmak.

---

## 📑 İçindekiler

- [1. Pointers 1 ve 2 (Temel ve Orta Seviye)](#1-pointers-1-ve-2-temel-ve-orta-seviye)
- [2. Konu Tekrarı (Sınavlık Karmaşık Sorular)](#2-konu-tekrarı-sınavlık-karmaşık-sorular)
- [3. Pointers 3 (Mimari ve İletişim)](#3-pointers-3-mimari-ve-i̇letişim)

---

## 1. Pointers 1 ve 2 (Temel ve Orta Seviye)
İşaretçilerin temelleri, adres operatörleri (`&`, `*`) ve dizilerin bellekteki ardışık yapısı üzerine notlar ve kodlar.

* **📝 Çalışma Notları:**
  * [Pointers.md](./Pointers1_2/Pointers.md) - Temel kavramlar ve tür uyumu.
  * [Pointers2.md](./Pointers1_2/Pointers2.md) - Bellek takibi (tracing) ve fonksiyonlara giriş.
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

---

## 2. Konu Tekrarı (Sınavlık Karmaşık Sorular)
Vize sınavlarında puan belirleyici olan; fonksiyon, dizi, döngü ve işaretçilerin birbiriyle karıştırıldığı "Çıktı Ne Olur?" (Tracing) tarzı zorlu kombinasyonlar.

* *Detaylı bilgi ve kodlar için alt klasöre bakınız:* **[Konu_Tekrari](./Konu_Tekrari/)**
  * [Pointers 1-2 Kombinasyonları](./Konu_Tekrari/Pointers_1-2/)
  * [Pointers 3 Kombinasyonları](./Konu_Tekrari/Pointers3/)

---

## 3. Pointers 3 (Mimari ve İletişim)
Gösterici aritmetiğinin arka planı (bayt hesabı), dizilerin pointer denkliği ve fonksiyonlar arası kalıcı veri aktarımı.

* **📝 Çalışma Notu:**
  * [Pointers3.md](./Pointers3/Pointers3.md) - İleri aritmetik ve adres aktarımı notları.
* **💻 Mimari ve İletişim Kodları:**
  * [aritmetik_byte_hesabi.c](./Pointers3/aritmetik_byte_hesabi.c) - *Tip bazlı bellek atlama hesapları.*
  * [dizi_pointer_denklik.c](./Pointers3/dizi_pointer_denklik.c) - *Dizi adının pointer olarak fonksiyona geçişi.*
  * [deger_vs_adres_gecisi.c](./Pointers3/deger_vs_adres_gecisi.c) - *Pass by Value vs. Pass by Reference.*
  * [gercek_swap_islemi.c](./Pointers3/gercek_swap_islemi.c) - *Adreslerle kalıcı yer değiştirme işlemi.*
