# Yapılacaklar Listesi

- Bu listede geliştiricilerin proje için yapılacaklar listesidir, her tamamlandığında OK, tamamlanmadığında boş bırakılır.
- Listeye eklenen görev için durum belirtileri:
	- `görev* | s: GG.AA.YY`: `s` harfi start kelimesinden gelir, görevin eklendiği tarihtir.
 	- `görev* | s: * | f: GG.AA.YY`: `f` finish kelimesinden gelir, görevin bittiği tarih eklenir.
  	- `görev* | s: * | d: GG.AA.YY`: `d` harfi delete kelimesinden gelir, görevin iptal olduğu tarih eklenir. 
- Geliştiricilerin projeye eklenmesini düşündüğü özellikleri buraya yazarak ister kendisi, ister bir başka geliştirici tarafından tamamlanabilir, topluluk istemediyse kaldırılabilir.
- "Ertelenenler" gibi kategoriler oluşturulabilir.

## Nasıl Yapılır?

- Tamamlanmış görevler için:
	- `- [`X`]` (2 köşeli parantez arasında `X` yazın.)

- Tamamlanmamış görevler için:
	- `- [ ]` (2 köşeli parantez arasında ` ` boşluk bırakın.)

### Örnek

- [X] Tamamlanmış bir görev örneği.
- [ ] Tamamlanmamış bir görev örneği.


### Tarih Örnekleri

- [X] Toplantı yapılması. | s: gg.10.25 | f: 06.11.25
- [ ] Lab bilgisayarında toplantı yapmak. | s: 06.11.25
- [ ] ✖️ iptal edilen X görevi | s: gg.aa.yy | d: gg.aa.yy

---

# Yapılacaklar

- [ ] Yarışma Sisteminin Geliştirilmesi
- [X] Herhangi bir geliştiricinin bu görevi "Tamamlandı" olarak işaretlemesi. <--
- [ ] Whatsapp grubunda soru sormak veya fikir önermek.
- [X] Geliştirici dışında katkı/commit eklemek.
- [X] Projeye ekleme yapıldığında elle onaylanabilmesi. | s: 05.11.25 | f: 08.11.25
- [X] README.md dosyaların güncellenip düzeltilmesi. | s: 07.11.25 | f: 27.02.26
