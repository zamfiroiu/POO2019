#include<iostream>

using namespace std;

class Copil {
private:
	static float alocatie;
	static int contor;
	const int cod;
	char* nume;
	int varsta;
	float greutate;
public:
	Copil() :cod(contor), varsta(7), greutate(20) {
		contor++;
		this->nume = NULL;
	}

	Copil(const char* nume, int varsta, float greutate) :cod(contor++) {
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

	Copil(const Copil& c) :cod(contor++) {
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

	Copil operator+(Copil c) {
		Copil rezultat = *this;
		rezultat.greutate = this->greutate + c.greutate;
		return rezultat;
	}

	Copil operator+(int a) {
		Copil rezultat = *this;
		rezultat.greutate = this->greutate + a;
		return rezultat;
	}
	Copil operator+=(Copil c) {
		this->greutate += c.greutate;
		return*this;
	}

	bool operator>(Copil c) {
		return this->varsta > c.varsta;
	}
	explicit operator int() {
		return this->varsta;
	}

	friend Copil operator+(int a, Copil c);
};
int Copil::contor = 1;
float Copil::alocatie = 150;

Copil operator+(int a, Copil c){
	Copil rezultat = c;
	rezultat.greutate = c.greutate + a;
	return rezultat;
}

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
			delete copii[i];
		}

		if (this->copii != NULL) {
			delete[]this->copii;
		}
	}
};

void main() {

	Copil c1("Popescu",6,20);
	Copil c2("Ionescu", 8, 30);
	Copil c3("Vasilescu", 4, 15);

	c3 = c1 + c2;
	c3 = c1 + 3;
	c3 = 3 + c2;

	c2=c3 += c1;
	if (c2 > c3) {

	}

	int a = (int)c1;
}