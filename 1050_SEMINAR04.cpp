#include<iostream>

using namespace std;

class Film {
private:
	static int nrObiecte;
	static float TVAPret;
	const int id;
	string nume;
	int nrActori;
	int * varsteActori;
	char* regizor;
public:
	Film(string nume, int nrActori, int* varste, const char* regizor) :id(nrObiecte) {
		this->nume = nume;
		this->nrActori = nrActori;
		this->varsteActori = new int[nrActori];
		for (int i = 0; i < nrActori; i++) {
			this->varsteActori[i] = varste[i];
		}
		this->regizor = new char[strlen(regizor) + 1];
		strcpy(this->regizor, regizor);
		nrObiecte++;
	}

	Film() :id(nrObiecte), nrActori(0) {
		this->nume = "Anonim";
		//this->nrActori = 0;
		this->varsteActori = NULL;
		this->regizor = NULL;
		nrObiecte++;
	}

	int* getVarsteActor() {
		return varsteActori;
	}
	int getVarstaActor(int index) {
		if (index >= 0 && index < nrActori) {
			return varsteActori[index];
		}
		else throw - 1;
	}

	void setVarsteActori(int* varste, int nrActori) {
		if (varste != NULL && nrActori > 0) {
			if (this->varsteActori != NULL) {
				delete[]this->varsteActori;
			}
			this->varsteActori = new int[nrActori];
			for (int i = 0; i < nrActori; i++) {
				this->varsteActori[i] = varste[i];
			}
			this->nrActori = nrActori;
		}
	}
};

int Film::nrObiecte = 0;
float Film::TVAPret = 0.19;

void main() {


	Film f("Ion", 3, new int[3]{ 27,35,23 }, "Vasile");
	f.setVarsteActori(new int[3]{ 22,24,38 }, 3);

	Film f2;
	Film f3();

	Film * pFilm = new Film("Ionela", 4, new int[4]{ 21,22,23,24 }, "Ionel");
	Film * vectorFilme = new Film[3];

	Film ** vectorPointeri = new Film*[5];
	for (int i = 0; i < 5; i++) {
		vectorPointeri[i] = new Film();
	}
}