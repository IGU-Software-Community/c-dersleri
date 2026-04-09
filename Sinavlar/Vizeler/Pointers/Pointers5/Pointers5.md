# İşaretçiler (Pointers) - Bölüm 5: calloc, realloc ve İleri Dinamik Bellek

Bu bölüm, Pointers 4'te öğrenilen `malloc` ve `free` temellerinin üzerine inşa eder: `calloc` ile sıfırlanmış bellek ayırma, `realloc` ile mevcut belleği yeniden boyutlandırma, dinamik dizide sıralama algoritması ve tüm kavramları birleştiren kapsamlı bir uygulama (Not Hesaplama Sistemi).

## 1. Pointer ile Dinamik Dizi Sıralama
[cite_start]`malloc` ile çalışma zamanında boyutu belirlenen bir dizi üzerinde **Selection Sort** (Seçmeli Sıralama) algoritması uygulanır[cite: 1, 2].

Algoritmanın mantığı: İç içe iki döngü ile dizinin her elemanı, kendinden sonraki tüm elemanlarla karşılaştırılır. Eğer `*(a+i) > *(a+j)` ise (yani önceki eleman daha büyükse), `tmp` geçici değişkeni ile yer değiştirilir.

Dikkat edilmesi gereken noktalar:
* Dış döngü `i < (n-1)` ile çalışır; son eleman karşılaştırılacak kimse kalmadığı için döngüye dahil edilmez.
* `scanf("%d", a + i);` ifadesinde `&` operatörü kullanılmaz çünkü `a + i` zaten bir adrestir (pointer aritmetiği).
* Elemanlara `*(a+i)` ile erişim, `a[i]` ile erişimle birebir aynıdır; burada pointer gösterimi tercih edilmiştir.

> **🔍 Uygulama İçin Bakınız:**
> * `dinamik_dizi_siralama.c`: malloc ile dinamik dizi oluşturup Selection Sort ile sıralama.

## 2. `calloc()` Fonksiyonu

### A. calloc Nedir?
[cite_start]`calloc`, `malloc`'a oldukça benzer bir dinamik bellek ayırma fonksiyonudur ve `stdlib.h` kütüphanesinde bulunur[cite: 4].

**Sözdizimi:**
```c
isaretci_adi = (tur *) calloc(eleman_sayisi, her_elemanin_boyutu);
```

### B. malloc ile calloc Arasındaki Farklar

**Fark 1 — Otomatik Sıfırlama:**
[cite_start]`malloc` tahsis ettiği bellek alanına hiçbir ilk değer atamaz; bellekte o an ne varsa (çöp veri) aynen kalır. `calloc` ise ayrılan alanın tüm elemanlarını otomatik olarak **0** yapar[cite: 5, 7].

Bu ne anlama gelir? `malloc` kullandığında dizinin elemanlarını kendin `p[i] = 0;` ile sıfırlamak zorundasın[cite: 9]. `calloc` kullandığında bu adımı atlayabilirsin çünkü elemanlar zaten 0'dır[cite: 15, 16].

**Fark 2 — Parametre Sayısı:**
[cite_start]`malloc` tek parametre alır (toplam byte miktarı), `calloc` ise iki parametre alır (eleman sayısı ve her elemanın boyutu)[cite: 6]:

| | `malloc` | `calloc` |
|---|---|---|
| Parametre | `malloc(n * sizeof(int))` | `calloc(n, sizeof(int))` |
| İlk Değer | Çöp veri (rastgele) | Otomatik 0 |
| Kullanım | Kendin sıfırla | Hazır sıfırlanmış |

[cite_start]`calloc` aslında arka planda bellek tahsisi yaparken `malloc`'u kullanır, ardından ayrılan bölgeyi sıfırlar[cite: 7].

**NULL Kontrolü (calloc için de zorunlu!):**
[cite_start]`calloc` da başarısız olabilir; döndürdüğü değer `NULL` ise bellek ayırma başarısız olmuştur[cite: 8]:
```c
dizi = (int*) calloc(eleman_sayisi, sizeof(int));
if (dizi == NULL) {
    printf("Yer ayirma islemi basarisiz!\n");
    return 1;
}
```

> **🔍 Uygulama İçin Bakınız:**
> * `malloc_vs_calloc.c`: malloc ile elle sıfırlama vs calloc ile otomatik sıfırlama karşılaştırması.
> * `calloc_kullanici_boyut.c`: Kullanıcıdan eleman sayısı alarak calloc ile dinamik dizi oluşturma (scanf doğrulama dahil).

### C. Dangling Pointer ve `p = NULL;`
[cite_start]`free(p);` çağrıldıktan sonra `p` hâlâ eski bellek adresini tutar. Bu adres artık geçersizdir ama pointer bunu bilmez[cite: 10, 11].

**Otel Benzetmesi (PDF'ten):**
Bir otel odasında kalıyorsun (bellek ayrıldı). Çıkış yaparken anahtarı resepsiyona verdin (`free`). Ama oda numarasını hâlâ ezberden biliyorsun (`p` içindeki adres). Eğer gidip o odaya eski anahtarınla girmeye çalışırsan (`p`'yi kullanmaya devam etmek), ya başkasının eşyalarını karıştırırsın ya da güvenlik seni yakalar. `p = NULL;` demek, hafızandan o oda numarasını tamamen silmektir[cite: 10].

**`p = NULL;` sonrası `*p` kullanmaya çalışırsan ne olur?**
[cite_start]NULL adresi (0), işletim sistemi tarafından rezerve edilmiş yasaklı bir bölgedir. `*p` ile bu adrese erişmeye çalışmak "Access Violation" (Erişim İhlali — `0xC0000005`) hatasıyla programı anında sonlandırır[cite: 14]. Bu aslında **iyi bir şeydir**: belirsiz bir çökme yerine, kesin ve tanımlı bir hata alırsın; hata ayıklaması çok daha kolay olur.

> **🔍 Uygulama İçin Bakınız:**
> * `dangling_pointer_demo.c`: `free` sonrası `p = NULL` yapılmazsa ne olduğu ve yapılırsa nasıl korunduğu.

## 3. `realloc()` Fonksiyonu

### A. realloc Nedir?
[cite_start]`realloc` (re-allocation = yeniden tahsis), daha önce `malloc` veya `calloc` ile ayrılmış bellek bloğunu **genişletmek** veya **daraltmak** amacıyla kullanılır[cite: 24].

**Sözdizimi:**
```c
yeniAlan = (tur *) realloc(eskiAlan, yeni_boyut_byte);
```

### B. Neden realloc Gerekli?
[cite_start]Program başında ayrılan bellek alanı ilerleyen kısımlarda az veya fazla gelebilir. `realloc` ile mevcut blok yeniden boyutlandırılır[cite: 25].

Basit örnek:
```c
int *p;
p = calloc(15, sizeof(int));       // 15 elemanlık alan
p = realloc(p, sizeof(int) * 20);  // 20 elemana genişlet
```
[cite_start]Bu kodda 15 elemanlık eski veri korunur, sonuna 5 eleman daha eklenir[cite: 26].

### C. Güvenli realloc Kalıbı (Kritik!)
[cite_start]Eğer `realloc` başarısız olursa `NULL` döndürür. Doğrudan `p = realloc(p, ...)` yazılırsa, `p`'nin eski adresi kaybolur ve o 15 elemanlık veriye bir daha ulaşılamaz. Bu riski önlemek için geçici bir pointer (temp) kullanılmalıdır[cite: 27]:

```c
int *temp;
temp = (int *) realloc(p, sizeof(int) * 20);
if (temp != NULL) {
    p = temp;  // Başarılıysa güncelle
} else {
    // Hata: p hâlâ eski yerini koruyor, veriler kaybolmadı!
    printf("Bellek genisletme basarisiz!\n");
}
```

### D. Önemli Notlar
[cite_start]`realloc` yeni tahsisat yaparken, belleğin eski bloğun yanında yer yoksa, bloğun **tamamını içerikleriyle birlikte** yeni bir bölgeye taşır. Bu yüzden döndürdüğü adres eskisinden farklı olabilir[cite: 25, 29].
[cite_start]`realloc` da `malloc` gibi yeni eklenen alana ilk değer vermez (eski veriler korunur, yeni alan çöp veri içerir)[cite: 27].

> **🔍 Uygulama İçin Bakınız:**
> * `not_hesaplama_sistemi.c`: `malloc` + `realloc` birlikte kullanımı, sonsuz döngüde veri girişi, giriş doğrulama ve ortalama hesaplama.

## 4. Kapsamlı Uygulama: Not Hesaplama Sistemi
[cite_start]Bu uygulama, bölümdeki tüm kavramları birleştirir: `malloc` ile başlangıç bellek tahsisi, `while(1)` sonsuz döngüsü ile kullanıcıdan süresiz not alma, `realloc` ile her yeni notta belleği genişletme, `scanf` doğrulama ve tampon temizleme, ortalama hesaplama ve `free` ile bellek iadesi[cite: 30-34].

Program akışı:
1. `malloc(sizeof(int))` ile 1 elemanlık başlangıç alanı aç.
2. `while(1)` döngüsünde kullanıcıdan not al.
3. Giriş doğrulama: sayı mı? (`scanf != 1`), aralık kontrolü (`0-100`), çıkış sinyali (`-1`).
4. Geçerli notu `*(notlar + i)` ile pointer aritmetiği kullanarak yaz.
5. `temp = realloc(notlar, (i+1) * sizeof(int))` ile belleği güvenli genişlet.
6. Döngü bitince toplam, ortalama hesapla ve `free(notlar)` ile temizle.

> **🔍 Uygulama İçin Bakınız:**
> * `not_hesaplama_sistemi.c`: Tüm kavramların birleştirildiği kapsamlı uygulama.

---

### 📘 Terimler Sözlüğü (Hiç Bilmeyenler İçin)

1. **Selection Sort:** Dizinin en küçük elemanını bulup başa, sonra ikinci en küçüğü ikinci sıraya koyarak sıralama yapan algoritma.
2. **calloc:** "Contiguous Allocation" — bellekte ardışık yer ayırıp tüm elemanları sıfırlayan fonksiyon.
3. **realloc:** "Re-allocation" — daha önce ayrılmış bellek bloğunu büyütme veya küçültme fonksiyonu.
4. **Dangling Pointer:** `free` ile serbest bırakılmış belleği hâlâ göstermeye devam eden tehlikeli işaretçi.
5. **Access Violation:** NULL veya yasaklı bir bellek adresine erişmeye çalışıldığında işletim sisteminin verdiği hata (`0xC0000005`).
6. **Temp Pointer:** `realloc` başarısızlığında orijinal veriyi kaybetmemek için kullanılan geçici işaretçi.
7. **Tampon (Buffer):** Klavye girdilerinin geçici olarak saklandığı bellek alanı; `getchar()` ile temizlenir.
8. **Memory Leak:** `free` yapılmayan bellek alanlarının birikmesiyle oluşan bellek sızıntısı.
