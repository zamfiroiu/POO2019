#include<iostream>

using namespace std;

struct Animal {
	string rasa;
	char* culoare;
	int nrPicioare;
	float greutate;
	bool esteMascul;
};

Animal initializareAnimal(string rasa, const char* culoare, int nrPicioare, float greutate, bool esteMascul) {
	Animal a;
	a.rasa = rasa;
	//a.culoare = (char*)malloc(sizeof(char)*(strlen(culoare) + 1));
	a.culoare = new char[strlen(culoare) + 1];
	strcpy(a.culoare, culoare);
	a.nrPicioare = nrPicioare;
	a.greutate = greutate;
	a.esteMascul = esteMascul;
	return a;
}

void interschimbare1(int a, int b) {
	int aux = a;
	a = b;
	b = aux;
}

void interschimbare2(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void interschimbare3(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}


void main() {
	//Animal caine;
	//caine = initializareAnimal("Bulldog", "alb", 4, 25, true);
	//cout << caine.culoare << endl;
	//Animal * pA;
	//pA = &caine;
	//(*pA).greutate = 24;
	//pA->greutate = 23;
	//pA = pA + 2;

	//Animal *p2A = pA;
	//pA -= 2;

	//cout << p2A - pA;

	//int x = 5;
	//int y = 8;
	//cout << x << " " << y << endl;
	//interschimbare1(x, y);
	//cout << x << " " << y << endl;
	//interschimbare2(&x, &y);
	//cout << x << " " << y << endl;
	//interschimbare3(x, y);
	//cout << x << " " << y << endl;

	//int z = 10;
	//int &rZ = z;
	//rZ++;
	//cout << "Z:" << z<<endl<<endl;


	//int* *vectorP;
	//int dimensiuneVector = 3;
	//vectorP = new int*[dimensiuneVector];
	//for (int i = 0; i < dimensiuneVector; i++) {
	//	vectorP[i] = new int(5);
	//}

	//for (int i = 0; i < dimensiuneVector; i++) {
	//	cout << *vectorP[i]<<endl;
	//}

	Animal **pointerA;
	pointerA = new Animal*[2];
	for (int i = 0; i < 2; i++)
	{
		Animal b;
		pointerA[i] = new Animal();
		b = initializareAnimal("pitbull", "albastru", 4, 10 * (i + 1), true);
		pointerA[i]->culoare = b.culoare;
		//shallow copy
		//pointerA[i]->greutate = b.greutate;
		pointerA[i]->nrPicioare = b.nrPicioare;
		pointerA[i]->rasa = b.rasa;
		pointerA[i]->esteMascul = b.esteMascul;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << pointerA[i]->greutate << " ";
	}
	


}