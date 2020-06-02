#include <iostream>

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
};

class zasilacz : public rezystor
{
public:
	float napiecie = 0;
	cewka ceweczka;

	zasilacz(float U = 0) : napiecie(U), rezystor(470)
	{
		std::cout << "Konstruktor zasilacza " << U << " V " << "pobierajacego prad o natezeniu " << U / r << " A\n" << "Uzyto tez cewki o imp. " << ceweczka.L << '\n';
	}
	~zasilacz()
	{
		std::cout << "Dekonstruktor zasilacza " << napiecie << "V\n";
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

};

int main()
{
	radio Grundig("Grundig", 99.7f);
	return 0;
}