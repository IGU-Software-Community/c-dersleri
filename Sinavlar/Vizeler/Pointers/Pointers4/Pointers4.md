# İşaretçiler (Pointers) - Bölüm 4: Uygulamalar, const ve Dinamik Bellek

Bu bölüm, önceki bölümlerde öğrenilen işaretçi temellerinin pratik uygulamalarını, `const` belirtecinin pointer'larla kullanımını ve dinamik bellek yönetiminin (`malloc`, `free`) temellerini kapsar.

## 1. Pointer ile Sıralama (Swap Uygulaması)
[cite_start]Pointers 3'te öğrenilen `swap` (yer değiştirme) mantığı burada gerçek bir probleme uygulanır: üç sayıyı küçükten büyüğe sıralama[cite: 1].

Algoritmanın özü şudur: `degerdegistir(&a, &b)` fonksiyonu, iki değişkenin **adreslerini** alır ve geçici bir değişken (`gecici`) yardımıyla içeriklerini kalıcı olarak takas eder. `main` içinde hangi çiftlerin karşılaştırılacağına `if` koşullarıyla karar verilir (önce x>y, sonra x>z, sonra y>z).

Önemli nokta: Fonksiyona `&x` gönderiyoruz, `x` değil. Eğer sadece `x` göndersek, kopya üzerinde işlem yapılır ve `main`'deki orijinal değer **asla** değişmez.

> **🔍 Uygulama İçin Bakınız:**
> * `pointer_siralama.c`: Üç sayıyı pointer ile küçükten büyüğe sıralama.

## 2. Pointer ile String İşlemleri
[cite_start]Bir `char *pt` işaretçisi, bir karakter dizisinin başlangıç adresine atanarak tüm string üzerinde tek tek karakter dolaşımı yapılabilir[cite: 2, 3].

### A. fgets vs scanf
[cite_start]`scanf("%s", ...)` fonksiyonu ilk boşluk karakterinde okumayı durdurur; bu yüzden "Gelisim Universitesi" gibi boşluk içeren metinleri okuyamaz[cite: 6, 7].
[cite_start]`fgets(str, sizeof(str), stdin)` ise satır sonuna (Enter) kadar tüm karakterleri (boşluklar dahil) güvenli bir şekilde okur. `sizeof` sayesinde dizi kapasitesi aşılmaz[cite: 6].

| Özellik | `scanf("%s", ...)` | `fgets(..., stdin)` |
|---|---|---|
| Boşluk Okuma | İlk boşlukta durur | Satır sonuna kadar okur |
| Güvenlik | Sınır belirtilmezse tehlikeli | `sizeof` ile tam koruma |
| Enter Karakteri | Enter'ı okumaz, tamponda bırakır | Enter'ı da okuyup string'e ekler |

### B. `\n` Temizleme Sorunu
[cite_start]`fgets`, Enter karakterini (`\n`) de diziye ekler. Eğer bu temizlenmezse, ileride string karşılaştırma ve yazdırma işlemlerinde beklenmeyen satır kaymaları yaşanır[cite: 8, 9].

**Yöntem 1 — `strcspn` ile (Tek Satır):**
```c
str1[strcspn(str1, "\n")] = '\0';
```
`strcspn`, string içinde `\n` karakterinin indeksini bulur; o konuma `\0` yazılarak Enter silinir[cite: 8].

**Yöntem 2 — Manuel Döngü ile:**
```c
char *p = str1;
while (*p != '\0') {
    if (*p == '\n') { *p = '\0'; break; }
    p++;
}
```
Pointer ile karakter karakter ilerleyerek `\n` bulunduğunda yerine `\0` konur[cite: 9].

### C. Döngü Koşulundaki Çift Kontrol
[cite_start]`while(*pt != '\0' && *pt != '\n')` koşulunda iki durum kontrol edilir[cite: 4]:
* **`\n` kontrolü:** Kullanıcı "Ali" yazıp Enter bastığında dizi `{'A','l','i','\n','\0'}` olur. `\n` kontrolü olmadan döngü bu Enter karakterini de harf sanıp sayar.
* **`\0` kontrolü:** Eğer dizi tamamen dolarsa (ör. 5 elemanlık diziye "Selam" yazılırsa) `\n`'e yer kalmaz, sadece `\0` konur. Bu kontrol olmadan döngü hafızada komşu verilere dalar ve program çöker.

> **🔍 Uygulama İçin Bakınız:**
> * `sesli_sessiz_sayici.c`: Pointer ile string üzerinde dolaşıp sesli/sessiz harf sayma.

## 3. Pointer ile Faktöriyel Hesaplama
[cite_start]Bir fonksiyon birden fazla sonuç üretecekse veya hesaplanan değeri çağıran fonksiyona kalıcı olarak geri aktarmak gerekiyorsa, sonucu pointer parametresi ile yazarız[cite: 10, 11].

`findFactorial(int n, long long *f)` fonksiyonu, hesaplanan faktöriyeli `*f` ile doğrudan `main`'deki `fact` değişkenine yazar. `return` ile döndürmek yerine adres üzerinden yazmanın avantajı, fonksiyonun hem sonucu hem de hata durumunu (negatif sayı) yönetebilmesidir.

### Veri Tipleri ve Kapasite
[cite_start]Faktöriyel gibi hızla büyüyen hesaplamalarda `int` yetersiz kalır[cite: 13]:

| Tip | Format | Boyut | Yaklaşık Limit |
|---|---|---|---|
| `int` | `%d` | 4 Byte | ~2 Milyar |
| `long` | `%ld` | 4-8 Byte | Sisteme göre değişir |
| `long long` | `%lld` | 8 Byte | ~9 Kentilyon |

20! = 2.432.902.008.176.640.000 değeri `int`'e sığmaz, `long long` gerektirir.

> **🔍 Uygulama İçin Bakınız:**
> * `faktoriyel_hesapla.c`: Pointer ile faktöriyel hesabı ve negatif sayı kontrolü.

## 4. `const` Belirteci ve Pointer Kombinasyonları
[cite_start]`const` anahtar kelimesi bir değişkenin değiştirilemez olduğunu bildirir. İşaretçilerle birlikte kullanıldığında üç farklı kombinasyon ortaya çıkar[cite: 14, 15, 16]:

### A. Sabit Gösterici — `int *const ptr = &x;`
[cite_start]Pointer'ın **kendisi** sabittir; bir kez atandıktan sonra başka bir adrese yönlendirilemez (`ptr = &y` → HATA). Ancak gösterdiği adresteki değer değiştirilebilir (`*ptr = 100` → GEÇERLİ)[cite: 14].

### B. Sabit Veriye Gösterici — `const int *ptr = &x;`
[cite_start]Adresteki **değer** bu pointer üzerinden değiştirilemez (`*ptr = 100` → HATA, salt okunur). Ancak pointer başka bir adrese yönlendirilebilir (`ptr = &y` → GEÇERLİ)[cite: 15].

### C. Sabit Veriye Sabit Gösterici — `const int *const ptr = &x;`
[cite_start]Hem adres hem değer sabittir. Ne `ptr = &y` ne de `*ptr = 100` yapılabilir[cite: 16].

**Özet Tablo:**

| Tanımlama | Adres Değişir mi? (`ptr = &y`) | Değer Değişir mi? (`*ptr = 5`) |
|---|---|---|
| `int *const` | HAYIR | EVET |
| `const int *` | EVET | HAYIR |
| `const int *const` | HAYIR | HAYIR |

### Fonksiyon Parametrelerinde const
[cite_start]Fonksiyon parametresinde `const` kullanmak, fonksiyonun aldığı veriyle ne yapabileceğini sınırlar[cite: 18]:

| Tanım | Ne Yapabilir? |
|---|---|
| `void f(int *p)` | Her şeyi yapabilir |
| `void f(const int *p)` | Sadece okuyabilir, değeri değiştiremez |
| `void f(int *const p)` | Değeri değiştirebilir ama pointer'ı başka adrese yönlendiremez |

> **🔍 Uygulama İçin Bakınız:**
> * `const_pointer_demo.c`: Üç const kombinasyonunun çalışan gösterimi.

## 5. Dinamik Bellek Yönetimi

### A. Neden Dinamik Bellek?
[cite_start]Şimdiye kadar kullandığımız dizilerde eleman sayısı derleme zamanında (compile-time) belirleniyordu; buna **statik bellek** denir[cite: 23, 24].
[cite_start]Gerçek dünyada dizi boyutu önceden bilinmeyebilir: bir sınıfta 100 öğrenci varken diğerinde 50 olabilir. Sabit üst sınır koymak ya hafızayı israf eder ya da yetmez[cite: 25].
[cite_start]Dinamik bellek yönetiminde dizi boyutu programın çalışma anında (run-time) belirlenir ve ihtiyaca göre yer tahsis edilir[cite: 26].

### B. RAM Bellek Düzeni
```
+---------------------------+ <-- Yüksek Adresler
|   STACK (Statik)          | --> Yerel değişkenler (int x, dizi[10])
|   (Hızlı ama Küçük)      | --> Kendi kendine yönetilir.
+---------------------------+
|   BOŞ ALAN (Gap)          | --> Bellek burada büyür/küçülür.
+---------------------------+
|   HEAP (Dinamik)          | --> malloc, calloc, realloc ile açılır.
|   (Yavaş ama Geniş)      | --> SEN yönetmelisin (free)!
+---------------------------+ <-- Düşük Adresler
|   DATA & CODE             | --> Programın kendi kodları.
+---------------------------+
```
[cite_start]Yerel değişkenler Stack'te otomatik yönetilir; `malloc` ile açılan alan ise Heap'te yer alır ve **senin sorumluluğundadır**[cite: 22].

### C. `malloc()` Fonksiyonu
[cite_start]`stdlib.h` kütüphanesinde bulunur. Çalışma zamanında bellekten istenilen uzunlukta yer ayırır[cite: 27, 28].

**Sözdizimi:**
```c
isaretci_adi = (tur *) malloc(eleman_sayisi * sizeof(tur));
```

[cite_start]Başarılı olursa ayrılan alanın başlangıç adresini, başarısız olursa `NULL` (0) döndürür[cite: 28].

**Neden `sizeof` kullanılır?**
[cite_start]`p = malloc(5);` yazdığında 5 **byte** ayrılır. `int` 4 byte olduğu için bu sadece 1 eleman + 1 byte'lık anlamsız bir alan olur. Farklı sistemlerde `int` boyutu değişebilir[cite: 32].
[cite_start]`p = malloc(sizeof(int) * 5);` ile her sistemde garanti 5 elemanlık blok ayrılır[cite: 33].

**Neden `(int *)` tür dönüşümü?**
[cite_start]`malloc` geriye `void *` (türsüz adres) döndürür. `(int *)` ile döndürülen adresi doğru türe dönüştürerek hem güvenlik hem okunurluk artar[cite: 34].

**NULL Kontrolü (Zorunlu!):**
[cite_start]Bellek ayırma her zaman başarılı olacağı garanti değildir. `malloc` başarısız olursa `NULL` döndürür[cite: 30]:
```c
int *p = (int *) malloc(sizeof(int) * 5);
if (p == NULL) {
    printf("Hata: Yeterli bellek yok!\n");
    return 1;
}
```

[cite_start]Statik dizide `int dizi[1000000000];` yazdığında program daha başlamadan çöker çünkü Stack bu kadar alanı kaldıramaz. Dinamik bellekte ise aynı isteği `malloc` ile yaptığında, başarısızlığı `NULL` kontrolü ile yakalar ve programı düzgün şekilde sonlandırabilirsin[cite: 35].

> **🔍 Uygulama İçin Bakınız:**
> * `malloc_temel.c`: `malloc` ile dinamik bellek ayırma, NULL kontrolü ve `sizeof` kullanımı.
> * `dinamik_dizi.c`: Kullanıcıdan boyut alarak dinamik dizi oluşturma, doldurma ve yazdırma.

### D. `free()` Fonksiyonu
[cite_start]`malloc` ile ayrılan bellek alanını işletim sistemine iade eden fonksiyondur[cite: 39].

**Sözdizimi:**
```c
free(isaretci_adi);
```

[cite_start]`free` çağrıldıktan sonra pointer'ı `NULL`'a atamak iyi bir pratiktir; aksi halde pointer hâlâ eski adresi gösterir (dangling pointer) ve yanlışlıkla erişim denenirse tanımsız davranış oluşur[cite: 37].

**Neden `free` Şart?**
[cite_start]C dilinde Java veya C# gibi otomatik çöp toplayıcı (Garbage Collector) yoktur. Programcı `malloc` ile aldığı her alanı `free` ile iade etmelidir[cite: 40, 41].
[cite_start]Program sonunda otomatik boşaltma yapılsa da, uzun süre çalışan programlarda `free` yapılmayan bellek birikir ve sistemi yavaşlatır (memory leak)[cite: 42, 43].

**Doğru Kullanım Kalıbı:**
```c
int *p = (int *) malloc(sizeof(int) * 25);
// ... p ile işlemler ...
free(p);      // Belleği iade et
p = NULL;     // Pointer'ı güvenli hale getir
```

> **🔍 Uygulama İçin Bakınız:**
> * `dinamik_dizi.c`: `free` kullanımı ve bellek iadesi (`free` sonrası adresin `NULL`'a atanması dahil).
> * `bellek_adresi_izleme.c`: Stack ve Heap adreslerinin farklı bölgelerde olduğunun ispatı.

---

### 📘 Terimler Sözlüğü (Hiç Bilmeyenler İçin)

1. **Swap:** İki değişkenin içeriklerini geçici bir değişken yardımıyla yer değiştirme işlemi.
2. **fgets:** Klavyeden güvenli metin okuma fonksiyonu; boşlukları da okur, dizi sınırını aşmaz.
3. **strcspn:** Bir string içinde belirtilen karakterin kaçıncı sırada olduğunu bulan kütüphane fonksiyonu.
4. **Faktöriyel:** Bir sayının 1'e kadar olan tüm pozitif tam sayılarla çarpımı (5! = 5×4×3×2×1 = 120).
5. **long long:** 8 byte'lık tam sayı tipi; `int`'in taşacağı kadar büyük sayıları saklar.
6. **const:** Bir değişkenin veya pointer'ın değiştirilemez olduğunu bildiren anahtar kelime.
7. **Stack (Yığın):** Yerel değişkenlerin otomatik olarak yönetildiği, hızlı ama sınırlı bellek bölgesi.
8. **Heap (Öbek):** `malloc` ile programcının yönettiği, geniş ama yavaş bellek bölgesi.
9. **malloc:** "Memory Allocation" — çalışma zamanında bellekten yer ayırma fonksiyonu.
10. **free:** `malloc` ile ayrılmış bellek alanını işletim sistemine iade eden fonksiyon.
11. **NULL:** Geçersiz veya boş bir adresi temsil eden özel değer (0).
12. **Dangling Pointer:** `free` ile serbest bırakılmış belleği hâlâ göstermeye devam eden tehlikeli işaretçi.
13. **Memory Leak:** `free` yapılmayan bellek alanlarının birikmesiyle oluşan bellek sızıntısı.
