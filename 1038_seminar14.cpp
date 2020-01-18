#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Produs {
	float pret;
public:
	Produs() {
		pret = 0;
	}
	Produs(float pretNou) :pret(pretNou) {

	}

	bool operator<(Produs p)const {
		return this->pret < p.pret;
	}

	friend ostream& operator<<(ostream& o, Produs p) {
		o << "Pret:" << p.pret<<endl;
		return o;
	}
};


bool functieComparare(int a, int b) {
	return a> b;
}

void main() {
	vector<int> v;
	v.push_back(6);
	v.push_back(2);
	v.push_back(5);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	set<Produs> produse;

	Produs p1(40);
	Produs p2;
	Produs p3(20);

	produse.insert(p1);
	produse.insert(p2);
	produse.insert(p3);

	set<Produs>::iterator it;
	it = produse.begin();
	while (it != produse.end()) {
		cout << *it;
		it++;
	}

	
	sort(v.begin(), v.end(),functieComparare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}