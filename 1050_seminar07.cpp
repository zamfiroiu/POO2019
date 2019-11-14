#include<iostream>

using namespace std;

class Desert {
private:
	const int idDesert;
	static int contor;
	char* denumire;
	float pret;
	float cantitate;
public:

	float operator()() {
		return pret / cantitate;
	}
	float getPret() {
		return pret;
	}
	void setPret(float valoare) {
		//validare
		this->pret = valoare;
	}
	float getCantitate() {
		return cantitate;
	}
	void setCantitate(float valoare) {
		//validare
		this->cantitate = valoare;
	}

	char* getDenumire() {
		return denumire;
	}
	void setDenumire(const char* denumire) {
		if (denumire != NULL && strlen(denumire) > 2) {
			if (this->denumire != NULL) {
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
	}
	Desert() :idDesert(++contor) {
		this->denumire = NULL;
		this->pret = 0;
		this->cantitate = 0;
	}

	Desert(const char* denumire, float pret, float cantitate) :idDesert(++contor) {
		this->pret = pret;
		this->cantitate = cantitate;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}

	Desert(const Desert &d) :idDesert(++contor) {

		this->pret = d.pret;
		this->cantitate = d.cantitate;
		if (d.denumire != NULL) {
			this->denumire = new char[strlen(d.denumire) + 1];
			strcpy(this->denumire, d.denumire);
		}
		else {
			this->denumire = NULL;
		}
	}

	Desert& operator=(const Desert& d) {
		this->pret = d.pret;
		this->cantitate = d.cantitate;
		if (d.denumire != NULL) {
			if (this->denumire != NULL) {
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(d.denumire) + 1];
			strcpy(this->denumire, d.denumire);
		}
		else {
			this->denumire = NULL;
		}
		return *this;
	}

	~Desert() {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
	}

	Desert operator+(Desert d) {
		Desert result = *this;
		result.pret = this->pret + d.pret;
		result.cantitate = this->cantitate + d.cantitate;
		return result;
	}

	Desert operator+=(Desert d) {
		this->cantitate += d.cantitate;
		this->pret += d.pret;
		return *this;
	}

	bool operator!=(Desert d) {
		if (strcmp(this->denumire, d.denumire) == 0 && this->cantitate == d.cantitate && this->pret == d.pret) {
			return false;
		}
		else {
			return true;
		}
	}

	Desert operator++() {
		this->cantitate++;
		return *this;
	}

	Desert operator++(int) {
		Desert copie = *this;
		this->cantitate++;
		return copie;
	}

	//friend void operator<<(ostream& monitor, Desert d);
	friend istream& operator>>(istream& tastatura, Desert& d);
};
int Desert::contor = 0;

ostream& operator<<(ostream& monitor, Desert d) {
	monitor <<"Denumire: "<< d.getDenumire() << endl;
	monitor << "Pret: " << d.getPret() << endl;
	monitor << "Cantitate: " << d.getCantitate() << endl;
	return monitor;
}

istream& operator>>(istream& tastatura, Desert& d) {
	char aux[20];
	cout << "denumire:";
	tastatura >> aux;
	if (d.denumire != NULL) {
		delete[]d.denumire;
	}
	d.denumire = new char[strlen(aux) + 1];
	strcpy(d.denumire, aux);
	cout << "Cantitate:";
	tastatura >> d.cantitate;
	cout << "Pret:";
	tastatura >> d.pret;

	return tastatura;
}

Desert operator+(Desert d, int valoare) {
	Desert result = d;
	result.setCantitate(d.getCantitate() + valoare);
	return result;
}

Desert operator+(int valoare, Desert d) {
	Desert result = d;
	result.setCantitate(d.getCantitate() + valoare);
	return result;
}
//
//float pretPerGram(Desert d) {
//	return d.pret / d.cantitate;
//}

class Cofetarie {
public:
	int nrDeserturi;
	Desert*deserturi;

	Cofetarie() {
		nrDeserturi = 2;
		deserturi = new Desert[2];
		deserturi[0].setDenumire("Tiramisu");
		deserturi[1].setDenumire("Cheese Cake");
	}

	Cofetarie operator+=(Desert d) {
		this->nrDeserturi++;
		Desert* aux = new Desert[nrDeserturi];
		if (this->deserturi != NULL) {
			for (int i = 0; i < nrDeserturi - 1; i++) {
				aux[i] = this->deserturi[i];
			}
			delete[]deserturi;
		}
		aux[nrDeserturi - 1] = d;
		deserturi = aux;
		return *this;
	}

	Desert& operator[](int index) {
		if (index >= 0 && index < this->nrDeserturi) {
			return deserturi[index];
		}
		else {
			throw 0;
		}
	}
};




void main() {

	int a = 10;
	int b = 20;
	int c = 30;

	a = b + c;

	Desert d1("Cake", 10, 2);
	Desert d2("Tiramisu", 20, 3);
	Desert d3("Cozonac", 15, 2);
	//  exterior				interior
	d3 = d1 + d2; //operator+(d1,d2)  ==> d1.operator+(d2)
	d3 = d1 + 10.3;//operator+(d1,10) ==>   d1.operator+(10)
	d3 = 10 + d1;//operator+(10,d1) ==>   


	d3 += d1 += d2;

	if (d1 != d2) {
		cout << "sunt diferite";
	}
	else {
		cout << "sunt asemanatoare";
	}


	//d3 = !d2;

	d2 = d3++;


	d2 = ++d3;

	Cofetarie c1;
	Cofetarie c2;
	c1 += d1;

	cout << endl;
	cin >> d1;
	cout << d1<<endl;
	
	cout << c1[0];
	c1[0] = d3;
	cout << c1[0];

	d1();
}