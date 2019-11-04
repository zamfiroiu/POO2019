#include<iostream>


using namespace std;

class Medicament {
public:
	const int id;
	static int contor;
	char* denumire;
	float gramaj;
	bool antibiotic;

public:
	Medicament():id(++contor) {
		this->denumire = NULL;
		this->gramaj = 0;
		this->antibiotic = false;
	}
	Medicament(const char* denumire, float gramaj, bool antibiotic) :id(++contor) {
		this->antibiotic = antibiotic;
		this->gramaj = gramaj;
		if (denumire != NULL && strlen(denumire) > 0) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
	}
	~Medicament() {
		if (this->denumire) {
			delete[]this->denumire;
		}
	}

	Medicament(const Medicament &m):id(++contor) {
		this->gramaj = m.gramaj;
		this->antibiotic = m.antibiotic;
		if (m.denumire != NULL) {
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy(this->denumire, m.denumire);
		}
		else {
			this->denumire = NULL;
		}
	}

	Medicament& operator=(const Medicament& m) {
		this->gramaj = m.gramaj;
		this->antibiotic = m.antibiotic;
		if (m.denumire != NULL) {
			if (this->denumire != NULL) {
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy(this->denumire, m.denumire);
		}
		else {
			this->denumire = NULL;
		}
		return *this;
	}
};
int Medicament::contor = 0;

class Farmacie {
public:
	int nrMedicamente;
	Medicament* *medicamente;
public:
	Farmacie() {
		this->nrMedicamente = 3;
		this->medicamente = new Medicament*[this->nrMedicamente];
		for (int i = 0; i < this->nrMedicamente; i++) {
			this->medicamente[i] = new Medicament("Parasinus", (i + 10) * 3, false);
		}
	}
	~Farmacie() {
		for (int i = 0; i < this->nrMedicamente; i++) {
			delete this->medicamente[i];
		}
		delete[]this->medicamente;
	}

	float gramajTotal() {
		float suma=0;
		for (int i = 0; i < this->nrMedicamente; i++) {
			suma += this->medicamente[i]->gramaj;
		}
		return suma;
	}

	int nrAntibiotice() {
		float suma = 0;
		for (int i = 0; i < this->nrMedicamente; i++) {
			if (this->medicamente[i]->antibiotic == true) {
				suma++;
			}
		}
		return suma;
	}

};

void main() {
	Medicament m1;
	Medicament m2("Augmentin", 10, true);
	Medicament m3 = m2;
	cout << m3.denumire<<endl;
	strcpy(m2.denumire, "Clasa");
	cout << m3.denumire << endl;

	Medicament m4;
	m4 = m2;

	Farmacie f;

	for (int i = 0; i < f.nrMedicamente; i++) {
		cout << f.medicamente[i]->gramaj << " ";
	}
}