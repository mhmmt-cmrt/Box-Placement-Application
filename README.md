# kutu-yerlestirme-uygulamasi
2 boyutlu uzayda sınırları belirli dikdörtgen şeklinde bir bölge tanımlandığını düşünelim. Bu uzayın tamamen içi boş
olduğunu ve herhangi bir kütleye sahip olmadığını hayal edelim.
Bu uzay içerisine birden fazla sayıda dikdörtgen şeklinde kutular yerleştirmek istiyoruz. Ancak, hesaplamayı
kolaylaştırmak için aşağıdaki kısıtlamaları veriyoruz;
● Uzaya yerleştirilecek bütün dikdörtgenler aynı yoğunlukta olacak, Örneğin, 1x1 boyutlu birim karenin kütlesi 1
kg iken, 3x1 bir dikdörtgenin kütlesi 3 kg olarak ele alınabilir.
● Uzaya yerleştirilecek objeler eksenlere dik yerleştirilmek zorundadır. Örneğin, bir 3x1 boyutlu dikdörtgenin
başlangıç koordinatı (1,1) ise bitiş koordinatı <(4,2)> olabilir.
● Uzaya yerleştirilecek nesnelerin alanı uzayın alanından az olmak zorundadır.
● Kutu başlangıç köşe koordinatları ve boyut ölçüleri tam sayı olarak düşünülmelidir.
Kutu sinifi (x,y) koordinatları, width,height ve density özellikleri ile tanımlanmalıdır. Koordinat bilgileri kutunun baş
köşesine ait ve diğer köşe koordinatları artan veya eşit yönde hesaplanacaktır.
Bir uzay birden çok kutu içerebilir. Kutuları uzaya yerleştirirken boyut ozellikleri ve yogunluk girilecek. Kutuların uzayda
çakışmayacak şekilde kutu konumlari otomatik olarak belirlenebilecektir. Çakışma olursa çakışma olan kutu için
yeniden yerleştirme yapılacaktır.
Kutular uzaya yerleştirildikten sonra kutuların başlangıç, bitiş koordinatları ve uzayın ağırlık merkezi ekrana ve bir
dosyaya yazılacaktır. Boşlukta bulunan ve birbirinden belli mesafe uzaklıkta olan iki farkli boyuttaki objenin ağırlık
merkezleri aşağıdaki linkteki gibi bulunabilir.
https://www.khanacademy.org/science/physics/linear-momentum/center-of-mass/v/center-of-mass-equation
https://www.khanacademy.org/science/physics/linear-momentum/center-of-mass/a/what-is-center-of-mass
