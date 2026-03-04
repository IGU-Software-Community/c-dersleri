#include <stdio.h>

/*

	bu dosya, C programlama dilinde bir dosyada minimum olması gerekenleri gösterir:
	
	1. satıdaki "#include", harici olarak bir kütüphane veya dosyayı bu dosyaya çağrırır:
		- bu ifade aslında bir “preprocessor directive” yani derlemeden önce çalışan bir ön işlemci komutudur, derlenecek (yazılan kodların) kodların çalıştırılması için getirilen modüller.
		- '#' karakteri çağrılan dosyayı bu dosyaya kopyalar.
		- çağrılan dosya "<>" arasında yazılır: <DOSYA.h>
		- '.h' başlık "header" anlamına gelir.

	2. C programlama dili sayısal bir dildir:
		- main fonksiyonu her C programlama dilinde zorunlu tek giriş noktası.

		- "int main(){}": 'main' adında bir fonksiyon tanımlanır.
			- "int": fonksiyon sonunda 'return 0;' yazdığı için program bu satıra gelince programa '0' değeri döndürür ve 0 bir integer olduğu için fonksiyon 'int' diye tanımlanır.
		- return 0: programın bitirmesini sağlar.

		- main sağında bulunan () parantezler:
			- içinde parametre yani değer koyulabilen bir yapısı var, dıştan gelen verileri burada tutulup sonradan kullanılabilir.

*/

int main(/* parametreler */){

	// kodlar buraya yazılır.

	return 0;
}