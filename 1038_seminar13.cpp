#include<iostream>

using namespace std;


template<class tip>
tip suma(tip a, tip b) {
	return a + b;
}

template<class T1, class T2, class T3>
T1 adunare(T2 a, T3 b) {
	return a + b;
}

template<class TIP>
class Fabrica {
private:
	TIP* produse;
	int nrProduse;
public:
	Fabrica() {
		produse = NULL;
		nrProduse = 0;
	}
	Fabrica(int nrProduse, TIP* produse) {
		this->nrProduse = nrProduse;
		if (nrProduse > 0) {
			this->produse = new TIP[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->produse[i] = produse[i];
			}
		}
		else {
			this->produse = NULL;
		}
	}
	Fabrica(const Fabrica& f) {
		this->nrProduse = f.nrProduse;
		if (f.nrProduse > 0) {
			this->produse = new TIP[f.nrProduse];
			for (int i = 0; i < f.nrProduse; i++) {
				this->produse[i] = f.produse[i];
			}
		}
		else {
			this->produse = NULL;
		}
	}

	Fabrica& operator=(const Fabrica& f) {
		this->nrProduse = f.nrProduse;
		if (f.nrProduse > 0) {
			if (this->produse != NULL) {
				delete[]this->produse;
			}
			this->produse = new TIP[f.nrProduse];
			for (int i = 0; i < f.nrProduse; i++) {
				this->produse[i] = f.produse[i];
			}
		}
		else {
			this->produse = NULL;
		}
		return *this;
	}
	~Fabrica() {
		if (this->produse != NULL) {
			delete[]this->produse;
		}
	}

	Fabrica operator+=(TIP element) {
		TIP* temp = new TIP[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++) {
			temp[i] = this->produse[i];
		}
		temp[this->nrProduse] = element;
		if (this->produse != NULL) {
			delete[]this->produse;
		}
		this->produse = temp;
		this->nrProduse++;
		return *this;
	}

	void adaugaProdus(TIP element) {
		(*this) += element;
	}

	friend ostream&operator<<(ostream& monitor, Fabrica f) {
		monitor << "Fabrica are " << f.nrProduse << " produse:" << endl;
		for (int i = 0; i < f.nrProduse; i++) {
			monitor << f.produse[i] << endl;
		}
		return monitor;
	}
};

class Magazin {
private:
	int nrProduse;
	float pretProdus;
public:
	Magazin() {
		nrProduse = 0;
		pretProdus = 0;
	}
	Magazin(int nrProduse, float pret) {
		this->nrProduse = nrProduse;
		this->pretProdus = pret;
	}
	friend ostream& operator<<(ostream& out, const Magazin& m) {
		out << "Magazinul are " << m.nrProduse 
			<< " produse la un pret unitar de " 
			<< m.pretProdus<<endl;
		return out;
	}

	Magazin operator+(const Magazin& m) {
		Magazin r = *this;
		r.nrProduse = this->nrProduse + m.nrProduse;
		r.pretProdus = this->pretProdus;
		return r;
	}
};

void main() {
	/*int a = 5;
	int b = 6;
	cout << suma(a, b) << endl;

	float x = 5.8;
	float y = 6.7;
	cout << suma<float>(a, y) << endl;

	cout << adunare<int, float, float>(x, y)<<endl;


	Magazin m1(50, 10);
	Magazin m2(20, 5);
	cout << suma(m1, m2);*/

	Fabrica<int>fabricaValoriIntregi;
	float* v = new float[3]{ 5.8,6.3,7.4 };
	Fabrica<float>fabricaReale(3, v);
	Magazin m1(50, 10);
	Magazin m2(20, 5);
	Magazin* magazine = new Magazin[2]{ m1,m2 };
	Fabrica<Magazin>fabrica(2, magazine);
	cout << fabrica<<endl;

	Magazin m3(60, 15);
	fabrica.adaugaProdus(m3);
	cout << fabrica;
}