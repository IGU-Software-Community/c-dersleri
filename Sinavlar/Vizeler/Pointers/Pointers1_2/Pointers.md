# İşaretçiler (Pointers)

İşaretçiler, C programlama dilinin en temel ve güçlü yapı taşlarından biridir. Bellek yönetimi ve verimlilik açısından kritik bir öneme sahiptirler.

## 1. Temel Kavram: Adres ve İşaretçi
Bilgisayar belleğindeki her bir **bellek hücresinin¹** kendine özgü, benzersiz (unik) bir adresi bulunur. Normal bir değişken tanımlandığında, bu adresleme işlemi sistem tarafından arka planda yapılır; buna **Örtük Adresleme²** denir.

Bir değişkenin bellek adresini alıp başka bir değişkende saklama işlemine ise **Açık Adresleme³** denir. İşte bu adres bilgisini saklayan özel değişkenlere **İşaretçi (Pointer)** adı verilir. Bir işaretçi, veri değerinin kendisini değil, o verinin bellekte nerede bulunduğunu (adresini) tutar.

> **🔍 Uygulama İçin Bakınız:**
> * `kilo_ortuk.c`: Örtük adresleme mantığını gösterir.
> * `kilo_acik.c`: Adres operatörü ve işaretçi ile belleğe erişimi gösterir.

## 2. İşaretçi Tanımlama ve Tür Uyumu
Bir işaretçi tanımlanırken, işaret edeceği **veri türü⁴** ile aynı türde olması zorunludur.

* **Tanım Formatı:** `veri_türü *isaretci_adi;`
* **Örnek:** `int *p;` (Bir tamsayı adresini tutacak işaretçi)
* **Örnek:** `float *f_ptr;` (Bir ondalıklı sayı adresini tutacak işaretçi)

Buradaki `*` sembolü, tanımlanan değişkenin normal bir değişken değil, bir işaretçi olduğunu belirtir.

> **🔍 Uygulama İçin Bakınız:** > * `tamsayi_isaretci.c`: `int` türünde işaretçi tanımlama ve kullanım örneği.

## 3. Temel Operatörler: `&` ve `*`
Sınavlarda en çok karıştırılan ve sorulan iki temel operatör şunlardır:

* **`&` (Adres Operatörü):** Bir değişkenin önünde kullanıldığında, o değişkenin bellekteki adresini verir. "Bu değişken nerede?" sorusunun cevabıdır.
* **`*` (İçerik Operatörü⁵):** Bir işaretçinin önünde kullanıldığında, o işaretçinin gösterdiği adresteki **değere** ulaşmamızı sağlar. "Bu adreste ne var?" sorusunun cevabıdır.

**Örnek Mantık:**
`ptam = &tam;` denildiğinde, `ptam` işaretçisine `tam` değişkeninin adresi atanır. Artık `*ptam` ifadesi, `tam` değişkeninin içindeki sayısal değere eşittir.

> **🔍 Uygulama İçin Bakınız:**
> * `10prg01.c`: `&` ve `*` operatörlerinin temel farklarını gösterir.
> * `10prg02.c`: İşaretçi üzerinden orijinal değişkenin değerini nasıl değiştirebileceğinizi gösterir.

## 4. Bellek Adreslerini Yazdırmak (`%p`)
Bir değişkenin veya işaretçinin tuttuğu adresi ekrana yazdırmak için `printf` fonksiyonunda `%p` **format belirleyicisi⁶** kullanılır. Bu belirleyici, adresleri genellikle **heksadesimal⁷** sayı sisteminde görüntüler.

> **🔍 Uygulama İçin Bakınız:**
> * `kilo_acik.c`: Adreslerin `%p` ile nasıl yazdırıldığını gösterir.

## 5. İşaretçi Aritmetiği
İşaretçiler üzerinde toplama, çıkarma, arttırma ve eksiltme işlemleri yapılabilir. Buna **işaretçi aritmetiği⁸** denir. Ancak buradaki matematik, standart sayısal matematikten farklı işler.

Bir işaretçi arttırıldığında (`ptr++`), adresi sadece 1 birim artmaz. İşaretçinin gösterdiği veri türünün bellekte kapladığı bayt miktarı kadar ileriye gider.
* Eğer bir tamsayı işaretçisi arttırılırsa, bellek adresi bir sonraki tamsayının başlayacağı yere (genellikle 4 bayt ileriye) atlar.

## 6. İşaretçiler ve Karakter Dizileri (Strings)
C dilinde karakter dizileri, bellekte ardışık olarak dizilmiş karakterlerden oluşur.
* Bir dizinin adı, aslında o dizinin ilk elemanının bellek adresini temsil eder.
* Program, bu adresten başlayarak belleği okur ve **sonlandırıcı karakter⁹** olan (`\0`) işaretini görene kadar devam eder.

> **🔍 Uygulama İçin Bakınız:**
> * `dizi_isaretci_erisim.c`: Karakter dizisi elemanlarına işaretçi aritmetiği ile ulaşımı gösterir.

---

### 📘 Terimler Sözlüğü (Hiç Bilmeyenler İçin)

1.  **Bellek Hücresi:** Bilgisayarın hafızasındaki numaralı küçük kutucuklar. Her kutunun içine bir veri koyulur.
2.  **Örtük Adresleme:** Bilgisayarın işleri senin ruhun bile duymadan, "gizlice" ve otomatik olarak halletmesi.
3.  **Açık Adresleme:** Bilgisayara "şu adresteki kutuyla ilgileniyorum" diyerek parmağınla göstermen.
4.  **Veri Türü:** Kutunun içine ne koyacağının cinsi (tam sayı mı, harf mi, ondalıklı sayı mı?).
5.  **İçerik Operatörü (*):** Bir evin adresine sahipken, kapıyı açıp "içeride kim var?" diye bakmanı sağlayan anahtar.
6.  **Format Belirleyicisi:** Bilgisayara "ekrana bir şey yazdırırken bunu şu formatta (örneğin adres olarak) yazdır" deme şekli.
7.  **Heksadesimal:** Bilgisayarların adresleri kısa yazmak için kullandığı, içinde hem rakam hem de harf (A, B, C...) olan sayı sistemi.
8.  **İşaretçi Aritmetiği:** Adresler üzerinde matematik yapmak; ama 1+1=2 gibi değil, "bir sonraki kutuya zıpla" şeklinde çalışır.
9.  **Sonlandırıcı Karakter (\0):** Bilgisayara "yazı burada bitti, okumayı bırakabilirsin" diyen görünmez dur tabelası.
