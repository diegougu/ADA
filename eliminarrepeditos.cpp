#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> combinar(const vector<int>& izq, const vector<int>& der) {
	unordered_set<int> hash;
	vector<int> solve;
	for (int i = 0; i < izq.size(); i++) {
		auto e = hash.find(izq[i]);
		if (e == hash.end()) {
			solve.push_back(izq[i]);
			hash.insert(izq[i]);
		}
	}

	for (int i = 0; i < der.size(); i++) {
		auto e = hash.find(der[i]);
		if (e == hash.end()) {
			solve.push_back(der[i]);
			hash.insert(der[i]);
		}
	}
	return solve;
}

vector<int> eliminarrepeditos(const vector<int>& vc) {
	if (vc.size() <= 1) {
		return vc;
	}

	int mid = vc.size() / 2;
	vector<int> izq(vc.begin(), vc.begin() + mid);
	vector<int> der(vc.begin() + mid, vc.end());

	izq = eliminarrepeditos(izq);
	der = eliminarrepeditos(der);

	return combinar(izq, der);
}


int main() {
	vector<int> A = { 4, 2, 9, 4, 2, 3, 9, 1, 7 };

	vector<int> sinDuplicados = eliminarrepeditos(A);

	cout << "Vector sin duplicados (orden no garantizado):\n";
	for (int x : sinDuplicados)
		cout << x << " ";
	cout << endl;

	return 0;
}
