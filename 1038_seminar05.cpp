#include<iostream>

using namespace std;

class Copil {
public:
	static float alocatie;
	static int contor;
	const int cod;
	char* nume;
	int varsta;
	float greutate;
public:
	Copil():cod(contor),varsta(7), greutate(20){
		contor++;
		this->nume = NULL;
	}

	Copil(const char* nume, int varsta, float greutate):cod(contor++) {
		this->varsta = varsta;
		this->greutate = greutate;
		if (nume != NULL) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = NULL;
		}
	}

	Copil(const Copil& c):cod(contor++) {
		this->varsta = c.varsta;
		this->greutate = c.greutate;
		if (c.nume != NULL) {
			this->nume = new char[strlen(c.nume) + 1];
			strcpy(this->nume, c.nume);
		}
		else {
			this->nume = NULL;
		}
	}

	~Copil() {
		if (this->nume) {
			delete[]this->nume;
		}
	}

	Copil& operator=(const Copil& c) {
		this->varsta = c.varsta;
		this->greutate = c.greutate;
		if (c.nume != NULL) {
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(c.nume) + 1];
			strcpy(this->nume, c.nume);
		}
		else {
			this->nume = NULL;
		}
		return *this;
	}
};
int Copil::contor = 1;
float Copil::alocatie = 150;


class Parinte {
	int nrCopii;
	Copil** copii;

public:
	Parinte() {
		nrCopii = 2;
		copii = new Copil*[2];
		for (int i = 0; i < 2; i++) {
			copii[i] = new Copil();
		}
	}

	~Parinte() {
		for (int i = 0; i < 2; i++) {
			delete copii[i]
		}

		if (this->copii != NULL) {
			delete[]this->copii;
		}
	}
};

void main() {

	Copil c1;
	Copil c2("Gigel", 4, 10);
	Copil c3 = c2;
	cout << c2.nume << endl;
	strcpy(c3.nume, "Ion");
	cout << c2.nume << endl;

	Copil c4;
	c4 = c2;


}