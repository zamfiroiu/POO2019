//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class ExceptieIndex {
//	string mesajExceptie;
//public:
//	ExceptieIndex(string mesaj) {
//		this->mesajExceptie = mesaj;
//	}
//	ExceptieIndex() {
//		this->mesajExceptie = "Mesaj exceptie";
//	}
//	string getMesaj() {
//		return mesajExceptie;
//	}
//};
//
//class Prajitura {
//	const int id;
//	static int contor;
//	string denumire;
//	int nrIngrediente;
//	string * ingrediente;
//protected:
//	float calorii;
//
//public:
//	static float TVA;
//	Prajitura() :id(contor), nrIngrediente(3) {
//		this->denumire = "Amandina";
//		this->ingrediente = new string[3];
//		this->ingrediente[0] = "Zahar";
//		this->ingrediente[1] = "Lapte";
//		this->ingrediente[2] = "Faina";
//		this->calorii = 10;
//		contor++;
//	}
//
//	void operator()(string newDenumire) {
//		this->denumire = newDenumire;
//	}
//
//	float operator()() {
//		return this->calorii / (float)this->nrIngrediente;
//	}
//
//	Prajitura(const Prajitura& p):id(contor++) {
//		this->denumire = p.denumire;
//		this->nrIngrediente = p.nrIngrediente;
//		this->ingrediente = new string[nrIngrediente];
//		for (int i = 0; i < nrIngrediente; i++) {
//			this->ingrediente[i] = p.ingrediente[i];
//		}
//		this->calorii = p.calorii;
//	}
//
//	Prajitura operator=(const Prajitura& p) {
//		this->denumire = p.denumire;
//		this->nrIngrediente = p.nrIngrediente;
//		if (this->ingrediente != NULL) {
//			delete[]this->ingrediente;
//		}
//		this->ingrediente = new string[nrIngrediente];
//		for (int i = 0; i < nrIngrediente; i++) {
//			this->ingrediente[i] = p.ingrediente[i];
//		}
//		this->calorii = p.calorii;
//		return *this;
//
//	}
//
//	Prajitura(string denumire, int nrIngrediente, string * ingrediente, float calorii) :id(contor++) {
//		if (denumire.length() > 0) {
//			this->denumire = denumire;
//		}
//		else {
//			this->denumire = "";
//		}
//		if (nrIngrediente > 0 && ingrediente != NULL) {
//			this->nrIngrediente = nrIngrediente;
//			this->ingrediente = new string[nrIngrediente];
//			for (int i = 0; i < nrIngrediente; i++) {
//				this->ingrediente[i] = ingrediente[i];
//			}
//		}
//		else {
//			this->nrIngrediente = 0;
//			this->ingrediente = NULL;
//		}
//		this->calorii = calorii;
//	}
//
//	~Prajitura() {
//		if (this->ingrediente != NULL) {
//			delete[]this->ingrediente;
//		}
//	}
//	string* getIngrediente() {
//		return this->ingrediente;
//	}
//
//	string getIngredient(int pozitie) {
//		if (pozitie >= 0 && pozitie < nrIngrediente) {
//			return this->ingrediente[pozitie];
//		}
//		else {
//			throw ExceptieIndex("Pozitie incorecta");
//		}
//	}
//	int getNrIngrediente() {
//		return nrIngrediente;
//	}
//
//	Prajitura operator+(Prajitura p) {
//		Prajitura result = *this;
//		result.calorii = this->calorii + p.calorii;
//		return result;
//	}
//
//	float getCalorii() {
//		return calorii;
//	}
//	void setCalorii(float calorii) {
//		//validare
//		this->calorii = calorii;
//	}
//
//	Prajitura operator+=(Prajitura p) {
//		this->calorii += p.calorii;
//		return *this;
//	}
//
//	bool operator>=(Prajitura p) {
//		return this->calorii >= p.calorii;
//	}
//
//	Prajitura operator++();
//
//
//	Prajitura operator++(int){
//		Prajitura aux = *this;
//		this->calorii++;
//		return aux;
//	}
//
//	string& operator[](int pozitie) {
//		if (pozitie >= 0 && pozitie < this->nrIngrediente) {
//			return this->ingrediente[pozitie];
//		}
//		else {
//			throw new ExceptieIndex("Index incorect");
//		}
//	}
//
//	friend istream& operator>>(istream& tastatura, Prajitura& p);
//};
//float Prajitura::TVA = 9;
//int Prajitura::contor = 1;
//
//Prajitura Prajitura ::operator++()
//{
//	this->calorii++;
//	return *this;
//}
//
//ostream& operator << (ostream& monitor, Prajitura p) {
//	monitor <<"Prajitura are "<< p.getCalorii()<<" calorii";
//	monitor <<"Are "<< p.getNrIngrediente()<<" ingrediente. Acestea sunt:";
//	for (int i = 0; i < p.getNrIngrediente(); i++) {
//		monitor << p.getIngredient(i)<<", ";
//	}
//	return monitor;
//}
//
//istream& operator>>(istream& tastatura, Prajitura& p) {
//	cout << "denumire:";
//	tastatura >> p.denumire;
//	cout << "Cate ingrediente are:";
//	tastatura >> p.nrIngrediente;
//	if (p.ingrediente != NULL) {
//		delete[]p.ingrediente;
//	}
//	p.ingrediente = new string[p.nrIngrediente];
//	for (int i = 0; i < p.nrIngrediente; i++) {
//		cout << "Ingredient:";
//		tastatura >> p.ingrediente[i];
//	}
//	cout << "Cate calorii are:";
//	tastatura >> p.calorii;
//
//	return tastatura;
//}
//
//Prajitura operator+(Prajitura p, int valoare) {
//	Prajitura result = p;
//	result.setCalorii(p.getCalorii() + valoare);
//	return result;
//}
//
//Prajitura operator+(int valoare, Prajitura p) {
//	Prajitura result = p;
//	result.setCalorii(p.getCalorii() + valoare);
//	return result;
//}
//
//float pretTotal(float pretInitial, Prajitura p) {
//	return pretInitial + (pretInitial*Prajitura::TVA / 100);
//}
//
//class PrajituraComerciala : public Prajitura {
//private:
//	float greutate;
//	float pret;
//public:
//	PrajituraComerciala() :Prajitura() {
//		this->greutate = 300;
//		this->pret = 10;
//	}
//	PrajituraComerciala(float greutate, float pret) :Prajitura("Profiterol", 3, new string[3]{ "inghetata","ciocolata","gogosi" }, 400) {
//		this->greutate = greutate;
//		this->pret = pret;
//	}
//	PrajituraComerciala(string denumire, int nrIngrediente, string* ingrediente, float calorii, float greutate, float pret) :Prajitura(denumire, nrIngrediente, ingrediente, calorii) {
//		this->greutate = greutate;
//		this->pret = pret;
//	}
//	PrajituraComerciala(const PrajituraComerciala &pc) :Prajitura(pc) {
//		this->greutate = pc.greutate;
//		this->pret = pc.pret;
//	}
//	PrajituraComerciala operator=(const PrajituraComerciala& pc) {
//		Prajitura::operator=(pc);
//		this->greutate = pc.greutate;
//		this->pret = pc.pret;
//		return *this;
//	}
//	~PrajituraComerciala() {
//
//	}
//		
//	//operator afisare
//	friend ostream& operator<<(ostream& out, PrajituraComerciala pc) {
//		out << (Prajitura)pc;
//		out << "Greutate:" << pc.greutate << endl;
//		out << "Pret:" << pc.pret << endl;
//		return out;
//	}
//
//	friend istream& operator>>(istream& in, PrajituraComerciala& pc) {
//		in >> (Prajitura&)pc;
//		cout << "Greutate";
//		in >> pc.greutate;
//		cout << "Greutate";
//		in >> pc.pret;
//
//		return in;
//	}
//
//	explicit operator float() {
//		return greutate;
//	}
//};
//
//
//
//void main() {
//	Prajitura p;
//	p.setCalorii(6);
//	PrajituraComerciala pc;
//	pc.setCalorii(6);
//	cout << pc.getCalorii();
//	cin >> pc;
//	cout << pc;
//
//	float greutate = (float)pc;
//}