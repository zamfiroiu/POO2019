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

class Voluntar {
protected:
	int aniExperienta;
	string asociatie;
public:
	Voluntar() {
		aniExperienta = 2;
		asociatie = "ASER";
	}

	Voluntar(int aniExperienta, string asociatie) {
		this->aniExperienta = aniExperienta;
		this->asociatie = asociatie;
	}

	virtual void prezentareVoluntar() {
		cout << "Sunt voluntar de "<<aniExperienta<<" in asociatia "<<asociatie<<endl;
	}

	virtual ~Voluntar() {
		cout << "a fost apelat destructorul din Voluntar"<<endl;
	}

	virtual float getVenit() = 0;

};

class Adolescent :public Copil, public Voluntar {
private:
	string liceu;
	float bursa;
public:

	float getVenit() {
		return bursa;
	}

	Adolescent() :Copil(),Voluntar() {
		liceu = "";
		bursa = 0;
	}
	Adolescent(string liceu, float bursa)
		:Copil("Adolescent", 14, 50),Voluntar() {
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
		cout << "A fost apelat destructorul din Adolescent"<<endl;

	}

	void prezentareVoluntar() {
		cout << "Sunt elev liceul " << liceu << " si fac voluntariat in asociatia " << this->asociatie << endl;
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
		out << "Liceu:" << a.liceu << endl;
		out << "Bursa: " << a.bursa << endl;
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
	//Voluntar v(5,"SISC");
	//v.prezentareVoluntar();

	//Adolescent a;
	//a.prezentareVoluntar();

	//Voluntar* pv = &a;
	//pv->prezentareVoluntar();

	//Voluntar** vector = new Voluntar*[4];
	//vector[0] = new Voluntar(3, "asociatie");
	//vector[1] = new Adolescent("Lucian Blaga", 300);
	//vector[2] = new Voluntar(6, "alta asociatie");
	//vector[3] = new Adolescent("Mihai viteazu", 400);

	//for (int i = 0; i < 4; i++) {
	//	vector[i]->prezentareVoluntar();
	//}

	//Voluntar* p = new Adolescent();

	//delete p;

	Voluntar* v=new Adolescent();
	v->prezentareVoluntar



}