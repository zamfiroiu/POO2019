#include<iostream>

using namespace std;

//int suma(int a, int b) {
//	return a + b;
//}
//
//float suma(float a, float b) {
//	return a + b;
//}

template<class tip>
tip suma(tip a, tip b) {
	return a + b;
}

template<class T1, class T2>
void functie(T1 a, T2 b) {

}

template<class TIP>
class Colectie{
private:
	TIP* elemente;
	int nrElemente;
public:
	Colectie() {
		elemente = NULL;
		nrElemente = 0;
	}
	Colectie(TIP* elemente, int nrElemente) {
		this->nrElemente = nrElemente;
		if (nrElemente > 0) {
			this->elemente = new TIP[nrElemente];
			for (int i = 0; i < nrElemente; i++) {
				this->elemente[i] = elemente[i];
			}
		}
		else {
			this->elemente = NULL;
		}
	}
	Colectie(const Colectie& c) {
		this->nrElemente = c.nrElemente;
		if (c.nrElemente > 0) {
			this->elemente = new TIP[this->nrElemente];
			for (int i = 0; i < this->nrElemente; i++) {
				this->elemente[i] = c.elemente[i];
			}
		}
		else {
			this->elemente = NULL;
		}
	}

	Colectie& operator=(const Colectie& c) {
		this->nrElemente = c.nrElemente;
		if (c.elemente != NULL) {
			if (this->elemente != NULL) {
				delete[]this->elemente;
			}
			this->elemente = new TIP[this->nrElemente];
			for (int i = 0; i < this->nrElemente; i++) {
				this->elemente[i] = c.elemente[i];
			}
		}
		else {
			this->elemente = NULL;
		}
		return *this;
	}
	~Colectie() {
		if (this->elemente) {
			delete[]this->elemente;
		}
	}

	friend ostream& operator<<(ostream& consola, Colectie c) {
		consola << "Colectia are " << c.nrElemente << " elemente:" << endl;
		for (int i = 0; i < c.nrElemente; i++) {
			consola << c.elemente[i]<<endl;
		}
		return consola;
	}

	Colectie operator+=(TIP item) {
		this->nrElemente++;
		TIP* temp = new TIP[this->nrElemente];
		for (int i = 0; i < this->nrElemente - 1; i++) {
			temp[i] = this->elemente[i];
		}
		temp[this->nrElemente - 1]=item;
		if (this->elemente != NULL) {
			delete[]this->elemente;
		}
		this->elemente = temp;
		return *this;
	}

	void adaugaElement(TIP item) {
		(*this) += item;
	}
};

class Carte {
private:
	int nrPagini;
	float pret;
public:
	Carte() {
		this->pret = 0;
		this->nrPagini = 0;
	}
	Carte(int nrPagini, float pret) {
		this->nrPagini = nrPagini;
		this->pret = pret;
	}
	friend ostream& operator<<(ostream& out, const Carte& c) {
		out << c.nrPagini << " pagini costa " << c.pret << "RON." << endl;
		return out;
	}

	Carte operator+(Carte c) {
		Carte r = *this;
		r.pret = this->pret + c.pret;
		r.nrPagini = this->nrPagini + c.nrPagini;
		return r;
	}
};

void main() {
	/*int a = 5;
	int b = 6;
	cout << suma(a, b)<<endl;


	float x = 5.6;
	float y = 6.8;
	cout << suma<float>(x, b)<<endl;

	Carte c1(200, 20);
	Carte c2(450, 64);
	cout << suma(c1, c2);*/

	Colectie<int> colectieIntregi;
	float* vector = new float[2]{ 4.7,8.3 };
	Colectie<float>colectieReale(vector, 2);
	Carte c1(200, 20);
	Carte c2(450, 64);
	Carte * carti = new Carte[2]{ c1,c2 };
	Colectie<Carte>colectieCarti(carti, 2);
	cout << colectieCarti << endl<<endl;
	Carte c3(500, 30);
	colectieCarti.adaugaElement(c3);
	cout << colectieCarti;
}
