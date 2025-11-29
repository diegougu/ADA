#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


vector<int> combinar(vector<int>& a, vector<int>& b) {
	unordered_set<int> hash;
	vector<int> solve;
	for (int i = 0; i < a.size(); i++) {
		auto ite = hash.find(a[i]);
		if (ite == hash.end()) {
			hash.insert(a[i]);
			solve.push_back(a[i]);
		}
	}

	for (int i = 0; i < b.size(); i++) {
		auto ite = hash.find(b[i]);
		if (ite == hash.end()) {
			hash.insert(b[i]);
			solve.push_back(b[i]);
		}
	}
	
	return solve;
}

vector<int> repetidos(vector<int>& vc) {
	if (vc.size() <= 1) {
		return vc;
	}

	int mid = vc.size() / 2;

	vector<int> izq(vc.begin(), vc.begin() + mid);
	vector<int> der(vc.begin() + mid, vc.end());
	izq = repetidos(izq);
	der = repetidos(der);

	return combinar(izq, der);
} 

int main() {
	vector<int> A = { 4, 2, 9, 4, 2, 3, 9, 1, 7 };

	vector<int> sinDuplicados = repetidos(A);

	cout << "Vector sin duplicados (orden no garantizado):\n";
	for (int x : sinDuplicados)
		cout << x << " ";
	cout << endl;

	return 0;
}
