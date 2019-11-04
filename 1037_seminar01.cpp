//#include<iostream>
//
//using namespace std;
//
//struct Fruct {
//	string culoare;
//	char* denumire;
//	float greutate;
//	int nrSeminte;
//	bool dulce;
//};
//
//Fruct initializareFruct(string culoare, const char* denumire, float greutate, int nrSeminte, bool dulce) {
//	Fruct f;
//	f.culoare = culoare;
//	//f.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	f.denumire = new char[strlen(denumire) + 1];
//	strcpy(f.denumire, denumire);
//	f.greutate = greutate;
//	f.nrSeminte = nrSeminte;
//	f.dulce = dulce;
//	return f;
//}
//
//void main() {
//	Fruct mar;
//	mar = initializareFruct("Verde", "mar", 100.5, 6, true);
//
//	cout << mar.denumire<<endl;
//
//	Fruct * pFruct;
//	pFruct = &mar;
//
//	(*pFruct).nrSeminte = 18;
//	pFruct->nrSeminte = 14;
//
//	cout<< "Marime: " << sizeof(Fruct);
//	cout << "Adresa initiala: " << pFruct<<endl;
//	Fruct *pf2 = pFruct+2;
//	cout << "Adresa finala: " << pFruct << endl;
//
//	int nr = pf2 - pFruct;
//
//	cout << "Numar: " << nr;
//
//
//}