**Selamlar**

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
Ardından gönderilen veriyi, belelkte ayırdığımız yere aktarıyoruz ve verinin adresini kayıt edeceğimiz yeri ayarlamak için `MemoryExpansion` a verinin adresini gönderiyoruz.

Listenin ilk kaydını yapmamız çok kolay, Listenin ilk değeri için listenin uzunluğunu kontrol ediyoruz. `_Lengh` i bir kez arttırıyoruz, `StartPoint` i değerlerin adresini tutabileceği alan kadar yani `_Lengh` kadar yer ayırıyoruz. Ardından ayırdığımız yerin 0. indexine  değerin adresini aktarıyoruz.
```
_Lengh++;
StartPoint = new T * [_Lengh];
StartPoint[0] = NValue;
```

2. Değerimizi ekleyelim ve programın bizi asıl ilgilendirdiği yere gelelim. 
```
 _Lengh++;
T** NewStartPoint = StartPoint;
StartPoint = new T * [_Lengh];
for (int i = 0; i < _Lengh-1; i++)
{
    StartPoint[i] = NewStartPoint[i];
}
StartPoint[_Lengh - 1] = NValue;
free(NewStartPoint);
```
Aynı şekilde gönderdiğimiz değerler ilkinden sonra buraya gelecektir. Program kodlarına bakarsak, `_Lengh` değerini 1 arttırıyoruz. Biz bellekten yeni boyutta bir yer ayıracağız, bir yeni boyutta bir yer ayırdığımızda önceki yerimizin adresini kayıp olacağı için bu adresi başka bir yere geçici olarak `NewStartPoint ` e aktarıyoruz.
`StartPoint = new T * [_Lengh]` tam burada, değerlerin adreslerini tutan `StartPoint` in boyutunda bellekten yeni bir yer ayırıyor.

Peki şimdi ne olacak ? Bellekten yeni bir yer tahsis etmeden önce önceki boyutun adresini `NewStartPoint ` e aktarmıştık hatırlarsanız. Şimdi eski değerleri bellekten yeni tahsis ettiğimiz yere aktarıyoruz `StartPoint[i] = NewStartPoint[i]`.
Eski değerleri yeni tahsis edilen yere aktardık. En son gönderilen değerin adresinide `StartPoint[_Lengh - 1] = NValue`  yani `StartPoint` in en son indexine aktarıyoruz.
`_Lengh - 1` dememizin sebebi indexlerin 0 dan başladığı için 1 eksiğini alıyoruz.

Peki ne olacak bu `NewStartPoint` e ? 

`NewStartPoint` bu arkadaşımız bizim `StartPoint`'in eski adresini tuttuğu için bellekte o alanı serbest bırakmamız gerekiyor. `free(NewStartPoint)`  `free` fonksiyonu kullanarak eski alanımızı serbest bırakıyoruz.

 `public` alanında yazılan fonksiyonlar kullanıcının yada sizin ihtiyaçlarınıza göre değişiklik gösterebilir. `Read()` de mesela tüm değerleri konsola yazdırmakta. `Lengh()`de  ise dizinin uzunluğunu geri döndürüyor.
`GetIndex()` de istenilen indexdeki değeri geri döndürüyor.
