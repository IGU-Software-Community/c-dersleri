# Vizeler

Bu klasör, C programlama dili vize sınavlarına hazırlık amacıyla oluşturulmuş ders notlarını ve uygulama örneklerini içermektedir.

## 📂 Proje Yapısı

### 📝 Çalışma Notları (Markdown)
- **[Pointers.md](./Pointers.md)**: İşaretçilerin temelleri, adres operatörleri (`&`, `*`) ve tür uyumu.
- **[Pointers2.md](./Pointers2.md)**: Bellek takibi (tracing), fonksiyonlara işaretçi gönderimi ve dizi erişimi.

---

### 💻 Uygulama Kodları (.c)

#### 1. Temel İşaretçi Kavramları (Kaynak: pointers.pdf)
- **[kilo_ortuk.c](./kilo_ortuk.c)**: Değişkenlerin sistem tarafından otomatik adreslenmesi (Örtük Adresleme). *(Sayfa 20)*
- **[kilo_acik.c](./kilo_acik.c)**: Bir değişkenin adresini işaretçiye atama (Açık Adresleme). *(Sayfa 22)*
- **[tamsayi_isaretci.c](./tamsayi_isaretci.c)**: Tamsayı değişkenleri ve işaretçi ataması üzerine temel çalışma. *(Sayfa 27/31)*
- **[10prg01.c](./10prg01.c)**: Adres operatörü (`&`) ve işaretçi içeriğinin karşılaştırılması. *(Sayfa 33)*
- **[10prg02.c](./10prg02.c)**: İşaretçi (pointer) üzerinden orijinal değişkenin değerini değiştirme. *(Sayfa 35)*
- **[dizi_isaretci_erisim.c](./dizi_isaretci_erisim.c)**: Karakter dizilerine (string) işaretçi aritmetiği kullanarak erişim. *(Sayfa 49)*

#### 2. Bellek Takibi ve Aritmetik (Kaynak: Pointers2.pdf)
- **[bellek_takibi.c](./bellek_takibi.c)**: İşaretçi atamaları ve bellek hücrelerinin adım adım takibi (Vize odaklı). *(Sayfa 1)*
- **[dizi_adres_yazdir.c](./dizi_adres_yazdir.c)**: Dizi elemanlarının bellekte yan yana (ardışık) bulunduğunun kanıtı. *(Sayfa 5)*
- **[isaretci_aritmetik_test.c](./isaretci_aritmetik_test.c)**: İşaretçinin tuttuğu değer üzerinde toplama ve çıkarma işlemleri. *(Sayfa 7)*

#### 3. Fonksiyonlar ve Gelişmiş Uygulamalar (Kaynak: Pointers2.pdf)
- **[fonksiyon_pointer.c](./fonksiyon_pointer.c)**: Fonksiyonlara adres göndererek değer değiştirme (Referansla Çağırma). *(Sayfa 9)*
- **[iki_sayi_topla.c](./iki_sayi_topla.c)**: İşaretçi değişkenleri üzerinden veri girişi ve matematiksel işlem. *(Sayfa 11)*
- **[buyuk_sayi_bul.c](./buyuk_sayi_bul.c)**: İşaretçi kullanarak iki sayı arasından büyük olanı belirleme. *(Sayfa 13)*
- **[alfabe_yazici.c](./alfabe_yazici.c)**: ASCII değerleri ve `ptr++` yöntemiyle alfabeyi belleğe yazma. *(Sayfa 15)*
- **[alfabe_tek_dongu.c](./alfabe_tek_dongu.c)**: İşaretçi notasyonu `*(ptr + i)` ile tek döngüde dizi yönetimi. *(Sayfa 17)*

---
*Not: Bu dökümanlar üniversite ders notları referans alınarak vize hazırlığı için düzenlenmiştir.*
