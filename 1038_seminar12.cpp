#include<iostream>
#include<fstream>

using namespace std;

class CitireScriere {
	virtual void scrieInFisierBinar(fstream& fisier) = 0;
	virtual void citesteDinFisierBinar(fstream& fisier) = 0;
};

class Calculator:public CitireScriere {
private:
	char* model;
	int anProductie;
	float pret;
public:
	Calculator() {
		this->anProductie = 0;
		this->pret = 0;
		this->model = NULL;
	}

	Calculator(const char* model, int anProductie, float pret)
	{
		this->anProductie = anProductie;
		this->pret = pret;
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}

	Calculator(const Calculator& c)
	{
		this->anProductie = c.anProductie;
		this->pret = c.pret;
		if (c.model != NULL)
		{
			this->model = new char[strlen(c.model) + 1];
			strcpy(this->model, c.model);
		}
		else
		{
			this->model = NULL;
		}
	}

	Calculator operator=(const Calculator& c)
	{
		this->anProductie = c.anProductie;
		this->pret = c.pret;
		if (this->model != NULL)
		{
			delete[]this->model;
		}
		if (c.model != NULL)
		{
			this->model = new char[strlen(c.model) + 1];
			strcpy(this->model, c.model);
		}
		else
		{
			this->model = NULL;
		}
		return *this;
	}

	~Calculator() {
		if (this->model != NULL)
		{
			delete[]this->model;
		}
	}

	friend ostream& operator<<(ostream& o, const Calculator& c) {
		o << "Model:" << c.model << endl;
		o << "An productie:" << c.anProductie << endl;
		o << "Pret:" << c.pret<<endl;
		return o;
	}

	void scrieInFisierBinar(fstream& fisier) {
		fisier.write((char*)&this->anProductie, sizeof(int));
		int nrCaractere = strlen(this->model);
		fisier.write((char*)&nrCaractere, sizeof(int));
		for (int i = 0; i < nrCaractere; i++) {
			fisier.write((char*)&this->model[i], sizeof(char));
		}

		fisier.write((char*)&this->pret, sizeof(float));
	}
	void citesteDinFisierBinar(fstream& fisier) {
		fisier.read((char*)&this->anProductie, sizeof(int));
		int lungime = 0;
		fisier.read((char*)&lungime, sizeof(int));
		if (this->model != NULL) {
			delete[]this->model;
		}
		this->model = new char[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			fisier.read((char*)&this->model[i], sizeof(char));
		}
		this->model[lungime] = '\0';
		fisier.read((char*)&this->pret, sizeof(float));
	}
};

void main() {
	//Calculator c1("Acer", 2016, 2000);
	//fstream fisOut("calculatoare.txt", ios::out | ios::binary);
	//c1.scrieInFisierBinar(fisOut);
	//fisOut.close();

	fstream fisIn("calculatoare.txt", ios::binary | ios::in);
	Calculator c2;
	c2.citesteDinFisierBinar(fisIn);
	cout << c2;
	fisIn.close();
}