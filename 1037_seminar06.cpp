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
//};
//float Prajitura::TVA = 9;
//int Prajitura::contor = 1;
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
//void main() {
//	Prajitura p1("Tiramisu", 2, new string[2]{ "lapte","faina" }, 10);
//	Prajitura p2("Alba ca zapada", 3, new string[3]{ "lapte","faina", "cacao" }, 20);
//	Prajitura p3("Cremsmit", 3, new string[3]{ "lapte","faina", "zahar" }, 80);
//
//	{
//		Prajitura p4;
//	}
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	a = b + c;
//	//			exteriorul clasei		in clasa
//	p1 = p2 + p3;//operator+(p2,p3)==>p2.operator+(p3)
//	p1 = p2 + 10;//operator+(p2,10)==>p2.operator+(10)
//	p1 = 10 + p2;//operator+(10,p2)==>
//
//	p3 += p1 += p2;
//	bool conditie = true;
//	cout<<(conditie ? "este adevarat" : "nu este adevarat");
//	cout << (p1 >= p2 ? "P1 are mai multe calorii" : "P2 are mai multe calorii");
//}