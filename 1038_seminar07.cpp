#include<iostream>
#include<string>

using namespace std;

class ExceptieAfisare {
private:
	string mesaj;
public:
	ExceptieAfisare(string mesaj) {
		this->mesaj = mesaj;
	}
	string getMesaj() {
		return mesaj;
	}
};

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

	//operator=
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

	Copil operator++() {
		this->varsta++;
		return *this;
	}

	Copil operator++(int) {
		Copil aux = *this;
		this->varsta++;
		return aux;
	}

	friend Copil operator+(int a, Copil c);
	friend ostream& operator<<(ostream& o, Copil c);
	friend istream& operator>>(istream& tastatura, Copil& c);
};
int Copil::contor = 1;
float Copil::alocatie = 150;

Copil operator+(int a, Copil c) {
	Copil rezultat = c;
	rezultat.greutate = c.greutate + a;
	return rezultat;
}

ostream& operator<<(ostream& o, Copil c) {
	if (c.nume != NULL) {
		o << "Nume: " << c.nume << endl;
		o << "Greutate: " << c.greutate << endl;
		o << "Varsta:" << c.varsta << endl;
		o << endl;
	}
	else {

		throw new ExceptieAfisare("Copilul nu are nume");
	}
	return o;
}

istream& operator>>(istream& tastatura, Copil& c) {
	char aux[20];
	cout << "nume:";
	tastatura >> aux;
	if (c.nume != NULL) {
		delete[]c.nume;
	}
	c.nume = new char[strlen(aux) + 1];
	strcpy(c.nume, aux);
	cout << "greutate:";
	tastatura >> c.greutate;
	cout << "Varsta:";
	tastatura >> c.varsta;
	return tastatura;

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

	Copil& operator[](int index) {
		if (index >= 0 && index < nrCopii) {
			return *(this->copii[index]);
		}
	}
};

void main() {

	Copil c;
	//Copil *pc = new Copil();
	//int a = 10;
	//cout << a;
	//try {
	//	cout << c << endl;
	//}
	//catch (ExceptieAfisare* exceptie) {
	//	cout << exceptie->getMesaj();
	//}

	//cin >> c;
	//cout << c;

	Copil c2("Gigel", 45, 15);
	Parinte p;
	p[0] = c2;
	cout<<p[0];


	c2 = ++c;
	//initial c=10;
	//dupa c2=11; c=11;

	c2=c++;
	//initial c=10
	//dupa c2=10; c=11

}