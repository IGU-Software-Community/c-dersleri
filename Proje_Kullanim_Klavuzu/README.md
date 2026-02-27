# Proje Kullanım Klavuzu

> 👋 Merhaba İGÜ Yazılım Mühendisliği öğrencileri!  
> Bu rehber, **C-Dersleri Topluluk Projesi**ne katkıda bulunurken proje düzenini korumanız için hazırlandı.

- Rehber sayesinde projeyi bozmadan nasıl ekleme yapabileceğinizi ve olası durumlara karşı nasıl davranılması gerektiğini anlatır.

## Gereksinimler

- [Git](https://git-scm.com/install/) adresinden git indirin:
	- win10/11: [Win10/11](https://git-scm.com/install/windows) yada `winget install -e --id Git.Git`
	- mac cihazları için: [git mac](https://git-scm.com/install/mac)
	- [Linux](https://git-scm.com/install/linux)

	- indirdikten sonra kontrol edin: `git --version`, bu komu bize version numarası verirse indirme başarılı demektir.

	- git kullanıcı bilgisi:
		- git indirdikten sonra, yapacağınız değişiklikleri adınıza kaydedilmesi için bu komutları ilgili yerlerini kendinize göre uyarlayıp çalıştırın:
			```
			git config --global user.name "Github'taki adınız"
			git config --global user.email "github_email_adresiniz@example.com"
			```

	- Git programı hakkında Wiki makalesi (meraklılar için): [Git (Yazılım)](https://tr.wikipedia.org/wiki/Git_(yaz%C4%B1l%C4%B1m))

- [Github](https://github.com/):
	- bu [adresten](https://github.com/) hesap oluşturun ardından başvurmak için proje yöneticilerine iletişime geçin.
	- projeye eklenebilmeniz için github'a kayıtlı olan email adresinize davet linkleri gelecektir. (proje katılım linki, topluluk & takım katılım linki).

	- Github platformu hakkında Wiki makalesi (meraklılar için): [Github](https://tr.wikipedia.org/wiki/GitHub)

- [GitHub CLI (gh)](https://cli.github.com/) (meraklılar için):
	- gitHub hesabınızla komut satırından işlem yapabilmenizi sağlar (örneğin: repo klonlama, PR açma, issue oluşturma, login işlemleri).
	- indirme bağlantıları:
		windows: `winget install --id GitHub.cli` (bu komutta hata alırsanız bu komutu çalıştırın: `winget update` ardından tekrar deneyin. yine olmazsa [bağlantıdan](https://cli.github.com/) indirebilirsiniz.)
	- macOS: `macOS: brew install gh`
	- Linux (Debian/Ubuntu):
	```
	type -p curl >/dev/null || sudo apt install curl -y
	curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
	sudo chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg
	echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null
	sudo apt update
	sudo apt install gh -y
	```
	- kurulum sonrası kontrol edin: `gh --version` versiyon numarası görünüyorsa indirme başarılıdır.
	- gitHub CLI ile giriş yapmak için: `gh auth login` burada github hesabınızın olması şart, komut panelini takip ederek giriş yapabilirsiniz.
	- daha fazla bilgi için: [CLI Kullanım Kılavuzu](https://cli.github.com/manual/)

	> [!NOTE]
	> gh aracı zorunlu değildir, isteğe bağlı olarak kurulabilir

	> [!NOTE]
	> kullandığınız linux'a göre indirme komutu değişebilir, ona göre uygun olanı bulup indirebilirsiniz.


## Proje Düzenleme Aşamaları:
- indirmek:
	- projeyi `git clone https://github.com/IGU-Software-Community/c-dersleri.git` komutu ile indirme:
		- `git`: programın adı, programı başlatır. sağdaki tüm değerler git programına parametre olarak gider.
		- `clone`: sağında belirtilen linkteki bulunan projeyi bulunduğunuz diziye indirir.
		- `https://*`: projenin linki/adresi.
		- proje linki/adresi yapısı:
			- `github.com`: [Github](https://github.com/) sitesinin barındığı alan adı (domain).
			- `IGU-Software-Community`: kullanıcı/topluluk adı/username.
			- `c-dersleri`: projenin adı, `.git` eklentisi ise projenin `.git` dosyasını çağırır.

- proje yapısı:
	- projeyi indirdikten sonra bulunduğunuz dizine `c-dersleri` adında bir klasör, ve içinde projeye ait olan tüm verileri barındırır.
	- `c-dersleri` içinde gizli olan `.git` klasörü tüm projenin beyni ve kalbidir. bozulursa tüm projenin kaybolmasına neden olabilir.
> [!WARNING]
> projede bulunan `.git` klasörünü <ins>**asla dokunmayın**</ins>. bozulması halinde proje yöneticisine danışın ve yaptığınız güncellemeleri projeye yüklemeyin.

- projeyi düzenleme:
	- eğer ilk kez düzenliyorsanız:
		- projeyi indirdikten sonra `c-dersleri` adlı klasöre girin, ilgili komut:
			- `cd c-dersleri`: bu komut sizi projenin içine alır; bundan sonraki git komutları bu dizin içinde çalışmalıdır.
> [!WARNING] 
> `git` komutları sadece `c-dersleri` klasörü altında çalışır.

- kendi adınız ve soyadınızla bir klasör oluşturun, örneğin:
	- `Halil_Hattab`, boşluk karakteri yerine '_' karakterini kullanın, ilgili komut: `mkdir Adiniz_Soyadiniz`
		> dosya adlarında boşluk, türkçe karakter (ç, ğ, ı, ö, ş, ü) ve . (nokta) ile biten adlar kullanmayın. sadece harf, rakam ve _ karakteri kullanılmalıdır.

	- klasörü oluşturduktan sonra içine girip `*.c` uzantılı (c programlama dilini barındıran dosyaların uzantısı: .c) dosyalarınızı yazabilirsiniz.
		> kodunuzu sadece `.c` uzantılı dosyalara yazın. `.txt`, `.cpp` veya `.h` gibi uzantılar kabul edilmez.
	- eğer daha önce düzenlediyseniz:
		- diğer klasörleri asla dokunmayacaksınız, sadece kendinize ait oluşturduğunuz klasöre girip düzenleme yapacaksınız.

- projeyi github'a atmak:
	- eğer site üzerinden tercih ediyorsanız, oradan yüklemeleri yapabilirsiniz. hatta orada bile dosyaları oluşturabilirsiniz.
	- eğer terminal üzerinden tercih ediyorsanız: projeyi github'a atmadan önce, github'taki son güncellemeleri local, yani düzenleme yaptığınız klasöre indirin:
		- komutlar (bunlar örnek, kendinize göre ayarlayın. mesela Halil_Hattab yerine Adınız_Soyadınız olarak ayarlayın.) :
		```bash
		# 1. uzak depodaki (GitHub) son değişiklikleri getirir
		git fetch origin

		# 2. kendi dalınızı (main) uzak sürüme göre günceller, 
		# aynı zamanda kendi değişikliklerinizi korur
		git pull --rebase origin main

		# 3. kendi klasörünüzde yaptığınız değişiklikleri ekleyin
		git add .

		# 4. yaptığınız değişikliğe kısa ve açıklayıcı bir mesaj yazın
		git commit -m "Halil_Hattab: döngüler ödevi eklendi"

		# 5. değişiklikleri GitHub'a gönderin
		git push origin main
		```
		- `git fetch` ve `git pull`:
			- bu iki komut, [uzak depodaki](https://github.com/IGU-Software-Community/c-dersleri/) son değişiklikleri indirip kendi bilgisayarındaki sürümle birleştirir.

		> ilk push işleminde GitHub sizden kullanıcı adı ve Personal Access Token isteyebilir. Token, GitHub profilinizde → Ayarlar → Geliştirici Ayarları → Kişisel Erişim Jetonları → Fine-grained tokens kısmından oluşturulur. (AI yardımı alabilirsiniz.)


> [!WARNING]
> Eğer `error: invalid path` veya `merge conflict` gibi bir hata alırsanız, projeyi kapatıp proje yöneticisine bildirin.  
> Hatalı dosya adı veya yanlış klasör düzenlemesi GitHub sisteminde bozulmaya neden olabilir.  
> Lütfen **başka bir öğrencinin klasörüne dokunmayın** ve yalnızca kendi klasörünüzde çalışın.

## Sorun Giderme
- `error: invalid path` → Dosya adında yasaklı karakter var. kendi klasörünüzdeki tüm dosya adlarını kontrol edin.
- `merge conflict` → Başka biri aynı satırı değiştirmiş. proje yöneticisine haber verin.
- `fatal: Authentication failed` → GitHub erişim token’ınızı yenileyin.
- `permission denied (publickey)` → SSH kullanıyorsanız anahtarınızı GitHub hesabınıza ekleyin.
- Windows PowerShell kullananlar için uyarı:
	- powerShell bazen tırnak işaretlerini farklı algılar. eğer hata alırsanız komutları Git Bash üzerinde çalıştırın.

---

## Proje Yöneticileri
- iletişime geçmek isterseniz:
	- [Github](https://github.com/trs-1342)
	- [hattab1342@gmail.com](mailto:khalil.khattab@ogr.gelisim.edu.tr)