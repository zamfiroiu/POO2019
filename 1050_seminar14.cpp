#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Carte {
	int nrPagini;
public:
	Carte() {
		nrPagini = 100;
	}
	Carte(int nr) :nrPagini(nr) {

	}

	bool operator<(Carte c) const {
		return this->nrPagini < c.nrPagini;
	}

	friend ostream &operator<<(ostream& o, Carte c) {
		o << "Cartea are " << c.nrPagini << " pagini." << endl;
		return o;
	}
};

bool functieComparare(int a, int b) {
	return a > b;
}

void main() {
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(8);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	set<Carte> carti;
	Carte c1(400);
	Carte c2;
	Carte c3(300);

	carti.insert(c1);
	carti.insert(c2);
	carti.insert(c3);

	set<Carte>::iterator it;
	it = carti.begin();
	while (it != carti.end()) {
		cout << *it<<endl;
		it++;
	}


	sort(v.begin(), v.end(), functieComparare);

	for (vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++) {
		cout << *it2 << endl;
	}
	
}