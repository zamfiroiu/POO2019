#include<iostream>

using namespace std;

class ExceptieEtaj {

};

class Bloc {
private:
	string numeStrada;
	int nrEtaje;
	int nrApartamenteEtaj;
	int* nrLocatariEtaj;

public:

	Bloc(string numeStrada, int pNrEtaje, int nrApartamenteEtaj, int*nrLocatariEtaj) {
		this->numeStrada = numeStrada;
		nrEtaje = pNrEtaje;
		this->nrApartamenteEtaj = nrApartamenteEtaj;
		this->nrLocatariEtaj = new int[nrEtaje];
		for (int i = 0; i < nrEtaje; i++) {
			this->nrLocatariEtaj[i] = nrLocatariEtaj[i];
		}
	}

	Bloc() {
		this->numeStrada = "";
		this->nrEtaje = 0;
		this->nrApartamenteEtaj = 0;
		this->nrLocatariEtaj = NULL;

	}

	int* getNrLocatariEtaj() {
		return nrLocatariEtaj;
	}
	int getNrLocatariEtajPrimit(int etaj) {
		if (etaj > 0 && etaj <= nrEtaje) {
			return nrLocatariEtaj[etaj];
		}
		else {
			throw ExceptieEtaj();
		}
	}

	void setNrLocatariEtaj(int* nrLocatari,int nrEtaje) {
		if (nrLocatari != NULL && nrEtaje>0) {
			if (this->nrLocatariEtaj != NULL)
			{
				delete[]this->nrLocatariEtaj;
			}
			this->nrLocatariEtaj = new int[nrEtaje];
			for (int i = 0; i < nrEtaje; i++) {
				this->nrLocatariEtaj[i] = nrLocatari[i];
			}
			this->nrEtaje = nrEtaje;

		}
	}
};


void main() {
	Bloc b("Principala", 3, 2, new int[3]{6,8,15});
	try {
		b.setNrLocatariEtaj(new int[4]{ 4,8,6,9 }, 4);
	}
	catch (ExceptieEtaj ee) {
		cout << "Numar etaje incorect";
	}
	cout<<b.getNrLocatariEtaj()[1];


	Bloc b1;
	Bloc b2();

	Bloc * pBloc = new Bloc("Dorobanti", 2, 5, new int[2]{ 30,20 });
	Bloc * vectorBlocuri=new Bloc[4];

	Bloc *pb3 = &b1;
}