#include<iostream>
#include<fstream>

using namespace std;

class ScriereCitire {
public:
	virtual void scrieInFisierBinar(fstream & fisier) = 0;
	virtual void citesteDinFisierBinar(fstream & fisier) = 0;

};

class Eveniment : public ScriereCitire {
	char* locatie;
	int nrInvitati;
	float durata;
	int oraIncepere;

public:
	Eveniment() {
		this->locatie = NULL;
		this->nrInvitati = 0;
		this->durata = 0;
		this->oraIncepere = 0;
	}
	Eveniment(const char* locatie, int nrInvitati, float durata, int oraIncepere) {
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);
		this->nrInvitati = nrInvitati;
		this->durata = durata;
		this->oraIncepere = oraIncepere;
	}

	Eveniment(const Eveniment &e)
	{
		this->nrInvitati = e.nrInvitati;
		this->durata = e.durata;
		this->oraIncepere = e.oraIncepere;
		this->locatie = new char[strlen(e.locatie) + 1];
		strcpy(this->locatie, e.locatie);

	}

	Eveniment& operator=(Eveniment &e)
	{
		this->nrInvitati = e.nrInvitati;
		this->durata = e.durata;
		this->oraIncepere = e.oraIncepere;
		if (this->locatie != NULL)
			delete[] this->locatie;
		this->locatie = new char[strlen(e.locatie) + 1];
		strcpy(this->locatie, e.locatie);
		return *this;
	}

	~Eveniment()
	{
		if (this->locatie != NULL)
			delete[] this->locatie;
	}

	char* getLocatie() {
		return locatie;
	}
	int getNrInvitati() {
		return nrInvitati;
	}
	float getDurata() {
		return durata;
	}
	int getOraIncepere() {
		return oraIncepere;
	}

	void scrieInFisierBinar(fstream & fisier)
	{
		int lungime = strlen(this->locatie);
		fisier.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			fisier.write((char*)&this->locatie[i], sizeof(char));
		}
		fisier.write((char*)&this->nrInvitati, sizeof(int));
		fisier.write((char*)&this->oraIncepere, sizeof(int));
		fisier.write((char*)&this->durata, sizeof(float));
	}
	virtual void citesteDinFisierBinar(fstream & fisier) {
		int lungime = 0;
		fisier.read((char*)&lungime, sizeof(int));
		if (this->locatie != NULL) {
			delete[]this->locatie;
		}
		this->locatie = new char[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			fisier.read((char*)&this->locatie[i], sizeof(char));
		}
		this->locatie[lungime] = '\0';
		fisier.read((char*)&this->nrInvitati, sizeof(int));
		fisier.read((char*)&this->oraIncepere, sizeof(int));
		fisier.read((char*)&this->durata, sizeof(float));
	}
};
ostream& operator<<(ostream& consola, Eveniment & e) {
	consola << "Locatie eveniment: " << e.getLocatie() << endl;
	consola << "Numar Invitati: " << e.getNrInvitati() << endl;
	consola << "Durata: " << e.getDurata() << endl;
	consola << "Ora Incepere: " << e.getOraIncepere() << endl;
	return consola;
}


void main() {
	//Eveniment ev("Bucuresti", 200, 2, 14);

	//fstream fisBinOut("fisier.dat", ios::out | ios::binary);
	//ev.scrieInFisierBinar(fisBinOut);
	//fisBinOut.close();

	Eveniment e2;
	fstream fisIn("fisier.dat", ios::in | ios::binary);
	e2.citesteDinFisierBinar(fisIn);
	cout << e2;
	fisIn.close();
}