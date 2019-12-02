#include<iostream>
#include<string>
using namespace std;

class Materie {
private:
	float pondereSeminar;
	string denumire;
public:
	static int notaTrecere;
	Materie() {
		pondereSeminar = 0.4;
		denumire = "POO";
	}
	Materie(float pondere, string denumire) {
		this->pondereSeminar = pondere;
		this->denumire = denumire;
	}


	Materie(int pondere, string denumire) {
		this->pondereSeminar = pondere;
		this->denumire = denumire;
	}

	explicit operator float() {
		return 1-pondereSeminar;
	}
	friend ostream& operator << (ostream& out, Materie &m);
	friend istream& operator>>(istream& ist, Materie &m) {
		cout << "Denumire :";
		ist >> m.denumire;
		cout << "Pondere: ";
		ist >> m.pondereSeminar;
		return ist;
	}
};
int Materie::notaTrecere = 5;
ostream& operator << (ostream& out, Materie &m)
{
	out << endl << m.denumire;
	out << endl << m.pondereSeminar;
	return out;
}

class Student {
private:
	string nume;
	int nrMaterii;
	Materie * materii;

public:
	Student() {
		nume = "Popescu";
		nrMaterii = 0;
		materii = NULL;
	}
	Student(string nume, int nrMaterii, Materie*materii) {
		this->nume = nume;
		if (nrMaterii > 0 && materii != NULL) {


			this->nrMaterii = nrMaterii;
			this->materii = new Materie[nrMaterii];
			for (int i = 0; i < nrMaterii; i++) {
				this->materii[i] = materii[i];
			}
		}
		else {
			this->nrMaterii = 0;
			this->materii = NULL;
		}
	}
	Student(Student&s) {
		this->nume = s.nume;
		this->nrMaterii = s.nrMaterii;
		if (s.materii != NULL) {
			this->materii = new Materie[s.nrMaterii];
			for (int i = 0; i < s.nrMaterii; i++) {
				this->materii[i] = s.materii[i];
			}
		}
		else {
			this->materii = NULL;
		}
	}
	Student &operator=(const Student&s) {
		this->nume = s.nume;
		this->nrMaterii = s.nrMaterii;
		if (s.materii != NULL) {
			if (this->materii != NULL) {
				delete[]this->materii;
			}
			this->materii = new Materie[s.nrMaterii];
			for (int i = 0; i < s.nrMaterii; i++) {
				this->materii[i] = s.materii[i];
			}
		}
		else {
			this->materii = NULL;
		}
		return*this;
	}

	~Student() {
		if (this->materii != NULL) {
			delete[]this->materii;
		}
	}

	friend ostream & operator << (ostream& monitor, Student &s)
	{
		monitor << endl << s.nume;
		monitor << endl << s.nrMaterii;
		for (int i = 0; i < s.nrMaterii; i++)
		{
			monitor << s.materii[i];

		}
		return monitor;
	}
	friend istream& operator>>(istream& ist, Student &s) {
		cout << "Nume: ";
		ist >> s.nume;
		cout << "Numar de materii: ";
		ist >> s.nrMaterii;
		if (s.materii != NULL) {
			delete[]s.materii;
		}
		s.materii = new Materie[s.nrMaterii];
		for (int i = 0; i < s.nrMaterii; i++) {
			ist >> s.materii[i];
		}
		return ist;
	}
};

void main() {
	Materie m((float)0.5, "CTS");
	cout << m.notaTrecere;

	int a = (float)m;
	Materie* v = new Materie[2];
	v[0] = m;

	Student s("Popescu",2,v);
	cin >> s;
	cout << s;

}