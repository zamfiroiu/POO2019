//#include<iostream>
//#include<vector>
//#include<set>
//
//#include<algorithm>
//
//using namespace std;
//
//class Sesiune {
//	int nrExamene;
//public:
//	Sesiune() {
//		nrExamene = 5;
//	}
//
//	Sesiune(int nr) :nrExamene(nr) {
//
//	}
//
//	bool operator<(const Sesiune s) const {
//		return this->nrExamene < s.nrExamene;
//	}
//	friend ostream&operator<<(ostream& o, Sesiune s) {
//		o <<"Numar exmaene:"<< s.nrExamene << endl;
//		return o;
//	}
//};
//
//bool metodaComparare(int a, int b) {
//	return a > b;
//}
//
//void main() {
//
//	vector<int> nrIntregi;
//	nrIntregi.push_back(3);
//	nrIntregi.push_back(7);
//	nrIntregi.push_back(2);
//
//	for (int i = 0; i < nrIntregi.size(); i++) {
//		cout << nrIntregi[i] << endl;
//	}
//
//	set<Sesiune> sesiuni;
//	Sesiune s1(3);
//	Sesiune s2;
//	Sesiune s3(2);
//	sesiuni.insert(s1);
//	sesiuni.insert(s2);
//	sesiuni.insert(s3);
//	
//	set<Sesiune>::iterator it;//definire iterator pentru un set cu sesiuni
//	it = sesiuni.begin();
//	while (it != sesiuni.end()) {
//		cout << *it;
//		it++;
//	}
//
//
//	sort(nrIntregi.begin(), nrIntregi.end(), metodaComparare);
//	
//	vector<int>::iterator it2;
//	for (it2 = nrIntregi.begin(); it2 != nrIntregi.end(); it2++) {
//		cout << *it2 << endl;
//	}
//
//}