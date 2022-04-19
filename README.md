Merhaba değerli okur,
Bu programda dinamik olarak, yani sabit olarak tanımlanan dizilerden farklı olarak, bir veri türünü sınırsız elemanda tutabilecek programı yazacağız.

İlk olarak işe `template`in ne olduğundan bahsedeyim. `Template` : Bir fonksiyona yada sınıfa atanan veri türüne göre değişkenlik gösteren ve bizim bu esneklikten yararlanabildiğimiz bir şablondur.

`C#` dan da bildiğimiz üzere sınırsız veri tutabilen sintaks yapısı olan `List<>` in aynısını biz burada `C/C++` ile yaptık.

Bir class oluşturduk ve adını `List `olarak belirledik. Programı açıklamadan önce bizim için temel olan bazı değişkenleri ve fonksiyonları açıklayalım.
Private olarak eklenen `_Lengh` dizimizin kaç elemandan oluştuğunu gösteriyor. Aynı şekilde  `T** StartPoint` de bize dizinin bellekteki başlangıç adresini veriyor.

Fark ettiyseniz,  classın hemen üstünde  tanımladığımız `template<class T>` , bize hangi tipte tanımlanırsa, o tip ile çalışacağımızı belirtiyor.

Tekrar `T** StartPoint` a gelirsek, tanımlanan tipin tipinde bellekte yer ayırmakta.
 






