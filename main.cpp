#include<iostream>

#include<string>

#include<Windows.h>

#include<iomanip>

#include<time.h>



/* this project was created by Muhammet Cömert


/*kutularin baslangic ve bitis kordinatlarini yazdirirken; baslangic noktasi kutunun sol alt kosesi,

bitis noktasida kutunun sag ust kosesi olarak yazdirilmistir. ayrica kutulari yerlestirirken (0,0) noktasindan
 
baslayip saga dogru yerlestirerek devam ediliyor. kutunun bitis noktasýnýn x degeri ayni zamanda bir sonraki kutunun

baslangic noktasinin x degeri olarak belirlenmektedir. ornegin kutunun bitis noktasi (a,b) ise bir sonraki kutunun
 
baslangic noktasi (a,c) olarak belirlenmektedir. yatayda yerlestirilecek kutularin boyutu (yani genislik degerlerinin toplami) 

uzayin genislik degerini asmasina kullanicinin girdigi maxboyut degerinden daha az bir fark kaldiysa geriye kalan kutulari 

maxboyut kadar +y ekseninde yukariya oteleyerek yine soldan saga dogru sirayla  yerlestirme yapilir.  */




using namespace std;



class Coordinate
{
public:

	Coordinate();                            // parametresiz kurucu
	Coordinate(int x, int y);                // parametreli kurucu
	void setStartCoordinate(int a, int b);   // baslangic noktalarini ayarla
	int  getStartCoordinateX();              // bitis noktasinin x degerini getir
	int  getStartCoordinateY();              // bitis noktasinin y degerini getir

private:

	double sx = 0;                           // kutunun baslangic noktasinin  kordinati
	double sy = 0;                           // kutunun baslangic noktasinin  kordinati    
	int fx, fy;                              // kutunun bitis noktasinin  kordinati.

};

//--------------------------------------------------------------------------------------------------.


class Kutu
{
public:

	Kutu();                                     // parametresiz kurucu
	Kutu(int ygnlk, int gnslk, int yksklk);	    // parametreli kurucu
	void setYogunluk(int ygnlk);                // yogunlugu ayarlar
	int  getYogunluk();                         // yogunlugu getirir
	void setGenislik(int gnslk);                // Genislik ayarlar
	int  getGenislik();                         // Genislik getirir
	void setYukseklik(int yksklk);              // Yukseklik ayarlar
	int  getYukseklik();                        // Yukseklik getirir
	void setKutuStartCordinate();               // Kutunun baslangic noktalarini ayarla
	int  getKutuStartCordinateX();              // Kutunun bitis noktasinin x degerini getir
	int  getKutuStartCordinateY();              // Kutunun bitis noktasinin y degerini getir

private:

	double yogunluk;                            // yogunluk degeri
	double genislik;                            // genislik degeri
	double yukseklik;                           // yukseklik degeri
	Coordinate kordinat;                        // kordinat klasinin nesnesi

};
//--------------------------------------------------------------------------------------------------------.

class Space
{
public:

	Space();                                             // parametresiz kurucu
	Space(int, int);                                     // parametreli kurucu
	void fillRandomBox(int, int, int);                   // kutulari yerlestiren Üye fonksiyon
	void printBoxCoordinates(int, int,int, int, int);    // kutularin baslangic-bitis kordinatlarini yazan Üye fonksiyon
	void printCenterOfMass(double,double,double);        // kutulari agirlik merkezini bulan Üye fonksiyon	                                 
	void uzayCiz();                                      // atama sonrasi kutularin üye uzaydaki yerini veren fonksiyon ****

private:

	Kutu kutu;                                          // kutu klasinin nesnesi
	int kutuSayisi;	                                    // kutu sayisini tutar
	int baslangic_x;                                    // kutunun baslangic degerinin x bileseni
	int baslangic_y;							        // kutunun baslangic degerinin y bileseni
	double toplamMX = 0;                                // kutle merk. hesaplamasinda (kutle*uzunluk) degerlerinin toplami
	double toplamMY = 0;                                // kutle merk. hesaplamasinda (kutle*uzunluk) degerlerinin toplami
	double toplamM = 0;                                 // kutle merk. hesaplamasinda kutle degerlerinin toplami
	int uzayGenisligi;                                  // uzayin geneislik degerini tutar
	int uzayYuksekligi;                                 // uzayin yukseklik degerini tutar
	int  uzay[40][40] = { };                            // varsayilan uzay boyutu

};
//-------------------------------------Main Fonksiyonu-----------------------------------------------.

int main()

{
	int kutuSayisi, maxBoyut, yogunluk, boyutX, boyutY;

	cout << "->Uzayin X ekseni boyutunu girin: ";
	cin >> boyutX;

	cout << "->Uzayin Y ekseni boyutunu girin: ";
	cin >> boyutY;

	cout << "->Kutu sayisini girin: ";
	cin >> kutuSayisi;

	cout << "->Maximum boyutu girin: ";
	cin >> maxBoyut;

	cout << "->Kutu yogunlugunu girin: ";
	cin >> yogunluk;
	cout << "---------------------------------------------------\n";

	if ((kutuSayisi * (maxBoyut*maxBoyut)) <= (boyutX * boyutY))
	{
		Space space(boyutX, boyutY);
		cout << "----------------------------------------------------\n";
		space.fillRandomBox(kutuSayisi, maxBoyut, yogunluk);
		space.uzayCiz();
	}
	else
	{
		cout << "->Hatali Veri girisi Yapildi...! " << endl;
		cout << "->Kutularin toplam alani uzayin alanindan buyuk." << endl;
		cout << "->Tekrar uygun veri girisi yapin." << endl;
	}

	cout << endl;

	system("pause");


	return 0;

}
//--------------------------Coordinate.cpp dosyasý-----------------------------------------------------.
Coordinate::Coordinate()
{
	cout << "parametresiz Coordinate kurucusu cagrildi" << endl;
}

Coordinate::Coordinate(int a, int b)
{
	setStartCoordinate(a, b);
}

void Coordinate::setStartCoordinate(int a, int b)
{
	sx = a;
}

int Coordinate::getStartCoordinateX()
{
	return sx;
}

int Coordinate::getStartCoordinateY()
{
	return sy;
}

//--------------------------Kutu.cpp---------------------------------------------------------------.

Kutu::Kutu()
{
	cout << "parametresiz kutu kurucu cagrildi" << endl;
}

Kutu::Kutu(int gnslk, int yksklk, int ygnlk = 1)
{
	setYogunluk(ygnlk);
	setGenislik(gnslk);
	setYukseklik(yksklk);
	int kordinat(int gnslk, int yksklk);
}

void Kutu::setYogunluk(int ygnlk)
{
	yogunluk = ygnlk;
}

int Kutu::getYogunluk()
{
	return yogunluk;
}

void Kutu::setGenislik(int gnslk)
{
	genislik = gnslk;
}

int Kutu::getGenislik()
{
	return genislik;
}

void Kutu::setYukseklik(int yksklk)
{
	yukseklik = yksklk;
}

int Kutu::getYukseklik()
{
	return yukseklik;
}

void Kutu::setKutuStartCordinate()
{
	kordinat.setStartCoordinate(genislik, yukseklik);
}

int Kutu::getKutuStartCordinateX()
{
	return kordinat.getStartCoordinateX();
}

int Kutu::getKutuStartCordinateY()
{
	return kordinat.getStartCoordinateY();
}

//------------------------------Space.cpp---------------------------------------------------------------

Space::Space()
{
	cout << "parametresiz space kurucusu cagrildi" << endl;
	cout << "uzay default olarak 40x40 olarak tanimlandi" << endl;
	uzayGenisligi  = 40;
	uzayYuksekligi = 40;
	uzay[uzayGenisligi][uzayYuksekligi];
}

Space::Space(int boyut_x, int boyut_y)
{
	uzayGenisligi  = boyut_x;
	uzayYuksekligi = boyut_y;

	uzay[uzayGenisligi][uzayYuksekligi];
}

void Space::fillRandomBox(int kutuSayisi, int maxBoyut, int yogunluk)
{

	srand(time(NULL));                                          // random fonksiyonunu pc nin time degeriyle besler.

	int baslangic_x = 0;  int  baslangic_y = 0;
	int temp1 = 0;        int temp2 = 0;

	for (int i = 0; i < kutuSayisi; i++)
	{
		int a = (1 + (rand() % maxBoyut));                  // max boyuta gore random x boyutunu belirler
		int b = (1 + (rand() % maxBoyut));                  // max boyuta gore random y boyutunu belirler

		kutu.setGenislik(a);                                // kutu genisligini setler
		kutu.setYukseklik(b);								// kutu yuksekligini setler
		kutu.setYogunluk(yogunluk);                         // kutu yogunlugunu setler
		kutu.setKutuStartCordinate();                       // kutu kordinatlarýný setler
		baslangic_x = kutu.getKutuStartCordinateX();        // kutunun boyut degeri
		baslangic_y = kutu.getKutuStartCordinateY();        // kutunun boyut degeri

		
		for (int j = temp1; j < temp1 + a; j++)             // kutunun icini 1 ile doldurur
		{
			for (int k = temp2; k < temp2 + b; k++)
			{
			   uzay[j][k] = i+1;
			}
		}

		cout << endl;
		printBoxCoordinates(i + 1, temp1,temp2, temp1 + a, temp2+b);    // kutunun kordinatlarini yazdirir
		cout << endl;

		if ((temp1 + maxBoyut) < uzayGenisligi)
		{
			temp1 += baslangic_x;                                   // yeni baslangic x degerini veririr
		}
		else
		{ 
			temp1 = 0;
		    temp2 += maxBoyut;
		}

		toplamMX += ((temp1 + ((double(a)) / 2))*(a*b*yogunluk));      // toplam kutle*uzunluk degerini tutan sayac
		toplamMY += ((temp2 + ((double(b)) / 2))*(a*b*yogunluk));                                      // toplam kutle*uzunluk degerini tutan sayac
		toplamM += a * b* yogunluk;                                    // toplam kutle degerini tutan sayac
	}

	printCenterOfMass(toplamMX, toplamMY, toplamM);                        // agirlik merkezini bulur

}

void Space::printBoxCoordinates(int kutuadi, int temp1,int temp2, int en, int boy)  // kutunun kordinatlarini yazdirir
{
	cout << "-> Kutu " << kutuadi << " in baslangic ve bitis kordinatlari : " << "("
		 << temp1 << "," << temp2 << ")" << "(" << en << "," << boy << ")" << endl;
}

void Space::printCenterOfMass(double mx, double my, double m)                                  // agirlik merkezini hesaplar ve yazdirir
{
	cout << "------------------------------------------------------------\n";
	double merkezX;
	double merkezY;
	merkezX = mx / m;
	merkezY = my / m;
	cout << "->uzayin agirlik merkezi kordinatlari : " <<"("<< merkezX<<","<< merkezY<<")" << "\n" << endl;
	cout << "------------------------------------------------------------\n";
}

void Space::uzayCiz()     // uzayin kutu yerleþimini gosterir. 
{

	int k;  int l;

	for (k = 0; k < uzayGenisligi; k++)
	{
		for (l = 0; l < uzayYuksekligi; l++)
		{
			cout << uzay[k][l]<<"   ";
		}

		cout << endl;
	}

}
