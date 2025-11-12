#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int pivot(vector<int>& vc, int ini, int fin) {
	int pivtoval = vc[ini];
	int i = ini + 1;
	int j = fin;
	while (true) {
		while (i <= fin && vc[i] <= pivtoval) {
			i++;
		}
		while (j >= ini && vc[j] > pivtoval) {
			j--;
		}

		if (i >= j) break;
		swap(vc[i], vc[j]);
	}
	swap(vc[ini], vc[j]);
	return j;
}

int select(vector<int>& vc, int ini, int fin, int k) {
	if (ini == fin) {
		return vc[ini];
	}

	int pos = pivot(vc, ini, fin);
	int orden = pos - ini + 1;

	if (orden == k) {
		return vc[pos];
	}
	else if (k < orden) {
		return select(vc, ini, pos - 1, k);
	}
	else {
		return select(vc, pos + 1, fin, k - orden);
	}
}


int mediana(vector<int>& vc) {
	int n = vc.size();
	if (n % 2 != 0) {
		int m = (n + 1) / 2;
		int s = select(vc, 0, n - 1, m);
		return s;
	}
	else {
		int k1 = n / 2;
		int k2 = n + 1;
		vector<int> copy = vc;
		int s1 = select(vc, 0, n - 1, k1);
		int s2 = select(copy, 0, n - 1, k2);
		return (s1 + s2) / 2;
	}
}


int main() {
	vector<int> v = { 8, 2, 5, 9, 1, 6, 0};

	cout << "Vector original: ";
	for (int x : v) cout << x << " ";
	cout << endl;

	double med = mediana(v);
	cout << "\nLa mediana es: " << med << endl;

	return 0;
}
