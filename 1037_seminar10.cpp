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
//	virtual ~Prajitura() {
//		cout << "Destructor prajitura" << endl;
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
//class Produs {
//private:
//	int cantitate;
//public:
//	Produs() {
//		cantitate = 1;
//	}
//	Produs(int cantitate) {
//		this->cantitate = cantitate;
//	}
//	virtual void vindeProdus() {
//		cout << "Produsul s-a vandut."<<endl;
//	}
//
//	virtual float calculeazaPretTotal(float TVA) = 0;
//};
//
//
//class PrajituraComerciala : public Prajitura, public Produs {
//private:
//	float greutate;
//	float pret;
//public:
//
//	void vindeProdus() {
//		cout << "S-a vandut prajitura cu pretul " << pret << endl;
//	}
//
//	float calculeazaPretTotal(float TVA) {
//		return pret * TVA+pret;
//	}
//
//	PrajituraComerciala() :Prajitura(),Produs() {
//		this->greutate = 300;
//		this->pret = 10;
//	}
//	PrajituraComerciala(float greutate, float pret) :Prajitura("Profiterol", 3, new string[3]{ "inghetata","ciocolata","gogosi" }, 400),Produs(1) {
//		this->greutate = greutate;
//		this->pret = pret;
//	}
//	PrajituraComerciala(string denumire, int nrIngrediente, string* ingrediente, float calorii, float greutate, float pret) :Prajitura(denumire, nrIngrediente, ingrediente, calorii),Produs(2) {
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
//		cout << "Destructor prajitura comericala";
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
//class LumanareOnomastica :public Produs {
//private:
//	float pret;
//public:
//	LumanareOnomastica():Produs(1) {
//		pret = 1;
//	}
//	LumanareOnomastica(int cantitate, float pret):Produs(cantitate) {
//		this->pret = pret;
//	}
//
//	float calculeazaPretTotal(float TVA) {
//		return pret + pret * (TVA-0.05);
//	}
//};
//
//
//
//void main() {
//	//Prajitura* p1 = new PrajituraComerciala();
//	//delete p1;
//
//	Produs * pp = new PrajituraComerciala(20,100);
//	//Produs* p = new Produs();
//
//	//p->vindeProdus();
//	pp->vindeProdus();
//	cout << "Pret total:" << pp->calculeazaPretTotal(0.09) << endl;
//
//	//Produs produs;
//
//	Produs** produse = new Produs*[4];
//	produse[0] = new LumanareOnomastica(3, 20);
//	produse[1] = new PrajituraComerciala(20, 20);
//	produse[2] = new PrajituraComerciala(40, 20);
//	produse[3] = new LumanareOnomastica(5, 20);
//
//	for (int i = 0; i < 4; i++) {
//		cout<<produse[i]->calculeazaPretTotal(0.09) << endl;
//	}
//}