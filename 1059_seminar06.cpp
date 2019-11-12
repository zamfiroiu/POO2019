//#include<iostream>
//
//using namespace std;
//
//class Medicament {
//private:
//	const int id;
//	static int contor;
//	char* denumire;
//	float gramaj;
//	bool antibiotic;
//
//public:
//	Medicament() :id(++contor) {
//		this->denumire = NULL;
//		this->gramaj = 0;
//		this->antibiotic = false;
//	}
//	Medicament(const char* denumire, float gramaj, bool antibiotic) :id(++contor) {
//		this->antibiotic = antibiotic;
//		this->gramaj = gramaj;
//		if (denumire != NULL && strlen(denumire) > 0) {
//			this->denumire = new char[strlen(denumire) + 1];
//			strcpy(this->denumire, denumire);
//		}
//	}
//	~Medicament() {
//		if (this->denumire) {
//			delete[]this->denumire;
//		}
//	}
//
//	Medicament(const Medicament &m) :id(++contor) {
//		this->gramaj = m.gramaj;
//		this->antibiotic = m.antibiotic;
//		if (m.denumire != NULL) {
//			this->denumire = new char[strlen(m.denumire) + 1];
//			strcpy(this->denumire, m.denumire);
//		}
//		else {
//			this->denumire = NULL;
//		}
//	}
//
//	Medicament& operator=(const Medicament& m) {
//		this->gramaj = m.gramaj;
//		this->antibiotic = m.antibiotic;
//		if (m.denumire != NULL) {
//			if (this->denumire != NULL) {
//				delete[]this->denumire;
//			}
//			this->denumire = new char[strlen(m.denumire) + 1];
//			strcpy(this->denumire, m.denumire);
//		}
//		else {
//			this->denumire = NULL;
//		}
//		return *this;
//	}
//	Medicament operator+(Medicament m) {
//		Medicament result = *this;
//		result.gramaj = this->gramaj + m.gramaj;
//		return result;
//	}
//
//	Medicament operator+(int valoare) {
//		Medicament result = *this;
//		result.gramaj = this->gramaj + valoare;
//		return result;
//	}
//
//	Medicament operator+=(Medicament m) {
//		this->gramaj += m.gramaj;
//		return *this;
//	}
//
//	float getGramaj() {
//		return gramaj;
//	}
//	void setGramaj(float value) {
//		//validare
//		this->gramaj = value;
//	}
//
//	bool operator!=(Medicament m) {
//		if (strcmp(this->denumire, m.denumire) == 0 && this->gramaj == m.gramaj && this->antibiotic == m.antibiotic) {
//			return false;
//		}
//		else {
//			return true;
//		}
//	}
//
//
//	Medicament operator!() {
//		Medicament result = *this;
//		result.antibiotic = !result.antibiotic;
//		return result;
//	}
//
//
//	friend class Farmacie;
//};
//int Medicament::contor = 0;
//
//Medicament operator+(int valoare, Medicament m) {
//	Medicament result = m;
//	result.setGramaj(m.getGramaj() + valoare);
//	return result;
//}
//
//
//class Farmacie {
//public:
//	int nrMedicamente;
//	Medicament* *medicamente;
//public:
//	Farmacie() {
//		this->nrMedicamente = 3;
//		this->medicamente = new Medicament*[this->nrMedicamente];
//		for (int i = 0; i < this->nrMedicamente; i++) {
//			this->medicamente[i] = new Medicament("Parasinus", (i + 10) * 3, false);
//		}
//	}
//	~Farmacie() {
//		for (int i = 0; i < this->nrMedicamente; i++) {
//			delete this->medicamente[i];
//		}
//		delete[]this->medicamente;
//	}
//
//	float gramajTotal() {
//		float suma = 0;
//		for (int i = 0; i < this->nrMedicamente; i++) {
//			suma += this->medicamente[i]->gramaj;
//		}
//		return suma;
//	}
//
//	int nrAntibiotice() {
//		float suma = 0;
//		for (int i = 0; i < this->nrMedicamente; i++) {
//			if (this->medicamente[i]->antibiotic == true) {
//				suma++;
//			}
//		}
//		return suma;
//	}
//
//	Farmacie operator+=(Medicament* m) {
//		Medicament**pp = new Medicament*[this->nrMedicamente + 1];
//		for (int i = 0; i < this->nrMedicamente; i++) {
//			pp[i] = this->medicamente[i];
//		}
//		pp[this->nrMedicamente]=m;
//		delete[]this->medicamente;
//		this->medicamente = pp;
//		this->nrMedicamente++;
//		return *this;
//
//	}
//
//};
//
//void main() {
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	c = a + b;
//
//	Medicament m1("Paracetamol", 30, false);
//	Medicament m2("Aspirina", 20, false);
//	Medicament m3("Augmentin", 10, true);
//
//	m3 = m1 + m2; //operator+(m1,m2)  ==>  m1.operator+(m2)
//	m3 = m1 + 10; //operator+(m1,10)   ==>  m1.operator+(10)
//	m3 = 10 + m1; //operator+(10,m1)  ==>
//
//	m1 += m2;
//
//	if (m1 != m2) {
//		cout << "sunt diferite";
//	}
//	else {
//		cout << "Sunt asemanatoare";
//	}
//
//	m3 = !m2;//m2.operator!();
//
//	Farmacie f1;
//	f1 += &m3;
//
//}