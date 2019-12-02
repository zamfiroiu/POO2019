#include<iostream>

using namespace std;

class Desert {
private:
	const int idDesert;
	static int contor;
	char* denumire;
	float pret;
protected:
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
	monitor << "Denumire: " << d.getDenumire() << endl;
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


class Prajitura :public Desert {
private:
	int nrIngrediente;
	int nrCalorii;

public:
	
	Prajitura() :Desert() {
		this->nrIngrediente = 0;
		this->nrCalorii = 0;
	}
	Prajitura(int nrIngrediente, int nrCalorii) :Desert("Prajitura", 30, 3) {
		this->nrIngrediente = nrIngrediente;
		this->nrCalorii = nrCalorii;
	}

	Prajitura(const char* denumire, float pret, float cantitate, int nrIngrediente, int nrCalorii) 
		:Desert(denumire, pret, cantitate) {
		this->nrIngrediente = nrIngrediente;
		this->nrCalorii = nrCalorii;
	}

	Prajitura(const Prajitura & p) :Desert(p) {
		this->nrIngrediente = p.nrIngrediente;
		this->nrCalorii = p.nrCalorii;
	}
	Prajitura operator=(const Prajitura& p) {
		Desert::operator=(p);
		this->nrIngrediente = p.nrIngrediente;
		this->nrCalorii = p.nrCalorii;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Prajitura p) {
		out << (Desert)p;
		out << "Nr ingrediente:" << p.nrIngrediente << endl;
		out << "Nr calorii:" << p.nrCalorii << " ";
		return out;
	}
	friend istream& operator>>(istream& in, Prajitura& p) {
		in >> (Desert&)p;
		cout << "nr ingrdiente:";
		in >> p.nrIngrediente;
		cout << "nr calorii:";
		in >> p.nrCalorii;

		return in;
	}

	~Prajitura() {
		
	}
};



void main() {
	Prajitura p;
	p.setCantitate(7);
	cout << p.getCantitate();
	Desert d;
	d.setCantitate(3);

	Prajitura p1(3, 300);
	Prajitura p2("Profiterol", 50, 4, 4, 600);
	
	cin >> p2;
	cout << p2;
}