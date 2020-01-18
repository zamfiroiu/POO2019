//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int suma(int a, int b) {
//	return a + b;
//}
//
//float suma(float a, float b) {
//	return a + b;
//}
//
//template<class tip>
//tip suma(tip a, tip b) {
//	return a + b;
//}
//
//
//template<class T1, class T2, class T3>
//T1 functie(T2 param, T3 parametru) {
//
//}
//
//template<class TIP>
//class Colectie {
//private:
//	TIP* elemente;
//	int nrElemente;
//public:
//	Colectie() {
//		elemente = NULL;
//		nrElemente = 0;
//	}
//	Colectie(int nrElemente, TIP*elemente) {
//		this->nrElemente = nrElemente;
//		if (nrElemente > 0) {
//			this->elemente = new TIP[nrElemente];
//			for (int i = 0; i < nrElemente; i++) {
//				this->elemente[i] = elemente[i];
//			}
//		}
//		else {
//			this->elemente = NULL;
//		}
//	}
//	~Colectie() {
//		if (this->elemente != NULL) {
//			delete[]this->elemente;
//		}
//	}
//
//	Colectie(const Colectie& c) {
//		this->nrElemente = c.nrElemente;
//		if (c.elemente != NULL) {
//			this->elemente = new TIP[c.nrElemente];
//			for (int i = 0; i < c.nrElemente; i++) {
//				this->elemente[i] = c.elemente[i];
//			}
//		}
//		else {
//			this->elemente = NULL;
//		}
//	}
//
//	Colectie operator=(const Colectie&c) {
//		this->nrElemente = c.nrElemente;
//		if (c.elemente != NULL) {
//			if (this->elemente != NULL) {
//				delete[]this->elemente;
//			}
//			this->elemente = new TIP[c.nrElemente];
//			for (int i = 0; i < c.nrElemente; i++) {
//				this->elemente[i] = c.elemente[i];
//			}
//		}
//		else {
//			this->elemente = NULL;
//		}
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& consola, const Colectie& c) {
//		consola << "In colectie sunt " << c.nrElemente << " elemente:" << endl;
//		for (int i = 0; i < c.nrElemente; i++) {
//			consola << c.elemente[i]<<endl;
//		}
//		return consola;
//	}
//
//	Colectie operator+=(TIP element) {
//		TIP*temp = new TIP[this->nrElemente + 1];
//		for (int i = 0; i < this->nrElemente; i++) {
//			temp[i] = this->elemente[i];
//		}
//		if (this->elemente != NULL) {
//			delete[]this->elemente;
//		}
//		temp[this->nrElemente] = element;
//		this->elemente = temp;
//		this->nrElemente++;
//		return *this;
//	}
//
//	void adaugaElement(TIP element) {
//		(*this) += element;
//	}
//};
//
//
//class Masinuta {
//private:
//	float pret;
//	int nrRoti;
//public:
//	Masinuta(int nrRoti, float pret) {
//		this->pret = pret;
//		this->nrRoti = nrRoti;
//	}
//	Masinuta() {
//		pret = 0;
//		nrRoti = 0;
//	}
//	friend ostream& operator<<(ostream&out, Masinuta m) {
//		out << "Are " << m.nrRoti << " roti si costa " << m.pret << endl;
//		return out;
//	}
//
//	Masinuta& operator+(const Masinuta& m) {
//		Masinuta r = *this;
//		r.nrRoti = this->nrRoti + m.nrRoti;
//		r.pret = this->pret + m.pret;
//		return r;
//	}
//};
//
//void main() {
//	/*int a = 5;
//	int b = 4;
//	cout << suma(a, b)<<endl;
//
//	float x = 5.7f;
//	float y = 4.6f;
//	cout << suma<float>(a, y) << endl;
//
//	string c = "sir";
//	string d = " de caractere";
//	cout << suma(c, d);
//
//	Masinuta m1(2, 20);
//	Masinuta m2(4, 35);
//
//	cout << suma(m1, m2);*/
//
//
//	Colectie<int> colectieValoriIntregi;
//
//	Colectie<float>colectieValoriReale(2, new float[2]{ 3.6f,8.2f });
//	cout << colectieValoriReale;
//
//	Masinuta m1(2, 20);
//	Masinuta m2(4, 35);
//
//	Masinuta* vector = new Masinuta[2]{ m1,m2 };
//
//	Colectie<Masinuta> colectieMasinute(2, vector);
//	cout << colectieMasinute;
//
//	Masinuta m3(6, 30);
//
//	colectieMasinute.adaugaElement(m3);
//	cout << colectieMasinute;
//}