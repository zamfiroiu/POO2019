#include<iostream>
#include<string>

using namespace std;


class Ciocolata {
private:
	float gramaj;
	string aroma;
	int nrCalorii;
	int nrCuburi;
	string* umplutura;
public:

	void setUmpluturi(int nrCuburi,string*umplutura) {
		if (umplutura != NULL) {
			if (this->umplutura != NULL) {
				delete[]this->umplutura;
			}
			this->umplutura = new string[nrCuburi];
			for (int i = 0; i < nrCuburi; i++) {
				this->umplutura[i] = umplutura[i];
			}
			this->nrCuburi = nrCuburi;
		}
	}

	float getGramaj() {
		return gramaj;
	}

	void setGramaj(float gramaj) {
		if (gramaj > 0) {
			this->gramaj = gramaj;
		}
		else {
			throw 0;
		}
	}

	string getAroma() {
		return aroma;
	}

	void setAroma(string aroma) {
		if (aroma.length() > 2) {
			this->aroma = aroma;
		}
		else {
			throw string("Aroma incorecta");
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
};

void main() {
	Ciocolata ciocolata;
	ciocolata.setGramaj(200);
	cout << ciocolata.getGramaj();

	try {
		ciocolata.setGramaj(5);
		ciocolata.setAroma("");
		//instructiune 2
		//instructiune 3
	}
	catch (int ex) {
		cout << "Gramaj incorect"<<endl;
	}
	catch (string mesajExceptie) {
		cout << mesajExceptie << endl;
	}
	catch (...) {
		cout << "fsdfsd";

	}
}