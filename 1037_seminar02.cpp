//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Ponei {
//public:
//	string culoare;
//	bool potcovit;
//	float greutate;
//	int inaltime;
//	char* rasa;
//
//	Ponei initializarePonei(string culoare, bool potcovit, float greutate, int inaltime, const char* rasa) {
//		Ponei ponei;
//		ponei.culoare = culoare;
//		ponei.potcovit = potcovit;
//		ponei.greutate = greutate;
//		ponei.inaltime = inaltime;
//		ponei.rasa = new char[strlen(rasa) + 1];
//		strcpy(ponei.rasa, rasa);
//		return ponei;
//	}
//
//	void afisarePonei() { //void afisarePonei(Ponei* this)
//		cout << "Rasa: " << this->rasa<<endl;
//		cout << "Culoare: " << culoare<<endl;
//		cout << "Inaltime: " << inaltime << endl;
//		cout << "Greutate: " << greutate << endl;
//		cout << "Potcovit: " << potcovit << endl;
//	}
//
//	void citesteDeLaTastatura() {
//		cout << "Culoare:";
//		cin >> (*this).culoare;
//		char temp[20];
//		cout << "Rasa:";
//		cin >> temp;
//		this->rasa = new char[strlen(temp) + 1];
//		strcpy(this->rasa, temp);
//		cout << "Este potcovit? 0-NU, 1-DA";
//		cin >> this->potcovit;
//		cout << "Greutate:";
//		cin >> this->greutate;
//		cout << "Inaltime:";
//		cin >> this->inaltime;
//	}
//};
//
//void main() {
//
//	Ponei ponei;
//	ponei = ponei.initializarePonei("Negru", true, 48, 97, "Shetland");
//	ponei.afisarePonei();
//	Ponei ponei2 = ponei.initializarePonei("Alb", false, 60, 102, "Rasa noua");
//	ponei2.afisarePonei();//afisarePonei(&ponei2)
//
//	Ponei ponei3;
//	ponei3.citesteDeLaTastatura();
//	ponei3.afisarePonei();
//	ponei.afisarePonei();
//}