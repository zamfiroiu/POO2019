#include<iostream>

using namespace std;
enum Calitate{SLABA=1, MEDIE, BUNA};

struct Produs {
	int cod;
	float pret;
	Calitate calitate;
	char* denumire;
	string producator;
	bool perisabil;
};

Produs initializareProdus(int cod, float pret, Calitate calitate, const char* denumire, string producator, bool perisabil) {
	Produs p;
	p.cod = cod;
	p.pret = pret;
	p.calitate = calitate;
	//p.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
	p.denumire = new char[strlen(denumire) + 1];
	strcpy(p.denumire, denumire);
	p.producator = producator;
	p.perisabil = perisabil;
	return p;
}

void main() {
	Produs pix;
	pix = initializareProdus(1, 2.5, MEDIE, "Pix", "Bic", false);

	cout << pix.denumire << endl;

	Produs * p;
	p = &pix;

	cout << (*p).pret<<endl;
	cout << p->cod<<endl;
}

