# İşaretçiler (Pointers) - Bölüm 2: Bellek Takibi ve Fonksiyonlar

Bu dosya, işaretçilerin bellekteki verileri nasıl manipüle ettiğini, birbirlerine nasıl atandığını ve fonksiyonlar içindeki kullanımını öğretmeyi amaçlar.

## 1. İşaretçi Atamaları ve Bellek İzleme¹
Bir işaretçi başka bir işaretçiye atanabilir. Bu durumda her iki işaretçi de aynı bellek adresini göstermeye başlar.

* **Örnek:** `p3 = &b;` ve ardından `p2 = p3;` işlemi yapılırsa, artık hem `p2` hem de `p3` değişkenleri `b` değişkeninin adresini tutar. Birinde yapılan değişiklik diğerini de etkiler çünkü her ikisi de aynı "kutuyu" göstermektedir.



## 2. Parantezlerin Önemi ve Öncelik Sırası²
Sınavlarda en çok puan kaybettiren noktalardan biri `*` ve `++` operatörlerinin birlikte kullanımıdır:
* `(*p2)++`: Bu işlem, `p2`'nin gösterdiği adresteki **değeri** 1 arttırır.
* `*p2++`: Bu işlem (parantez yoksa), önce adresi bir sonraki hücreye kaydırır, sonra oradaki değere bakar.

**Hocanın Sorabileceği Detay:** `b` değişkeninin değeri 20 ise ve `p2` onu gösteriyorsa; `(*p2)++` işlemi sonrası `b` değeri 21 olur.

## 3. ASCII ve Karakter İşaretçileri
Bilgisayar için harfler aslında sayılardan ibarettir. Örneğin, 'A' harfinin sayısal karşılığı **ASCII Tablosunda³** 65'tir.

* Bir döngü içinde `*ptr = 65 + x;` yapıldığında ve `x` her seferinde arttırıldığında, işaretçinin gösterdiği bellek hücrelerine sırasıyla 'A', 'B', 'C' gibi harfler yazılır.
* `ptr++` komutu ile işaretçi bir sonraki bellek hücresine (bir sonraki harfin yerine) zıplatılır.

## 4. Değer Değiştirme (Swap) ve Referansla Çağırma⁴
Normal fonksiyonlarda bir değişkeni gönderdiğinizde sadece kopyası gider. Ancak iki değişkenin değerini kalıcı olarak değiştirmek (yer değiştirmek) istiyorsanız işaretçi kullanmalısınız.

* Fonksiyona değişkenin kendisi değil, adresi (`&a`, `&b`) gönderilir.
* Fonksiyon içinde bu adresler kullanılarak asıl bellek hücrelerine ulaşılır ve değerler takas edilir.



## 5. İşaretçi ile Dizi Erişimi
Bir dizinin elemanlarına ulaşmak için sadece indeks (dizi[0]) değil, işaretçi aritmetiği de kullanılır.
* `ptr = dizi;` atamasından sonra `ptr` üzerinden tüm elemanlar arasında **döngüsel ilerleme⁵** yapılabilir.
* `ptr++` her dendiğinde bir sonraki dizi elemanına geçilir.

---

### 📘 Terimler Sözlüğü (Anlamayanlar İçin)

1.  **Bellek İzleme (Memory Tracing)*:** Kod çalışırken bilgisayarın hafızasında hangi sayının hangi adrese gittiğini adım adım takip etme yöntemi.
2.  **Öncelik Sırası**:** Matematikteki işlem önceliği gibi, bilgisayarın önce parantez içini mi yoksa yanındaki işareti mi yapacağına karar verme kuralı.
3.  **ASCII Tablosu***:** Harflerin, rakamların ve sembollerin bilgisayarın anlayacağı sayısal karşılıklarını içeren evrensel liste.
4.  **Referansla Çağırma (Call by Reference)****:** Bir fonksiyona verinin kopyasını değil, verinin "ev adresini" (referansını) vererek fonksiyona asıl veriyi değiştirme yetkisi verme.
5.  **Döngüsel İlerleme (Iteration)*****:** Bir listenin veya dizinin elemanları üzerinde tek tek, sırayla gezme işlemi.
