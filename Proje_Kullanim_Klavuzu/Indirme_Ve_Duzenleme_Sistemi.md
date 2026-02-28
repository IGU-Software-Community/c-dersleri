# İNDİRME VE DÜZENLEME SİSTEMİ

> [!WARNING]
> daha detaylı anlatım için lütfen [Proje Kullanım Klavuzu](https://github.com/IGU-Software-Community/c-dersleri/tree/main/Proje_Kullanim_Klavuzu)'na bakınız.

> [!CAUTION]
> projede bulunan `.git` klasörünü **asla dokunmayın**.

Bu proje doğrudan main branch üzerinde çalışacak şekilde yapılandırılmıştır. Katılımcıların proje dosyalarına erişebilmesi ve düzenleme yapabilmesi için yönetici onayıyla davet edilmesi gerekir.

1. Katılım ve Erişim İzni
   Projeye katkı yapmak isteyen öğrenciler önce yöneticiden izin almak zorundadır. Yönetici, katılmak isteyen kullanıcının GitHub kullanıcı adını aldıktan sonra, e-posta adresine davet (invite) gönderir. Daveti kabul eden kullanıcı projeye yazma izni kazanır ve main branch üzerinde düzenleme yapabilir.
   Katkı talebi için iletişim adresi: [igu2025gh@hotmail.com](mailto:igu2025gh@hotmail.com)

2. Projeyi İndirme (Klonlama)
   Daveti kabul ettikten sonra proje kendi bilgisayarına şu şekilde indirilir:

```
git clone https://github.com/IGU-Software-Community/c-dersleri.git
cd c-dersleri
```

3. Git Kullanıcı Bilgisini Ayarlama **(Zorunlu İlk Adım)**
   Eğer ilk kez Git kullanıyorsanız veya commit sırasında aşağıdakine benzer bir uyarı alırsanız:

```
Author identity unknown
*** Please tell me who you are.
Run
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```
   Bu durumda, kendi adınızı ve GitHub e-posta adresinizi yazarak aşağıdaki komutları çalıştırın:

```
git config --global user.name "Adınız Soyadınız"
git config --global user.email "github_email_adresiniz@example.com"
```

   Bu ayarları bir kez yaptıktan sonra, tüm projelerde geçerli olur.
   Eğer sadece bu proje için geçerli olmasını istiyorsanız --global parametresini kaldırabilirsiniz.


4. Çalışmaya Başlamadan Önce Son Güncellemeleri Alma (Zorunlu)
   Yerelde çalışmaya başlamadan önce ana depodaki en güncel halleri alın:

```
git switch main
git fetch origin
git pull origin main
```

Not: Rebase sırasında çatışma (conflict) oluşursa ilgili dosyaları düzeltin, ardından:

```
git add <duzeltilen-dosyalar>
git rebase --continue
```

5. Klasör Ekleme ve Düzenleme
   Her öğrenci yalnızca kendi klasöründe çalışmalıdır. Klasör adı Ad_Soyad formatında olmalı, Türkçe karakter kullanılmamalıdır.
   Örnek yapı:

```text
ana proje dizini /
│
├─ Halil_Hattab   <== örnek klasör adı
├─ CanerSen       <== örnek klasör adı
├─ Ayse-yilmaz    <== örnek klasör adı
├─ esma-kara      <== örnek klasör adı
└─ README.md      <== proje bilgilendirmesi
```

```
mkdir Ad_Soyad
cd Ad_Soyad
echo "// ilk örnek dosya" > ornek.c
```

6. Değişiklikleri Kaydetme ve Gönderme
   Yapılan değişiklikler doğrudan main branch’ine eklenir:

```
git add .
git commit -m "Ad_Soyad klasörü içinde ornek.c eklendi"
git push origin main
```

Eğer push sırasında “önce günceli çek” uyarısı alırsanız, tekrar:

```
git pull --rebase origin main
git push origin main
```

7. Yönetici Onayı ve Denetim
   Her commit yöneticiler tarafından düzenli olarak gözden geçirilir. Uygun olmayan değişiklikler (örneğin başkasının klasörüne müdahale) geri alınabilir veya silinebilir. Proje bütünlüğü düzenli aralıklarla kontrol edilir.

> [!NOTE]
> ### Önemli Not
> Yaptığınız değişiklikleri göndermeden önce, yeni güncellemelerin olup olmadığına bakın. Eğer varsa senkronize edin yoksa gönderin. (Bu konuda AI'dan yardım alabilirsiniz.

> [!WARNING]
> ### MÜDAHALE
> Yazdığınız kodlara başkası tarafından müdahale edilirse, dosyalarınızı tekrar düzenleyip gönderin veya durumu [proje yöneticisi](mailto:khalil.khattab@ogr.gelisim.edu.tr) ne bildirin (email).
