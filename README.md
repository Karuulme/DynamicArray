Merhaba değerli okur,
Bu programda dinamik olarak, yani sabit olarak tanımlanan dizilerden farklı olarak, bir veri türünü sınırsız elemanda tutabilecek programı yazacağız.

İlk olarak işe `template`in ne olduğundan bahsedeyim. `Template` : Bir fonksiyona yada sınıfa atanan veri türüne göre değişkenlik gösteren ve bizim bu esneklikten yararlanabildiğimiz bir şablondur.

`C#` dan da bildiğimiz üzere sınırsız veri tutabilen sintaks yapısı olan `List<>` in aynısını biz burada `C/C++` ile yaptık.

Bir class oluşturduk ve adını `List `olarak belirledik. Programı açıklamadan önce bizim için temel olan bazı değişkenleri ve fonksiyonları açıklayalım.
Private olarak eklenen `_Lengh` dizimizin kaç elemandan oluştuğunu gösteriyor. Aynı şekilde  `T** StartPoint` de bize dizinin bellekteki başlangıç adresini veriyor.

Fark ettiyseniz,  classın hemen üstünde  tanımladığımız `template<class T>` , bize hangi tipte tanımlanırsa, o tip ile çalışacağımızı belirtiyor.

Tekrar `T** StartPoint` a gelirsek, tanımlanan tipin tipinde bellekte yer ayırmakta.  `*` yani `Pointer` in hepimiz ne olduğunu biliyoruz. Tanımlamak gerekirse, hangi tip ile belirtilirse o tipte, tipin bellekte kapladığı alan kadar, bellekte yer ayırmakta.

Peki `**` çift yıldız neden ?
Evet, burası çok önemli bir nokta, bizim pointer dediğimiz şeyin aslında bellekte bir yer ayrılmış ve içerisine sadece değer atanabilir durumda, fakat biz `Pointer to Pointer` yaklaşımını kullanacağız. Yani buda şu demek oluyor , programın genel yapısına bakıldığında, Biz her bir değer için o değer için bellekte bir yer ayırıp değeri onun içerisine aktarıyoruz, sonrada bu belleğin adresini, başlangıçta tanımladığımız `T** StartPoint` pointerini yeniden  genişleterek/tanımlayarak adresleri içerisine aktarıyoruz.

Buraya kadar kafanızda bir soru işareti yoksa, programa tanımlamalardan ve bir değer eklemeden başlayalım.

`main` içerisine classımızı int tipinde olacak şekilde tanımladık  `List<int> array `. İçerisine bir değer atamamız için `public` olarak `Add` fonksiyonu ekledik.
`Add` fonksiyonumuz tanımlanan `T` tipinde değer alacaktır. Aldığımız değeri `MemoryPointCreate` e bellekteki adresini gönderiyoruz. `MemoryPointCreate` e gelirsek, az önce bahsettiğim işlemi yapıyoruz. Bellekte `T`  tipinde bir pointer oluşturuyoruz. Burada `malloc` da kullanabilirsiniz işlem kalabalığından kurtulmak için `new T[1]` kullandım.
Ardından gönderilen veriyi, belelkte ayırdığımız yere aktarıyoruz ve verinin adresini kayıt edeceğimiz yeri ayarlamak için `MemoryExpansion` a gönderiyoruz.

 






