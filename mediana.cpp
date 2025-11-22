#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pivot(vector<int>& vc, int ini, int fin) {
	int pivotval = vc[ini];
	int i = ini + 1;
	int j = fin;

	while (true) {
		while (i <= fin && vc[i] <= pivotval) {
			i++;
		}

		while (j >= ini && vc[j] > pivotval) {
			j--;
		}

		if (i >= j) {
			break;
		}

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

	if (k == orden) {
		return vc[pos];
	}
	else if (k < orden) {
		return select(vc, ini, pos - 1, k);
	}
	else {
		return select(vc, pos + 1, fin, k - orden);
	}

}

int mediana(vector<int> vc) {
	if (vc.empty()) {
		return  -1;
	}
	int n = vc.size();
	if (n % 2 != 0) {
		int k = (n + 1) / 2;
		int sol = select(vc, 0, n - 1, k);
		return sol;
	}
	else {
		vector<int> vctemp = vc;
		int k1 = n / 2;
		int k2 = n + 1;

		int sol1 = select(vc, 0, n - 1, k1);
		int sol2 = select(vctemp, 0, n - 1, k2);
		return (sol1 + sol2) / 2;
	}
}


int main() {
	vector<int> v = { 8, 2, 5, 9, 1, 6, 0 };

	cout << "Vector original: ";
	for (int x : v) cout << x << " ";
	cout << endl;

	double med = mediana(v);
	cout << "\nLa mediana es: " << med << endl;

	return 0;
}
