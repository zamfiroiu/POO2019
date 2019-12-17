#include<iostream>
#include<fstream>

using namespace std;

class CitireScriere {
	virtual void scriereInFisierBinar(fstream& fisier) = 0;
	virtual void citesteDinFisierBinar(fstream& fisier) = 0;
};

class Florarie:public CitireScriere {
private:
	char* nume;
	int nrTipuriFlori;
	bool deschis;
public:
	Florarie() {
		nume = NULL;
		nrTipuriFlori = 0;
		deschis = false;
	}

	Florarie(const char* nume, int nrTipuri, bool deschis) {
		if (nume != NULL) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = NULL;
		}
		this->nrTipuriFlori = nrTipuri;
		this->deschis = deschis;
	}

	Florarie(const Florarie& f) {
		if (f.nume != NULL) {
			this->nume = new char[strlen(f.nume) + 1];
			strcpy(this->nume, f.nume);
		}
		else {
			this->nume = NULL;
		}
		this->nrTipuriFlori = f.nrTipuriFlori;
		this->deschis = f.deschis;
	}

	~Florarie() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}

	Florarie& operator=(const Florarie & f) {
		if (f.nume != NULL) {
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(f.nume) + 1];
			strcpy(this->nume, f.nume);
		}
		else {
			this->nume = NULL;
		}
		this->nrTipuriFlori = f.nrTipuriFlori;
		this->deschis = f.deschis;
		return *this;
	}

	friend ostream&operator<<(ostream& o, const Florarie& f) {
		o << "Nume: " << f.nume<<endl;
		o << "Numar tipuri flori: " << f.nrTipuriFlori << endl;
		o << (f.deschis ? "Deschis" : "Inchis");
		return o;
	}

	void scriereInFisierBinar(fstream& fisier)
	{
		int nrCaractere = strlen(this->nume);
		fisier.write((char*)&nrCaractere, sizeof(int));
		for (int i = 0; i < nrCaractere; i++) {
			fisier.write((char*)&this->nume[i], sizeof(char));
		}
		fisier.write((char*)&this->nrTipuriFlori, sizeof(int));
		fisier.write((char*)&this->deschis, sizeof(bool));
	 }
	void citesteDinFisierBinar(fstream& fisier)
	{
		int lungime;
		fisier.read((char*)&lungime, sizeof(int));
		if (this->nume != NULL) {
			delete[]this->nume;
		}
		this->nume = new char[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			fisier.read((char*)&this->nume[i], sizeof(char));
		}
		this->nume[lungime] = '\0';
		fisier.read((char*)&this->nrTipuriFlori, sizeof(int));
		fisier.read((char*)&this->deschis, sizeof(bool));

	}

};

void main() {
	Florarie* v=new Florarie[3];

	Florarie f("Floris", 4, true);
	fstream fisOut("fisier.txt", ios::out | ios::binary);
	f.scriereInFisierBinar(fisOut);

	fisOut.close();


	Florarie f2;
	fstream fisIn("fisier.txt", ios::in | ios::binary);
	f2.citesteDinFisierBinar(fisIn);
	cout << f2;
	fisIn.close();
}