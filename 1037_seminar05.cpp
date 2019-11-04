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
//
//public:
//	static float TVA;
//	Prajitura() :id(contor), nrIngrediente(3) {
//		this->denumire = "Amandina";
//		this->ingrediente = new string[3];
//		this->ingrediente[0] = "Zahar";
//		this->ingrediente[1] = "Lapte";
//		this->ingrediente[2] = "Faina";
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
//		return *this;
//
//	}
//
//	Prajitura(string denumire, int nrIngrediente, string * ingrediente) :id(contor++) {
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
//	}
//
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
//};
//float Prajitura::TVA = 9;
//int Prajitura::contor = 1;
//
//
//float pretTotal(float pretInitial, Prajitura p) {
//	return pretInitial + (pretInitial*Prajitura::TVA / 100);
//}
//
//void main() {
//	Prajitura p;
//	cout << p.getIngrediente()[1];
//	try {
//		p.getIngredient(-1);
//	}
//	catch (ExceptieIndex ei) {
//		cout << ei.getMesaj();
//	}
//	cout << p.getIngredient(1);
//	Prajitura p2 = p;
//	cout << pretTotal(8, p);
//
//	Prajitura p3;
//	p3 = p;
//}