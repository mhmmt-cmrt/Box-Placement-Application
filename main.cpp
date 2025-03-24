#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<time.h>

/* this project was created by Muhammet Cömert


/*kutularin baslangic ve bitis kordinatlarini yazdirirken; baslangic noktasi kutunun sol alt kosesi,

bitis noktasida kutunun sag ust kosesi olarak yazdirilmistir. ayrica kutulari yerlestirirken (0,0) noktasindan
 
baslayip saga dogru yerlestirerek devam ediliyor. kutunun bitis noktasının x degeri ayni zamanda bir sonraki kutunun

baslangic noktasinin x degeri olarak belirlenmektedir. ornegin kutunun bitis noktasi (a,b) ise bir sonraki kutunun
 
baslangic noktasi (a,c) olarak belirlenmektedir. yatayda yerlestirilecek kutularin boyutu (yani genislik degerlerinin toplami) 

uzayin genislik degerini asmasina kullanicinin girdigi maxboyut degerinden daha az bir fark kaldiysa geriye kalan kutulari 

maxboyut kadar +y ekseninde yukariya oteleyerek yine soldan saga dogru sirayla  yerlestirme yapilir.  */

using namespace std;

class Coordinate
{
public:

	Coordinate():sx(0),sy(0) {}
	Coordinate(int a, int b)
	{
		setStartCoordinate(a, b);
	}
	void setStartCoordinate(int a, int b)
	{
		sx = a;
		sy = b;
	}
	int  getStartCoordinateX()
	{
		return sx;
	}
	int  getStartCoordinateY()
	{
		return sy;
	}

private:

	double sx;
	double sy;
};

class Box
{
public:
	Box():  density(1), width(1), height(1) {}
	Box(int width, int height, int density = 1)
	{
		setDensity(density);
		setWidth(width);
		setHeight(height);
	}
	void setDensity(int density)
	{
		this->density = density;
	}
	int  getDensity()
	{
		return density;
	}
	void setWidth(int width)
	{
		this->width = width;
	}
	int  getWidth()
	{
		return width;
	}
	void setHeight(int height)
	{
		this->height = height;
	}
	int  getHeight()
	{
		return height;
	}
	void setBoxStartCoordinate()
	{
		coordinate.setStartCoordinate(width, height);
	}

	int  getBoxStartCoordinateX()
	{
		return coordinate.getStartCoordinateX();
	}
	int  getBoxStartCoordinateY()
	{
		return coordinate.getStartCoordinateY();
	}

private:

	double density;
	double width;
	double height;
	Coordinate coordinate;
};

class Space
{
public:
	Space():spaceWidth(40), spaceHeight(40)
	{
		
		space = new int* [spaceWidth];
		for (int i = 0; i < spaceWidth; i++)
			space[i] = new int[spaceHeight]();
	
	}

	Space(int size_x, int size_y) : spaceWidth(size_x), spaceHeight(size_y)
	{
		space = new int* [spaceWidth];
		for (int i = 0; i < spaceWidth; i++)
			space[i] = new int[spaceHeight]();
	}

	~Space()
	{
		for (int i = 0; i < spaceWidth; i++)
			delete[] space[i];
		delete[] space;
	}
	void fillRandomBox(int boxCount, int maxSize, int density)
	{

		srand(time(NULL));

		int start_x = 0;  int  start_y = 0;
		int temp1 = 0;    int temp2 = 0;

		for (int i = 0; i < boxCount; i++)
		{
			int a = (1 + (rand() % maxSize));
			int b = (1 + (rand() % maxSize));

			box.setWidth(a);
			box.setHeight(b);
			box.setDensity(density);
			box.setBoxStartCoordinate();
			start_x = box.getBoxStartCoordinateX();
			start_y = box.getBoxStartCoordinateY(); 

			for (int j = temp1; j < temp1 + a && j < spaceWidth; j++) {
				for (int k = temp2; k < temp2 + b && k < spaceHeight; k++) {
					space[j][k] = i + 1;
				}
			}

			cout << endl;
			printBoxCoordinates(i + 1, temp1, temp2, temp1 + a, temp2 + b);
			cout << endl;

			long long volume = static_cast<long long>(a) * b * density;
			double centerX = temp1 + (static_cast<double>(a) / 2.0);
			double centerY = temp2 + (static_cast<double>(b) / 2.0);

			totalMX += centerX * volume;
			totalMY += centerY * volume;
			totalM += volume;

			if ((temp1 + maxSize) < spaceWidth)
			{
				temp1 += start_x;
			}
			else
			{
				temp1 = 0;
				temp2 += maxSize;
			}

		}

		printCenterOfMass(totalMX, totalMY, totalM);

	}
	void printBoxCoordinates(int boxName, int temp1, int temp2, int width, int height)
	{
		cout << "-> Kutu " << boxName << " için başlangıc ve bitiş kordinatları : " << "("
			<< temp1 << "," << temp2 << ")" << "(" << width << "," << height << ")";
	}
	void printCenterOfMass(double mx, double my, double m)
	{
		cout << "------------------------------------------------------------\n";
		double centerX;
		double centerY;
		centerX = mx / m;
		centerY = my / m;
		cout << "-> Uzayın Ağırlık Merkezi Koordinatları : " << "(" << centerX << "," << centerY << ")" << "\n" << endl;
	}
        void uzayCiz() 
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
	
private:

	Box box;
	int** space;	
	int boxCount = 0;
	int start_x = 0;
	int start_y = 0;
	double totalMX = 0;
	double totalMY = 0;
	double totalM = 0;
	int spaceWidth;
	int spaceHeight;

};

int main()
{
	int boxCount, maxSize, density, sizeX, sizeY;

	cout << "-> Uzayin X Ekseni Boyutu: ";
	cin >> sizeX;

	cout << "-> Uzayin Y Ekseni Boyutu: ";
	cin >> sizeY;

	cout << "-> Kutu Sayısı: ";
	cin >> boxCount;

	cout << "-> Maximum Boyut: ";
	cin >> maxSize;

	cout << "-> Kutu Yoğunluğu: ";
	cin >> density;

	if ((boxCount * (maxSize * maxSize)) <= (sizeX * sizeY))
	{
		Space space(sizeX, sizeY);
		cout << "------------------------------------------------------------";
		space.fillRandomBox(boxCount, maxSize, density);
		space.uzayCiz();
	}
	else
	{
		cout << "->Hatali Veri Girişi...! " << endl;
		cout << "->Kutuların Toplam Alani Uzayın Alanından Büyük." << endl;
		cout << "->Uygun Veri Girişi Yapın." << endl;
	}

	cout << endl;

	cin.get();

	return 0;
}

