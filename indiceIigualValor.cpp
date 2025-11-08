#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool indiceIigualValor(vector<int>& vc, int ini, int fin) {
	if (ini == fin) {
		return vc[ini] == ini;
	}
	int mid = (ini + fin) / 2;
	if (vc[mid] == mid) {
		return true;
	}
	else if (vc[mid] > mid) {
		return indiceIigualValor(vc, ini, mid - 1);
	}
	else {
		return indiceIigualValor(vc, mid + 1, fin);
	}
}

int main() {
	vector<int> vc = { -3, -1, 1, 4, 5 };
	cout << indiceIigualValor(vc, 0, vc.size() - 1) << endl;

}
