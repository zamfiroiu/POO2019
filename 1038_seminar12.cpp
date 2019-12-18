//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//class ScriereCitire {
//public:
//	virtual void scrieInFisierBinar(fstream & fisier) = 0;
//	virtual void citesteDinFisierBinar(fstream & fisier) = 0;
//
//};
//
//class Craciun:public ScriereCitire {
//	char* locatiePetrecere;
//	int nrInvitati;
//	char masa;
//public:
//
//	char* getLocatie() {
//		return locatiePetrecere;
//	}
//	int getNrInvitati() {
//		return nrInvitati;
//	}
//	char getMasa() {
//		return masa;
//	}
//	Craciun() {
//		locatiePetrecere = NULL;
//		nrInvitati = 10;
//		masa = 'A';
//	}
//
//	Craciun(const char* locatie, int nrInvitati, char masa) {
//		if (locatie != NULL) {
//			this->locatiePetrecere = new char[strlen(locatie) + 1];
//			strcpy(this->locatiePetrecere, locatie);
//		}
//		else {
//			this->locatiePetrecere = NULL;
//		}
//		this->nrInvitati = nrInvitati;
//		this->masa = masa;
//	}
//
//	~Craciun() {
//		if (this->locatiePetrecere != NULL) {
//			delete[]this->locatiePetrecere;
//		}
//	}
//
//	Craciun(const Craciun& c) {
//		if (c.locatiePetrecere != NULL) {
//			this->locatiePetrecere = new char[strlen(c.locatiePetrecere) + 1];
//			strcpy(this->locatiePetrecere, c.locatiePetrecere);
//		}
//		else {
//			this->locatiePetrecere = NULL;
//		}
//		this->nrInvitati = c.nrInvitati;
//		this->masa = c.masa;
//	}
//
//	Craciun& operator=(const Craciun& c) {
//		if (c.locatiePetrecere != NULL) {
//			if (this->locatiePetrecere != NULL) {
//				delete[]this->locatiePetrecere;
//			}
//			this->locatiePetrecere = new char[strlen(c.locatiePetrecere) + 1];
//			strcpy(this->locatiePetrecere, c.locatiePetrecere);
//		}
//		else {
//			this->locatiePetrecere = NULL;
//		}
//		this->nrInvitati = c.nrInvitati;
//		this->masa = c.masa;
//
//		return *this;
//	}
//
//	void scrieInFisierBinar(fstream & fisier) {
//
//		int lungime = strlen(this->locatiePetrecere);
//		fisier.write((char*)&lungime, sizeof(int));
//		for (int i = 0; i < lungime; i++) {
//			fisier.write((char*)&this->locatiePetrecere[i], sizeof(char));
//		}
//		fisier.write((char*)&this->nrInvitati, sizeof(int));
//		fisier.write((char*)&this->masa, sizeof(char));
//	}
//	void citesteDinFisierBinar(fstream & fisier) {
//		int lungime = 0;
//		fisier.read((char*)&lungime, sizeof(int));
//		if (this->locatiePetrecere != NULL) {
//			delete[]this->locatiePetrecere;
//		}
//		this->locatiePetrecere = new char[lungime + 1];
//		for (int i = 0; i < lungime; i++) {
//			fisier.read((char*)&this->locatiePetrecere[i], sizeof(char));
//		}
//		this->locatiePetrecere[lungime] = '\0';
//		fisier.read((char*)&this->nrInvitati, sizeof(int));
//		fisier.read((char*)&this->masa, sizeof(char));
//	}
//};
//
//void main() {
//
//	//fstream fOut("fisier.txt", ios::out | ios::binary);
//	fstream fIn("fisier.txt", ios::in | ios::binary);
//
//	/*Craciun craciun("Bucuresti", 5, 'B');
//	craciun.scrieInFisierBinar(fOut);
//	fOut.close();*/
//
//	Craciun c2;
//	c2.citesteDinFisierBinar(fIn);
//	cout << c2.getLocatie() << " " 
//		<< c2.getNrInvitati() << " " 
//		<< c2.getMasa();
//	fIn.close();
//}