#include<iostream>
#include<string>
#include<fstream>

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
	friend ifstream& operator>>(ifstream& tastatura, Copil& c);
	friend ofstream& operator<<(ofstream& o, Copil c);
	friend void scriereInCSV(ofstream& file, Copil c);
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


ofstream& operator<<(ofstream& o, Copil c) {
	if (c.nume != NULL) {
		o <<  c.nume << endl;
		o <<  c.greutate << endl;
		o <<  c.varsta << endl;
	}
	else {

		throw new ExceptieAfisare("Copilul nu are nume");
	}
	return o;
}

ifstream& operator>>(ifstream& tastatura, Copil& c) {
	char aux[20];
	tastatura >> aux;
	if (c.nume != NULL) {
		delete[]c.nume;
	}
	c.nume = new char[strlen(aux) + 1];
	strcpy(c.nume, aux);
	tastatura >> c.greutate;
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

void scriereInCSV(ofstream& file, Copil c) {
	file << c.nume << "," 
		<< c.greutate << "," 
		<< c.varsta << "," 
		<< endl;
}

void main() {
	//Copil c("Gigel", 4, 20);
	/*ofstream f("fisier.txt", ios::out);

	f << c;
	
	f.close();*/

	/*ifstream file("fisier.txt", ios::in);

	file >> c;
	cout << endl << c;
	Copil c2;
	file >> c2;
	cout << c2;
	file.close();*/

	//Copil c3("Ionescu", 16, 60);

	//ofstream fApp("fisier.txt", ios::app);
	//fApp << c3;
	//fApp.close();

	ifstream fisier("fisier.txt", ios::in);
	int nrCopii = 0;
	fisier >> nrCopii;
	Copil * copii = new Copil[nrCopii];
	Copil** vectP = new Copil*[nrCopii];
	for (int i = 0; i < nrCopii; i++) {
		fisier >> copii[i];
		vectP[i] = new Copil(copii[i]);
	}

	ofstream csvFile("copii.csv", ios::out);
	csvFile << "Nume,Greutate,Varsta,"<<endl;
	for (int i = 0; i < nrCopii; i++) {
		cout << copii[i];
		scriereInCSV(csvFile, copii[i]);
	}
	csvFile.close();
	fisier.close();

}