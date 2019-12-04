#include<iostream>
#include<string>

using namespace std;

class Dispozitiv {
private:
	int anFabricatie;
public:
	Dispozitiv() {
		anFabricatie = 2000;
	}
	Dispozitiv(int an) {
		anFabricatie = an;
	}

	virtual void afiseazaDispozitiv() {
		cout << "An:" << anFabricatie << endl;
	}

	virtual float capacitateBaterie() = 0;

	virtual ~Dispozitiv() {
		cout << "A fost apelat destructorul din Dispozitiv" << endl;
	}

};

class Robot :public Dispozitiv {
private:
	int nrBaterii;
	string nume;

public:

	float capacitateBaterie() {
		return nrBaterii * 100;
	}
	Robot() :Dispozitiv() {
		nrBaterii = 2;
		nume = "";
	}

	Robot(int an, int nrBaterii, string nume) :Dispozitiv(an) {
		this->nrBaterii = nrBaterii;
		this->nume = nume;
	}
	void afiseazaDispozitiv() {
		cout << "Robotul " << nume << " are " << nrBaterii << " baterii"<<endl;
	 }

	~Robot() {
		cout << "Destructor Robot" << endl;
	}
};

void main() {
	//Dispozitiv d(2019);
	//d.afiseazaDispozitiv();

	//Robot r(2017, 4, "Sofia");
	//r.afiseazaDispozitiv();

	//Dispozitiv* p = &r;
	//p->afiseazaDispozitiv();

	/*Dispozitiv ** dispozitive = new Dispozitiv*[4];
	dispozitive[0] = new Robot(2014, 3, "Mr. Robot");
	dispozitive[1] = new Dispozitiv(2018);
	dispozitive[2] = new Dispozitiv(2018);
	dispozitive[3] = new Robot(2014, 6, "Wall-e");

	for (int i = 0; i < 4; i++) {
		dispozitive[i]->afiseazaDispozitiv();
	}*/


	Dispozitiv* p = new Robot(2019, 8, "BumbleBee");
	delete p;

	Dispozitiv *d=new Robot();
	d->capacitateBaterie();


}