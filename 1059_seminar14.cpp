//#include<iostream>
//#include<vector>
//#include<set>
//#include<numeric>
//#include<algorithm>
//
//using namespace std;
//
//class Calorifer {
//	int nrElementi;
//public:
//	Calorifer() {
//		nrElementi = 18;
//	}
//	Calorifer(int nr) :nrElementi(nr) {
//
//	}
//
//	bool operator<(const Calorifer& c)const {
//		return this->nrElementi < c.nrElementi;
//	}
//
//	friend ostream& operator<<(ostream& o, Calorifer c) {
//		o << "Numar elementi: " << c.nrElementi << endl;
//		return o;
//	}
//};
//
//template<class T>
//bool functieComparare(T a, T b) {
//	return a > b;
//}
//
//
//
//void main() {
//	vector<int>v;
//	v.push_back(5);
//	v.push_back(8);
//	v.push_back(2);
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << endl;
//	}
//
//	set<Calorifer> calorifere;
//
//	Calorifer c1(12);
//	Calorifer c2;
//	Calorifer c3(4);
//
//	calorifere.insert(c1);
//	calorifere.insert(c2);
//	calorifere.insert(c3);
//
//	set<Calorifer>::iterator it;
//
//	it = calorifere.begin();
//	while (it != calorifere.end()) {
//		cout << *it<<endl;
//		it++;
//	}
//
//	
//	sort(v.begin(), v.end(), functieComparare<int>);
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << endl;
//	}
//}