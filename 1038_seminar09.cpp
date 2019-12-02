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
protected:
	float greutate;
public:

	void setVarsta(int varsta) {
		if (varsta > 0) {
			this->varsta = varsta;
		}
	}

	int getVarsta() {
		return varsta;
	}

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
	operator int() {
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

class Adolescent :public Copil {
private:
	string liceu;
	float bursa;
public:
	Adolescent() :Copil() {
		liceu = "";
		bursa = 0;
	}
	Adolescent(string liceu, float bursa) 
		:Copil("Adolescent", 14, 50) {
		this->liceu = liceu;
		this->bursa = bursa;
	}

	Adolescent(const char* nume, int varsta, 
		float greutate, string liceu, float bursa)
		:Copil(nume, varsta, greutate) {
		this->liceu = liceu;
		this->bursa = bursa;
	}

	~Adolescent() {

	}

	Adolescent(const Adolescent& a) :Copil(a) {
		this->liceu = a.liceu;
		this->bursa = a.bursa;
	}

	Adolescent operator=(const Adolescent& a) {
		Copil::operator=(a);
		this->liceu = a.liceu;
		this->bursa = a.bursa;
		return *this;
	}

	friend ostream&operator<<(ostream& out, Adolescent a) {

		out << (Copil)a;
		out << "Liceu:" << a.liceu<<endl;
		out << "Bursa: " << a.bursa<<endl;
		return out;
	}

	friend istream& operator>>(istream& in, Adolescent& a) {
		
		in >> (Copil&)a;
		cout << "Liceu:";
		in >> a.liceu;
		cout << "Bursa:";
		in >> a.bursa;
		return in;
	}
};

void main() {
	Copil c;
	c.setVarsta(5);
	int val =(int) c;
	Adolescent a;
	//a.setVarsta(15);
	//cout << a.getVarsta();
	cin >> a;
	cout << a;
}