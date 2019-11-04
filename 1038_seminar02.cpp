#include<iostream>
#include<string>

using namespace std;

class Ciocolata {
public:
	string culoare;
	float greutate;
	int nrCuburi;
	char* producator;
	bool cuLapte;

	void afisareCiocolata() { //void afisareCiocolata(Ciocolata* this)
		std::cout << "Culoare: " << this->culoare << endl;
		cout << "Greutate: " << greutate << endl;
		cout << "Numar cuburi: " << nrCuburi << endl;
		cout << "Producator: " << producator << endl;
		cout << (cuLapte?"Cu lapte":"Fara lapte") << endl<<endl;
	}

	void citesteCiocolata() {
		cout << "Culoare:";
		cin >> culoare;
		cout << "Greutate:";
		cin >> greutate;
		cout << "Numar cuburi:";
		cin >> nrCuburi;
		char temp[20];
		cout << "Producator:";
		cin >> temp;
		producator = new char[strlen(temp) + 1];
		strcpy(producator, temp);
		cout << "Are lapte? 1-Da, 0-NU:";
		cin >> cuLapte;
	}

};

Ciocolata initializareCiocolata(string culoare, float greutate, int nrCuburi, const char* producator, bool cuLapte) {
	Ciocolata c;
	c.culoare = culoare;
	c.greutate = greutate;
	c.nrCuburi = nrCuburi;
	c.producator = new char[strlen(producator) + 1];
	strcpy(c.producator, producator);
	//strcpy_s(c.producator, strlen(producator) + 1, producator);
	c.cuLapte = cuLapte;
	return c;
}


void main() {
	Ciocolata c1=initializareCiocolata("Alba",200,12,"Milka",true);
	Ciocolata c2 = initializareCiocolata("Neagra", 300, 10, "Poiana", false);
	c1.afisareCiocolata();//afisareCiocolata(&c1)
	c2.afisareCiocolata();

	Ciocolata c3;
	c2.citesteCiocolata();
	c2.afisareCiocolata();

}