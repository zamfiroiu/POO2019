#include<iostream>
#include<string>

using namespace std;

enum Categorie{Antreu, Supa, FelPrincipal, Desert};
class Mancare {
private:
	string denumire;
	int nrCalorii;
	char*culoare;
	Categorie fel;

public:
	Mancare() {
		denumire = "";
		nrCalorii = 0;
		culoare = NULL;
		fel = Antreu;
	}

	Mancare(string denumire, int nrCalorii, const char* culoare, Categorie fel) {
		setDenumire(denumire);
		setNrCalorii(nrCalorii);
		if (strlen(culoare) > 2) {
			this->culoare = new char[strlen(culoare) + 1];
			strcpy(this->culoare, culoare);
		}
		setFel(fel);
	}
	string getDenumire() {
		return denumire;
	}
	void setDenumire(string denumire) {
		if (denumire.length() > 2) {
			this->denumire = denumire;
		}
		else {
			throw 202;
		}
	}

	int getNrCalorii() {
		return nrCalorii;
	}

	void setNrCalorii(int nr) {
		if (nr > 0) {
			nrCalorii = nr;
		}
	}

	char* getCuloare() {
		return culoare;
	}

	void setCuloare(const char* culoare) {
		if (strlen(culoare) > 2) {
			if (this->culoare != NULL) {
				delete[]this->culoare;
			}
			this->culoare = new char[strlen(culoare) + 1];
			strcpy(this->culoare, culoare);
		}
	}

	Categorie getFel() {
		return fel;
	}
	void setFel(Categorie fel) {
		this->fel = fel;
	}
};

void main() {
	Mancare m;
	try {
		m.setDenumire("fe");
	}
	catch (int ex) {
		cout << "Denumirea este prea scurta;";
	}
	catch (char* mesajExceptie) {

	}
	catch (...) {

	}

	m.setDenumire("Supa de rosii");
	m.setNrCalorii(100);
	m.setCuloare("Alb");
	cout << m.getDenumire()<<endl;
	cout << m.getNrCalorii() << endl;
}