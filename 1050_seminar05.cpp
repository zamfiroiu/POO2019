#include<iostream>

using namespace std;



class Desert {
public:
	const int idDesert;
	static int contor;
	char* denumire;
	float pret;
	float cantitate;
public:
	
	class dataTimp {
		int zi;
		int luna;
		int an;
	};
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

	Desert(const Desert &d):idDesert(++contor) {

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
};
int Desert::contor = 0;

float pretPerGram(Desert d) {
	return d.pret / d.cantitate;
}

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
};




void main() {

	Desert d1;
	Desert d2("Profiterol", 15, 300);
	Desert d3 = d2;
	cout << d2.getDenumire()<<endl;
	d3.setDenumire("Tiramisu");
	cout << d2.getDenumire() << endl;
	//d3.setDenumire(d3.getDenumire());

	cout << pretPerGram(d1);

	Desert d4;
	d4 = d2;

	Cofetarie c;
	c.deserturi[0].getDenumire();
}