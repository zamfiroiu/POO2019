//#include<iostream>
//
//
//using namespace std;
//
////int suma(int a, int b) {
////	return a + b;
////}
////
////float suma(float a, float b) {
////	return a + b;
////}
//
//template<class tip>
//tip suma(tip a, tip b) {
//	return a + b;
//}
//
//template<class T1,class T2>
//T1 functie(T2 obiect) {
//
//}
//
//template <class TIP>
//class Colectionar {
//private:
//	TIP* elemente;
//	int nrElemente;
//public:
//	Colectionar() {
//		this->elemente = NULL;
//		this->nrElemente = 0;
//	}
//	Colectionar(TIP*elemente, int nrElemente) {
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
//	Colectionar(const Colectionar& c) {
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
//	Colectionar operator=(const Colectionar& c) {
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
//	~Colectionar() {
//		if (this->elemente != NULL) {
//			delete[]this->elemente;
//		}
//	}
//
//	Colectionar operator+=(TIP element) {
//		this->nrElemente++;
//		TIP* temp = new TIP[this->nrElemente];
//		for (int i = 0; i < this->nrElemente - 1; i++) {
//			temp[i] = this->elemente[i];
//		}
//		temp[this->nrElemente - 1] = element;
//		if (this->elemente != NULL) {
//			delete[]this->elemente;
//		}
//		this->elemente = temp;
//		return *this;
//	}
//
//	void adaugaElement(TIP element) {
//		(*this) += element;
//	}
//
//	friend ostream& operator<<(ostream& out, const Colectionar& c) {
//		out << "Colectionarul are " << c.nrElemente<< " elemente:";
//		for (int i = 0; i < c.nrElemente; i++) {
//			out << c.elemente[i];
//		}
//		return out;
//	}
//};
//
//class Sesiune {
//private:
//	int nrExamene;
//	int nrZileSesiune;
//public:
//	Sesiune operator+(Sesiune s) {
//		Sesiune result = *this;
//		result.nrExamene = this->nrExamene + s.nrExamene;
//		result.nrZileSesiune = this->nrZileSesiune + s.nrZileSesiune;
//		return result;
//	}
//	Sesiune(int nrExamene, int nrZile) {
//		this->nrExamene = nrExamene;
//		this->nrZileSesiune = nrZile;
//	}
//	Sesiune() {
//		this->nrExamene = 0;
//		this->nrZileSesiune = 0;
//	}
//
//	friend ostream& operator<<(ostream& monitor, const Sesiune & s) {
//		monitor << s.nrExamene << " examene in " << s.nrZileSesiune << " zile."<<endl;
//		return monitor;
//	}
//};
//
//void main() {
//	//int x = 4;
//	//int y = 5;
//	//cout << suma(x, y)<<endl;
//
//	//float a = 4.6;
//	//float b = 5.7;
//	//cout << suma<float>(a, y)<<endl;
//
//	//Sesiune iarna(7, 21);
//	//Sesiune vara(6, 21);
//
//	//cout << suma(iarna, vara);
//
//	//int rezultat=functie<int, float>(6.5);
//
//	Colectionar<int> colectieIntregi;
//	int nrElemente = 4;
//	float* elemente = new float[4]{ 4.6f,6.8f,3.9f,4.8f };
//	Colectionar<float>colectieReale(elemente, nrElemente);
//
//	Sesiune iarna(7, 21);
//	Sesiune vara(6, 21);
//	int nrSesiuni = 2;
//	Sesiune* sesiuni = new Sesiune[2]{ iarna,vara };
//	Colectionar<Sesiune>student(sesiuni, nrSesiuni);
//	cout << student<<endl<<endl;
//
//	Sesiune sesiuneSpeciala(20, 7);
//	student.adaugaElement(sesiuneSpeciala);
//	cout << student << endl << endl;
//
//}