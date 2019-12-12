#include<iostream>
#include<fstream>

using namespace std;

class Medicament {
private:
	const int id;
	static int contor;
	char* denumire;
	float gramaj;
	bool antibiotic;

public:

	void salvareInFisierCSV(ofstream& file) {
		file << this->denumire << "," 
			<< this->gramaj << "," 
			<< (this->antibiotic?"DA":"NU") << "," 
			<< endl;
	}

	float operator()(int nrBucati) {
		return gramaj / nrBucati;
	}

	char* operator()() {
		return denumire;
	}

	Medicament() :id(++contor) {
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

	Medicament(const Medicament &m) :id(++contor) {
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
	Medicament operator+(Medicament m) {
		Medicament result = *this;
		result.gramaj = this->gramaj + m.gramaj;
		return result;
	}

	Medicament operator+(int valoare) {
		Medicament result = *this;
		result.gramaj = this->gramaj + valoare;
		return result;
	}

	Medicament operator+=(Medicament m) {
		this->gramaj += m.gramaj;
		return *this;
	}

	float getGramaj() {
		return gramaj;
	}
	void setGramaj(float value) {
		//validare
		this->gramaj = value;
	}

	bool operator!=(Medicament m) {
		if (strcmp(this->denumire, m.denumire) == 0 && this->gramaj == m.gramaj && this->antibiotic == m.antibiotic) {
			return false;
		}
		else {
			return true;
		}
	}


	Medicament operator!() {
		Medicament result = *this;
		result.antibiotic = !result.antibiotic;
		return result;
	}

	Medicament operator++() {
		this->gramaj++;
		return *this;
	}

	Medicament operator++(int) {
		Medicament copie = *this;
		this->gramaj++;
		return copie;
	}

	friend class Farmacie;
	friend ostream& operator<<(ostream& monitor, Medicament m);
	friend istream& operator>>(istream& tastatura, Medicament& m);
	friend ofstream& operator<<(ofstream& monitor, Medicament m);
	friend ifstream& operator>>(ifstream& tastatura, Medicament& m);
};
int Medicament::contor = 0;

Medicament operator+(int valoare, Medicament m) {
	Medicament result = m;
	result.setGramaj(m.getGramaj() + valoare);
	return result;
}
ostream& operator<<(ostream& monitor, Medicament m) {
	monitor << "Denumire: " << m.denumire << endl;
	monitor << "Gramaj: " << m.gramaj << endl;
	monitor << "Antibiotic: " << m.antibiotic << endl;
	return monitor;
}

istream& operator>>(istream& tastatura, Medicament& m) {
	if (m.denumire != NULL) {
		delete[]m.denumire;
	}
	char aux[20];
	cout << "Denumire:";
	tastatura >> aux;
	m.denumire = new char[strlen(aux) + 1];
	strcpy(m.denumire, aux);
	cout << "Gramaj:";
	tastatura >> m.gramaj;
	cout << "Antibiotic?(0-NU, 1-DA):";
	tastatura >> m.antibiotic;
	return tastatura;
}

ofstream& operator<<(ofstream& monitor, Medicament m) {
	monitor << m.denumire << endl;
	monitor << m.gramaj << endl;
	monitor << m.antibiotic << endl;
	return monitor;
}

ifstream& operator>>(ifstream& tastatura, Medicament& m) {
	if (m.denumire != NULL) {
		delete[]m.denumire;
	}
	char aux[20];
	tastatura >> aux;
	m.denumire = new char[strlen(aux) + 1];
	strcpy(m.denumire, aux);
	tastatura >> m.gramaj;
	tastatura >> m.antibiotic;
	return tastatura;
}


class Farmacie {
public:
	int nrMedicamente;
	Medicament* *medicamente;
public:

	bool operator>(Farmacie f) {
		return this->gramajTotal() > f.gramajTotal();
	}

	operator int() {
		return this->nrMedicamente;
	}

	operator float() {
		float s = 0;
		for (int i = 0; i < nrMedicamente; i++) {
			s += medicamente[i]->getGramaj();
		}

		return s;
	}
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
		float suma = 0;
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

	Farmacie& operator+=(Medicament* m) {
		Medicament**pp = new Medicament*[this->nrMedicamente + 1];
		for (int i = 0; i < this->nrMedicamente; i++) {
			pp[i] = this->medicamente[i];
		}
		pp[this->nrMedicamente] = new Medicament(*m);
		delete[]this->medicamente;
		this->medicamente = pp;
		this->nrMedicamente++;
		return *this;

	}

	Medicament* operator[](int index) {
		if (index >= 0 && index < this->nrMedicamente) {
			return medicamente[index];
		}
		else {
			throw "Index incorect";
		}
	}

};

void main() {
	Medicament m("Nurofen", 100, false);

	//ofstream file("fisier.txt", ios::out);
	//file << m;
	//file.close();

	//ifstream fileIN("fisier.txt", ios::in);
	//fileIN >> m;
	//cout << m;

	//fileIN >> m;
	//cout << m;
	//fileIN.close();

	//Medicament med("parasinus", 200, 0);
	//ofstream fis("fisier.txt", ios::app);
	//fis << med;
	//fis.close();


	ifstream fileIn("fisier.txt", ios::in);
	ofstream CSVFile("medicamente.csv", ios::out);

	int nrMedicamente = 0;
	fileIn >> nrMedicamente;
	CSVFile << "Denumire,Gramaj,Antibiotic,"<<endl;
	for (int i = 0; i < nrMedicamente; i++) {
		Medicament m;
		fileIn >> m;
		m.salvareInFisierCSV(CSVFile);
	}
	fileIn.close();
	CSVFile.close();

}