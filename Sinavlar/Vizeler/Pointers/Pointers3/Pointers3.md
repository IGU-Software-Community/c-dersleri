# İşaretçiler (Pointers) - Bölüm 3: İleri Aritmetik ve Fonksiyonel Aktarım

Bu bölüm, işaretçilerin bellekte fiziksel olarak nasıl hareket ettiğini ve fonksiyonlar arasında verilerin adreslerle nasıl taşındığını açıklar.

## 1. Gösterici Aritmetiği ve Bayt Hesaplama
[cite_start]Bir işaretçiye `n` sayısı eklemek veya çıkarmak, bellekte o veri tipinin `n` eleman sonrasına/öncesine gitmek demektir[cite: 1].
[cite_start]Matematiksel karşılığı şudur: `Adres = Adres + (n * sizeof(Veri_Türü))`[cite: 2, 3].

* [cite_start]`char` işaretçisi 1 arttırıldığında adres **1 bayt** ilerler.
* [cite_start]`int` işaretçisi 1 eksiltildiğinde adres **4 bayt** geriler.
* [cite_start]`double` işaretçisine 10 eklendiğinde adres **80 bayt (10 * 8)** ileri fırlar.

## 2. Diziler ve Göstericiler (Kardeşlik Bildirgesi)
[cite_start]C dilinde dizinin adı, aslında dizinin ilk elemanının (`dizi[0]`) adresini saklayan bir işaretçidir[cite: 11].
Bu nedenle:
* [cite_start]`p = &kutle[0];` ile `p = kutle;` işlemleri bilgisayar için tıpatıp aynıdır[cite: 13, 14, 15].
* Bir dizinin i. elemanına indeks ile (`kutle[i]`) erişmek ile işaretçi aritmetiği ile (`*(p+i)`) erişmek tamamen aynı sonucu verir[cite: 15, 16, 17].

## 3. Parametre Aktarım Yöntemleri (Vize Favorisi)
Fonksiyonlara değişken gönderirken iki yöntem kullanılır:

### A. Değer Geçerek Aktarım (Pass by Value)
* Sadece verinin bir **kopyası** fonksiyona yollanır[cite: 34].
* [cite_start]Fonksiyon içinde kopyanın değeri değişse bile, ana programdaki (main) orijinal değişkenin değeri ASLA değişmez[cite: 35, 40].
* [cite_start]Bellekleri tamamen farklı iki bölgededir[cite: 56].

### B. Adres Geçerek Aktarım (Pass by Reference)
* Verinin kendisi yerine **bellek adresi** (pointer ile) yollanır[cite: 34].
* [cite_start]Fonksiyon, gönderilen adrese doğrudan giderek orijinal değerin üzerinde işlem yapar[cite: 63, 64].
* [cite_start]Yapılan her değişiklik kalıcıdır; fonksiyon bitip geri dönüldüğünde orijinal değişken değişmiş olur[cite: 35, 41, 42, 66].

*(Not: Sınavda `swap` (yer değiştirme) kodları verilip çıktı sorulursa, fonksiyona `&x` mi yoksa sadece `x` mi gönderildiğine dikkat etmelisin.)*
