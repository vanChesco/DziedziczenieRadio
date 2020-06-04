#include <iostream>

// Powino byc troche inaczej. Dziedziczenie stosuje sie, gdy klasa dziedziczaca, to odmiana klasy glownej na zasadzie samochod -> marka -> model
// w przypadku elementow skladowych po prostu korzysta sie w ciele klasy z obiektow wczesniej zdefiniowanej innej klasy bez dziedziczenia.
// 

class rezystor
{
protected:
	float r = 220;
	float moc = 0;

public:
	rezystor(float r = 0, float P = 0) : r(r), moc(P) 
	{
		std::cout << "Konstruktor rezystora " << r << " Ohm\n";
	}
	~rezystor()
	{
		std::cout << "Destruktor rezystora " << r << "Ohm\n";
	}

	void virtual funkcja()
	{
		std::cout << "Wlasnie stawiam opor pradowi\n";
	}
};

class kondensator
{
protected:
	float c = 0;
	std::string typ = "";

public:
	kondensator(float c = 0, std::string typ = "") : c(c), typ(typ)
	{
		std::cout << "Konstruktor kondensatora " << c << " uF\n";
	}
	~kondensator()
	{
		std::cout << "Destruktor kondensatora " << c << " uF\n";
	}

	void funkcja()
	{
		std::cout << "Wlasnie gromadze ladunek\n";
	}
};

class cewka
{
public:
	float L = 0;

public:
	cewka(float l = 0) : L(l)
	{
		std::cout << "Konstruktor cewki " << L << "uT\n";
	}
	~cewka()
	{
		std::cout << "Dekonstruktor cewki " << L << "uT\n";
	}

	void funkcja()
	{
		std::cout << "Wlasnie transformuje prad na pole magnetyczne\n";
	}
};

class zasilacz : public rezystor, public kondensator, public cewka
{
public:
	float napiecie = 0;

	
	zasilacz(float U = 0) : napiecie(U), rezystor(470), cewka(60), kondensator(220)
	{
		std::cout << "Konstruktor zasilacza " << U << " V " << "pobierajacego prad o natezeniu " << U / r << " A\n" << "Uzyto tez cewki o imp. " << L << '\n';
	}
	~zasilacz()
	{
		std::cout << "Dekonstruktor zasilacza " << napiecie << "V\n";
	}

	void funkcja()
	{
		std::cout << "Wlasnie wytwarzam zasilanie\n";
	}
};

class radio : public zasilacz
{
protected:
	std::string marka = "";
	float uhf = 0;

public:
	radio(std::string model, float uhf) : marka(model), uhf(uhf), zasilacz(220)
	{
		std::cout << "Tworze radio z zasilaczem o wydajnosci " << zasilacz::napiecie / r << ", model: " << marka << ", na czest.: " << uhf << " MHz\n";
	}

	void funkcja()
	{
		std::cout << "Wlasnie demoduluje FM na dzwiek\n";
	}

};

int main()
{
	rezystor R{ 23 };
	kondensator C{ 110 };
	cewka L{ 40 };
	radio Grundig("Grundig", 99.7f);
	rezystor* wsk;

	wsk = &Grundig;

	wsk->funkcja();

	return 0;
}