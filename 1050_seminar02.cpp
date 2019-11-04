#include<iostream>
#include<string>

using namespace std;

class Rochie {
public:
	string culoare;
	int marime;
	char* material;
	float pret;
	bool noua;

	void afisareRochie() { //void afisareRochie(Rochie* this)
		cout << "Culoare:" << this->culoare<<endl;
		cout << "Marime:" << marime << endl;
		cout << "Material:" << material << endl;
		cout << "Pret:" << pret << endl;
		cout << (noua?"Este noua":"Este veche");
		cout << endl << endl;
		//if (noua)
		//	cout << "este noua";
		//else
		//	cout << "este veche";
	}

	void citesteRochie() {
		cout << "Culoare:";
		cin >> culoare;
		cout << "Marime:";
		cin >> marime;
		char temp[20];
		cout << "Material:";
		cin >> temp;
		material = new char[strlen(temp) + 1];
		strcpy(material, temp);
		cout << "Pret:";
		cin >> pret;
		cout << "Este noua(1-DA; 0-NU):";
		cin >> noua;
	}

	Rochie(string culoare, int marime, const char* material, float pret, bool noua) {
		this->culoare = culoare;
		this->marime = marime;
		this->material = new char[strlen(material) + 1];
		strcpy(this->material, material);
		this->pret = pret;
		this->noua = noua;
	}
	Rochie() {
		this->culoare = "Galbena";
		marime = 40;
		this->material = new char[strlen("In") + 1];
		strcpy(this->material, "In");
		this->pret = 50;
		this->noua = true;
	}

	void initializareRochie(string culoare, int marime, const char* material, float pret, bool noua) {
		
		this->culoare = culoare;
		this->marime = marime;
		this->material = new char[strlen(material) + 1];
		strcpy(this->material, material);
		this->pret = pret;
		this->noua = noua;
	}
};

//Rochie initializareRochie(string culoare, int marime, const char* material, float pret, bool noua) {
//	Rochie r;
//	r.culoare = culoare;
//	r.marime = marime;
//	r.material = new char[strlen(material) + 1];
//	strcpy(r.material, material);
//	r.pret = pret;
//	r.noua = noua;
//	return r;
//}

void main() {
	Rochie r1("Alba", 34, "Matase", 200, true);
	//r1.initializareRochie("Alba", 34, "Matase", 200, true);
	Rochie r2("Rosie", 36, "Bumbac", 25, false);
	//r2.initializareRochie("Rosie", 36, "Bumbac", 25, false);
	r1.marime = 32;
	r1.afisareRochie(); //afisareRochie(&r1)
	r2.afisareRochie();
	 
	Rochie r3("", 0, "", 0, false);
	r3.citesteRochie();
	r3.afisareRochie();
	r2.afisareRochie();

}