#include<iostream>
#include<string>

using namespace std;

class Carte {
private:
	int nrPagini;
	string autor;
	char* gen;
	bool ptCopii;
public:
	char* getGen() {
		return gen;
	}

	void setGen(const char* gen) {
		if (gen != NULL && strlen(gen) > 3) {
			if (this->gen != NULL) {
				//delete[]this->gen;
			}
			this->gen = new char[strlen(gen) + 1];
			strcpy(this->gen, gen);
		}
	}


	string getAutor() {
		return autor;
	}
	void setAutor(string autor) {
		if (autor.length() > 2) {
			this->autor = autor;
		}
	}
	int getNrPagini() {
		return nrPagini;
	}
	void setNrPagini(int nrPagini) {
		if (nrPagini > 10) {
			this->nrPagini = nrPagini;
		}
		else {
			throw 0;
		}
	}

	bool getPrCopii() {
		return ptCopii;
	}

	void setPtCopii(bool ptCopii) {
		this->ptCopii = ptCopii;
	}
};

void main() {
	Carte c;
	c.setAutor("Popescu");
	cout << c.getAutor() << endl << endl;
	c.setAutor("Rebreanu");
	cout << c.getAutor() << endl << endl;
	c.setGen("Drama");
	try {
		c.setNrPagini(-4);
		//instructiunea 1
		//instructiunea 2
	}
	catch (int exceptie) {
		cout << "Numar pagini prea mic. Cod eroare:"<<exceptie<<"."<<endl;
	}
	catch (string ex) {

	}
	catch (...) {

	}
}